/**
 * @Author: Michel Andy <andy>
 * @Date:   2017-10-15T22:42:45-04:00
 * @Email:  Andymic12@gmail.com
 * @Project: Multicore Programming
 * @Filename: semaphores.cc
 * @Last modified by:   andy
 * @Last modified time: 2017-10-15T22:48:26-04:00
 */


#include<iostream>
#include<atomic>
#include<thread>
#include<vector>
#include<chrono>
#include<condition_variable>
#include<mutex>
#include<random>
#include<algorithm>
// for random number generation
std::random_device rd;
std::mt19937 gen(rd());

class Semaphore {
private:
  int count;
  bool taken;
  std::mutex mtx;
  std::condition_variable cv;
public:
  Semaphore(int _count=0){
    count = _count;
    taken = false;
  }

  inline void notify(){
    std::unique_lock<std::mutex> lock(mtx);
    count++;
    taken = false;
    cv.notify_all();

  }
  
  inline bool isTaken(){
    return taken;
  }
  
  inline bool testAndGet(){
    
    if(!taken){
      std::unique_lock<std::mutex> lock(mtx);
      count--;
      bool prev = taken;
      taken = true;
      cv.notify_all();
      return prev;
    }

    return taken;
  }

  inline int wait(){
    std::unique_lock<std::mutex> lock(mtx);
    while(count == 0){
      taken = true;
      cv.wait(lock);
    }
    return count--;
  }

  int fetchAdd(int &val){
    std::unique_lock<std::mutex> lock(mtx);
    return val++;
  }

  template<typename T>
  T Set(T &old, T &_new){
    std::unique_lock<std::mutex> lock(mtx);
    T prev = old;
    old = _new;
    return prev;
  }
};

class TASLock {
  private:
    int consensus;
    Semaphore *semaphore;
  public:
    TASLock(int _consensus=1){
      consensus = _consensus;
      semaphore = new Semaphore(consensus);
    }

    inline void lock(){
      int val = semaphore->wait();
      std::cout<<"Semaphore wait: "<<val<<std::endl; 
    }

    inline void unlock(){
      semaphore->notify();
    }
};


class TTASLock {
  private:
    int consensus;
    Semaphore *semaphore;
  public:
    TTASLock(int _consensus=1){
      consensus = _consensus;
      semaphore = new Semaphore(consensus);
    }

    inline void lock(){
      while(semaphore->isTaken()){};
      int val = semaphore->wait();
      std::cout<<"Semaphore wait: "<<val<<std::endl; 
    }

    inline void unlock(){
      semaphore->notify();
    }
};


class BackoffLock {
  private:
    int consensus;
    Semaphore *semaphore;
    int min_delay;
    int max_delay;
    int curr_delay;

    void backoff(){
      std::uniform_int_distribution<> dis(1, curr_delay);
      int delay = dis(gen);
      curr_delay = std::min(max_delay, 2*curr_delay);
      std::this_thread::sleep_for(std::chrono::seconds(delay));
    }
  
  public:
    BackoffLock(int _min_delay, int _max_delay, int _consensus=1){
      consensus = _consensus;
      semaphore = new Semaphore(consensus);
      min_delay = curr_delay = _min_delay;
      max_delay = _max_delay;
    }

    inline void lock(){
      while(true){
        while(semaphore->isTaken()){};
        
        if(!semaphore->testAndGet())
          return;
        else
          backoff();
      }
    }

    inline void unlock(){
      semaphore->notify();
    }
};

class ALock {
  private:
    //Inherently thread_local
    int slot_index=0;
    std::atomic<int> tail{0};
    std::vector<bool> flag;
    int size; 
    Semaphore *semaphore;
    static int id;
  public:
    ALock(int _size, int consensus=1){
      size = _size;
      flag.resize(size);
      flag.at(0) = true;
      semaphore = new Semaphore(consensus);
    }

    void lock(){
      int slot = semaphore->fetchAdd(id) % size;
      slot_index = slot;
      while(!flag[slot]){};
    }

    void unlock(){
        int slot = slot_index;
        flag[slot] = false;
        flag[(slot + 1) % size] = true;
    }
};

struct QNode {
  QNode *prev;
  QNode *next;
  bool locked;
};

class CLHLock {
  private:
    static QNode *tail;
  public:
    CLHLock(){
      tail = new QNode();
      tail->prev = NULL;
      tail->next = NULL;
      tail->locked = false;
    }

    void lock(){
      
    }
};

std::vector<std::thread> makeThreads(){
  int min=1, max=32;
  std::uniform_int_distribution<> dis(min, max);

  int thread_count = dis(gen);

  std::cout<<"Creating "<<thread_count<<" threads...\n";
  std::vector<std::thread> threads;
  for(int i=0; i<thread_count; i++)
    threads.push_back(std::thread());

  return threads;
}

int main(void){
    makeThreads();
    TTASLock tas;
    tas.lock();
    tas.unlock();
    tas.lock();
    return 0;
}

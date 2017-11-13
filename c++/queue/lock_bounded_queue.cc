/**
 * @Author: Michel Andy <andy>
 * @Date:   2017-11-13T14:23:27-05:00
 * @Email:  Andymic12@gmail.com
 * @Project: lock_bounded_queue
 * @Filename: lock_bounded_queue.cc
 * @Last modified by:   andy
 * @Last modified time: 2017-11-13T15:01:21-05:00
 */



#include<iostream>
#include<atomic>
#include<mutex>
#include<condition_variable>
#include<climits>
#include<vector>
#include<random>
#include<algorithm>
#include<thread>

template<typename T>
class LBQueue {
    private:
        int head;
        int tail;
        int capacity;
        T *queue;
        std::atomic<int> size{0};
        std::mutex mtx;
        std::condition_variable cv;
    public:
        LBQueue(int _capacity=0){
            std::cout<<"Creating LBQueue with capacity:"<<_capacity<<std::endl;
            capacity = _capacity;
            head = tail = 0;
            queue = new T[capacity];
        }

        void enqueue(T val){
            std::unique_lock<std::mutex> lock(mtx);
            try{
                std::cout<<"Enqueue op by thread :"<<std::this_thread::get_id()<<std::endl;
                //queue is full
                while(size.load() == capacity){
                    std::cout<<"#\n";
                    cv.wait(lock);
                }

                size.fetch_add(1);
                tail = (size.load()) % capacity;
                queue[tail] = val;
            }catch(std::exception &ex){
                std::cout<<"Error in <enqueue> method: "<<ex.what()<<std::endl;
            }
            cv.notify_all();
        }

        T dequeue(){
            std::unique_lock<std::mutex> lock(mtx);
            try{
                std::cout<<"Dequeue op by thread :"<<std::this_thread::get_id()<<std::endl;
                //queue is empty
                while(size.load() == 0){
                    std::cout<<"#\n";
                    cv.wait(lock);
                }

                queue[head] = INT_MIN;
                head = (head + 1) % capacity;
                size.fetch_sub(1);
            }catch(std::exception &ex){
                std::cout<<"Error in <dequeue> method: "<<ex.what()<<std::endl;
            }
            cv.notify_all();
        }

        ~LBQueue(){
            cv.notify_all();
        }

};

void enqueue(LBQueue<int> &bq){
    bq.enqueue(1);
}

void dequeue(LBQueue<int> &bq){
    bq.dequeue();
}

void testLBQueue(int threads = 10){
    LBQueue<int> bq(20);
    std::vector<std::thread> ths;
    int eq = threads*.5, dq = threads *.5;
    std::random_device rd;
    std::mt19937 g(rd());

    for(int i=0; i<eq; i++)
        ths.push_back(std::thread(enqueue, std::ref(bq)));

    for(int i=0; i<dq; i++)
        ths.push_back(std::thread(dequeue, std::ref(bq)));

    std::clock_t begin = clock();
    //std::shuffle(ths.begin(), ths.end(), g);
    std::random_shuffle(ths.begin(), ths.end());
    for(int i=0; i<threads; i++)
        ths.at(i).join();

    std::clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    std::cout<<""<<elapsed_secs<<","<<threads<<std::endl;
}

int main(void){
    testLBQueue();
    return 0;
}

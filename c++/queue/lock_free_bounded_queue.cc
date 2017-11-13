/**
 * @Author: Michel Andy <andy>
 * @Date:   2017-11-13T14:59:11-05:00
 * @Email:  Andymic12@gmail.com
 * @Project: lock_free_bounded_queue
 * @Filename: lock_free_bounded_queue.cc
 * @Last modified by:   andy
 * @Last modified time: 2017-11-13T15:01:07-05:00
 */



#include<iostream>
#include<atomic>
#include<climits>
#include<vector>
#include<random>
#include<algorithm>
#include<thread>

template<typename T>
class LFBQueue {
    private:
        volatile int capacity;
        std::atomic<int> head, tail;
        std::atomic<bool> isEmpty, isFull;
        std::atomic<int> size{0};
        std::atomic<T *>queue;
    public:
        LFBQueue(int _capacity=0){
            std::cout<<"Creating LFBQueue with capacity:"<<_capacity<<std::endl;
            capacity = _capacity;
            head = tail = 0;
            queue = new T[capacity];
        }

        void enqueue(T val){
            try{
                std::cout<<"Enqueue op by thread :"<<std::this_thread::get_id()<<std::endl;
                //queue is full
                isFull.store(size.load() == capacity ? true: false);

                while(isFull.load()){
                    std::cout<<"#\n";
                }

                size.fetch_add(1);
                tail.store((size.load()) % capacity);
                queue[tail] = val;
            }catch(std::exception &ex){
                std::cout<<"Error in <enqueue> method: "<<ex.what()<<std::endl;
            }
        }

        T dequeue(){
            try{
                std::cout<<"Dequeue op by thread :"<<std::this_thread::get_id()<<std::endl;
                //queue is empty
                isEmpty.store(size.load() == 0 ? true: false);
                while(isEmpty.load()){
                    std::cout<<"#\n";
                }

                queue[head] = INT_MIN;
                head.store((head + 1) % capacity);
                size.fetch_sub(1);
            }catch(std::exception &ex){
                std::cout<<"Error in <dequeue> method: "<<ex.what()<<std::endl;
            }
        }

        ~LFBQueue(){
        }

};

void enqueue(LFBQueue<int> &bq){
    bq.enqueue(1);
}

void dequeue(LFBQueue<int> &bq){
    bq.dequeue();
}

void testLFBQueue(int threads = 10){
    LFBQueue<int> bq(20);
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
    testLFBQueue();
    return 0;
}

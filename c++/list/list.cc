#include <iostream>
#include <stdexcept>
#include <string>
#include "list.h"

template<typename E>
class List : public BaseList<E>{
private:
    int maxSize;
    int listSize;
    int currP;
    E* listArray;

public:
    List(int size=0){
        maxSize = size;
        listSize = currP = 0;
        listArray = new E[maxSize];
    }
    ~List(){
        delete [] listArray;
    }
    
    void clear(){
        delete [] listArray;
        listSize = currP = 0;
        listArray = new E[maxSize];        
    }
    
    void insert(const E& item){
        if(listSize > maxSize)
            std::overflow_error("capacity overflow");
        
        for(int i = listSize; i<currP; i--)
            listArray[i] = listArray[i-1];
        
        listArray[currP] = item;
        listSize++;
    }
    
    void append(const E& item){
        if(listSize > maxSize)
            throw std::overflow_error("capacity overflow");
            
        listArray[listSize++] = item;       
    }
    
    //remove the current element
    E remove(){
        if(currP < 0 && currP >= listSize)
            throw std::underflow_error("no element");
            
        E element = listArray[currP];
        
        for(int i = currP;  i<listSize-1; i++)
            listArray[i] = listArray[i+1];
        
        listSize--;
        return element;
    }
    
    void moveToFront(){
        currP = 0;
    }
    
    void moveToBack(){
        currP = listSize;
    }
    
    void prev(){
        if(currP > 0)
            currP--;
    }
    
    void next(){
        if(currP < listSize)
            currP++;
    }
    
    int length() const {
        return listSize;
    }
    
    int currPos() const {
        return currP;
    }
    
    void moveToPos(int index){
        if(index >= 0 || index<=listSize){
            currP = index;
            return;
        }
        
        throw std::range_error("index out range"); 
    }
    
    const E& getValue() const {
        if(currP < 0 && currP >= listSize)
            throw std::underflow_error("no element");
                    
        return listArray[currP];
    }
    
};

int main(void){
    List<std::string> * test = new List<std::string>(3);
    
    test->append("test1");
    test->append("test2");
    test->append("test3");
    
    for(int i = 0; i< test->length(); i++){
        std::cout<<test->getValue()<<std::endl;
        test->next();
    }
    
    delete test;
    return 0;
}
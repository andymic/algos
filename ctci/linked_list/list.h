#include<iostream>
#include<sstream>

template<class T>
struct Node
{
    Node<T>* next;
    T data;
    Node<T>():next(nullptr)
    {
    }
    
    Node<T>(T _data):next(nullptr), data(_data)
    {
    }
};

template<class T>
class LinkedList
{
    private:
        Node<T>* _head;
        Node<T>* mknode(T t)
        {
            return new Node<T>(t);
        }
    public:
        LinkedList():_head(nullptr)
        {}
        
        Node<T>* head()
        {
            return _head;
        }

        void insert(T data)
        {
            if(_head == nullptr)
            {
                _head = mknode(data);
                return;
            }

            Node<T> *tmp = _head;

            while(tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = mknode(data);
        }
        
        void insert(Node<T> *node)
        {
            if(node == nullptr)
                return;

            if(_head == nullptr)
            {
                _head = node;
                return;
            }

            Node<T> *tmp = _head;

            while(tmp->next != nullptr)
            {
                tmp = tmp->next;
            }
            tmp->next = node; 
        }

        Node<T>* find(T data)
        {
            Node<T> *tmp = _head;

            while(tmp != nullptr)
            {
                if(tmp->data == data)
                    return tmp;

                tmp = tmp->next;
            }

            return nullptr;
        }

        bool remove(T data)
        {
            Node<T> *tmp = _head;
            Node<T> *prev = tmp;
            
            if(_head->data == data)
            {   
                
                tmp = _head->next;
                _head = nullptr;
                delete _head;
                _head = tmp;
                return true;
            }

            while(tmp != nullptr)
            {
                if(tmp->data == data)
                {
                    prev->next = tmp->next;
                    tmp = nullptr;
                    delete tmp;
                    return true;
                }
                prev = tmp;
                tmp = tmp->next;
            }
            return false;
        }

        void print()
        {
            Node<T> *tmp = _head;
            std::stringstream ss;

            while(tmp != nullptr)
            {
                ss<<tmp->data<<"->";   
                tmp = tmp->next; 
            }
            ss<<"null";
            std::cout<<ss.str()<<std::endl;
        }
};

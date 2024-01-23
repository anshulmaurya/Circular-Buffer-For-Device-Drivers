/*
* Class for circular buffer object creation
*/

#include <iostream>

#ifndef BUFFER_H 
#define BUFFER_H

template <class T1>
class circularBuffer{
    private:
    short head, tail;
    T1* __buffer__;
    const char* const bufferName;
    bool isFull;
    short numberOfElement;


    public:
    // constructor or Init Method
    circularBuffer(short numberOfElement,  const char* const nameOfBuffer = "Default Circular Buffer") : 
    bufferName(nameOfBuffer),
    __buffer__(new T1[numberOfElement]),
    numberOfElement(numberOfElement)
    {
        head = tail = 0;
        isFull = false;
    }

    // Distructor
    ~circularBuffer(){
        delete[] __buffer__;
        std::cout<<std::endl<<"Buffer memory deleted"<<std::endl;
    }

    // Other Methods
    void printBufferInfo();
    bool isbufferEmpty();
    bool isbufferFull();
    void write(T1);
    T1 read();

};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


template <class T1>
void circularBuffer<T1>::printBufferInfo()
{
    std::cout<<"Size: "<<sizeof(T1)*numberOfElement<<"\nName: "<<bufferName<<std::endl;
    std::cout<<"Head:"<<head<<std::endl;
    std::cout<<"Tail:"<<tail<<std::endl;
}


template <class T1>
bool circularBuffer<T1>::isbufferEmpty()
{
    if (head == tail && isFull == false){
        return true;
    }
    else{
        return false;
    }
}


template <class T1>
inline bool circularBuffer<T1>::isbufferFull()
{
    if (head+1 == tail){
        isFull = true;
    }
    else{
        isFull = false;
    }
    return isFull;
}


template <class T1>
inline void circularBuffer<T1>::write(T1 data)
{
    __buffer__[head] = data;
    if(head == numberOfElement-1){
        head = 0;
    }
    else{
        head++;
    }
}


template <class T1>
T1 circularBuffer<T1>::read()
{   
    if (tail == numberOfElement)
    {
        if (head == 0){
            tail--;
        }
        else
            tail = 0;
    }
    if(tail == head){
        return __buffer__[tail];
    }
    return __buffer__[tail++];
}


#endif

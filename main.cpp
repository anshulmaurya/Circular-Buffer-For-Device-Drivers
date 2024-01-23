#include <iostream>
#include "buffer.h"


int main(){

    circularBuffer<float>* cBuff = new circularBuffer<float>(3, "Circular Buffer ID: 1");

    cBuff->write(1.1);
    cBuff->write(2.1);
    cBuff->write(3.1);

    std::cout<<cBuff->read()<<std::endl;
    std::cout<<cBuff->read()<<std::endl;
    std::cout<<cBuff->read()<<std::endl;
    std::cout<<cBuff->read()<<std::endl;

    cBuff->printBufferInfo();

    std::cout<<cBuff->isbufferEmpty()<<std::endl;
    std::cout<<cBuff->isbufferFull()<<std::endl;

    return 0;
}
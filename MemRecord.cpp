#include "MemRecord.h"

void* operator new(size_t nSize ,char* fileName ,int lineName){
    if(nSize == 0)//make sure the safe
        nSize = 1;
    void* ptr = malloc(nSize);
    MemRecordMap::getInstance()->insertMap(ptr,fileName,lineName);
    return ptr;
}

void operator delete(void* ptr){
    MemRecordMap::getInstance()->eraseMap(ptr);
    free(ptr);
}


void* operator new[](size_t nSize , char* fileName , int lineName){
    void* ptr = malloc(nSize);
    MemRecordMap::getInstance()->insertMap(ptr,fileName,lineName);
    std::cout<<"call new[]"<<std::endl;
    return ptr;
}

void operator delete[](void* ptr){
    MemRecordMap::getInstance()->eraseMap(ptr);
    free(ptr);
}
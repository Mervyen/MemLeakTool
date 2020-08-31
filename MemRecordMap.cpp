#include "MemRecordMap.h"

MemRecordMap* MemRecordMap::pInstance = nullptr;
mutex MemRecordMap::m_memMutex;
mutex MemRecordMap::m_insertMutex;
mutex MemRecordMap::m_eraseMutex;
MemRecordMap::garbageCollect gc;//when program finished,the destructor of gc will delete pInstance
MemRecordMap* MemRecordMap::getInstance() {//DCL(double check lock)
    if(pInstance == nullptr){//first check
        lock_guard<mutex> guard(m_memMutex);//RAII
        if(pInstance == nullptr)//second check
            pInstance = new MemRecordMap();//c++11 will ensure this new operator atomic
    }
    return pInstance;
}



void MemRecordMap::insertMap(void* ptr,string fileName,int lineNum){
    lock_guard<mutex> insertGuard(m_insertMutex);
    _value ptrDetail;
    ptrDetail.lineNum = lineNum;
    ptrDetail.fileName = fileName;
    m_memRecordMap.insert(std::pair<void*,VALUE>(ptr,ptrDetail));
}

void MemRecordMap::eraseMap(void* ptr) {
    auto search = m_memRecordMap.find(ptr);
    if(search != m_memRecordMap.end()){
        lock_guard<mutex> eraseGuard(m_eraseMutex);
        m_memRecordMap.erase(ptr);
    }
    else
        return;
}
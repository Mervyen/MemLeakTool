#ifndef MEMRECORDMAP_H
#define MEMRECORDMAP_H
#include <iostream>
#include <map>
#include <list>
#include <string>
#include <mutex>

using namespace std;

typedef struct _value{
    int lineNum;
    string fileName;
}VALUE;
class MemRecordMap
{
public:
    void insertMap(void* ptr,string fileName,int lineNum);
    void eraseMap(void* ptr);
    static MemRecordMap* getInstance();

    //gc
    class garbageCollect{
    public:
        ~garbageCollect(){
            if(!MemRecordMap::getInstance()->m_memRecordMap.empty()){
                for(auto it = MemRecordMap::getInstance()->m_memRecordMap.begin();
                    it!=MemRecordMap::getInstance()->m_memRecordMap.end();
                    ++it){//when program finished, cout the mem didnot delete
                   std::cout<<(*it).second.fileName<<std::endl;
                    std::cout<<(*it).second.lineNum<<std::endl;
                }
            }
            if(pInstance){
                delete pInstance;
                std::cout<<"gc call delete"<<std::endl;
            }
        }

    };
    static garbageCollect gc;
private:
    static MemRecordMap *pInstance;//Singleton
    static mutex m_memMutex;
    static mutex m_insertMutex;
    static mutex m_eraseMutex;
    map<void*,_value> m_memRecordMap;
};

#endif

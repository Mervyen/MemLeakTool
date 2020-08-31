#ifndef MEMRECORD_H
#define MEMRECORD_H
#include <string>
#include "MemRecordMap.h"

#define DEBUG_NEW new(__FILE__,__LINE__)

//重载new和delete函数
void* operator new(size_t nsize ,char* fileName ,int lineNum);
void operator delete(void* prt);
//重载new[]和delete[]函数
void* operator new[](size_t nsize ,char* fileName ,int lineNum);
void operator delete[](void* ptr);
#endif
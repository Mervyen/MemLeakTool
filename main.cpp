#include "MemRecord.h"
#include "MemRecordMap.h"
// #if defined (MEM_DEBUG)
// #define new DEBUG_NEW
// #endif
#define new DEBUG_NEW

int main(){
    auto* a = new int(10);
    auto* b = new char('c');
    auto* c = new double(12.3);

    delete a;
    delete b;

    return 1;
}

























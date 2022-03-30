
#ifndef UNTITLED4_O_H
#define UNTITLED4_O_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include "Page.h"

class OS {
private:
    int pageFaultCount = 0;
    std::vector<std::vector<Page>> HDD;
    Page page;
    char BackUpHDD [1024]{};
public:
    void store(int pageNumber, int currentProcessId);
    void FIFO(int pageNumber, int currentProcessId, char RAM[1024]);
    void NRU(int pageNumber, int currentProcessId);
    std::vector<std::vector<Page>> &getHdd() ;
};


#endif //UNTITLED4_O_H

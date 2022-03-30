
#ifndef UNTITLED4_CPU_H
#define UNTITLED4_CPU_H
#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>
#include "Process.h"
#include "Page.h"
#include "MMU.h"
#include "Helper.h"

class CPU {
public:
    CPU() {}

    std::vector<Process *> processes {};
    int currentProcessId = 0;
    MMU mmu;
    static const int RAMSize = 1024;
    char RAM [RAMSize]{};

    void addProcess(Process *Process);
    static int computeProbability() ;
    bool getNextOperation();
    bool read();
    bool write();
    bool changeProcess();
};


#endif //UNTITLED4_CPU_H

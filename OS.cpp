
#include "OS.h"

void OS::store(int pageNumber, int currentProcessId) {
    HDD.at(currentProcessId).at(pageNumber).setPresentBit(true);
    ++pageFaultCount;
    char process = HDD.at(currentProcessId).at(pageNumber).getProcessIdentifier() + 65;
    std::ofstream MyFile("LinearSortedFifoSimulation2.txt",std::ios_base::app);
    MyFile<<"-------------------------------------------------------------"<<std::endl;
    MyFile<<"OS: New page stored... Page "<<pageNumber<<" now belongs to "<<process<<std::endl;
    MyFile<<"OS: Page fault count is now: "<<pageFaultCount<<std::endl;
    MyFile<<"-------------------------------------------------------------"<<std::endl;
    MyFile.close();
}

void OS::FIFO(int pageNumber, int currentProcessId, char RAM [1024]) {
    HDD.at(currentProcessId).at(pageNumber).setPresentBit(true);
    HDD.at((currentProcessId+1)%2).at(pageNumber).setPresentBit(false);
    for(int i=0; i<page.getSize(); i++){
        this->BackUpHDD[i] = RAM[i];
    }
    ++pageFaultCount;

    std::ofstream MyFile("LinearSortedFifoSimulation2.txt",std::ios_base::app);
    MyFile<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
    MyFile<<"OS: Page "<<pageNumber<<" replaced with FIFO "<<std::endl;
    MyFile<<"OS: Page fault count is now: "<<pageFaultCount<<std::endl;
    MyFile<<"||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
    MyFile.close();
}

void OS::NRU(int pageNumber, int currentProcessId) {
    /*
    1. R=0, M=0 (not read, not modified)
    2. R=0, M=1 (not read, but modified)
    3. R=1, M=0 (read, but not modified)
    4. R=1, M=1 (read and modified)
    finally FIFO at the end of the day in this simulation at least... not reality of course!
     */
}

std::vector<std::vector<Page>> &OS::getHdd() {
    return HDD;
}


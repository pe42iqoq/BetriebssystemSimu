
#include "MMU.h"

int MMU::translate(int virtualAddress, std::vector<Process *> &processes, int currentProcessId, char RAM[1024]) {

    auto currentProcess = processes.at(currentProcessId);
    auto pageTable = currentProcess->getPageTable();
    int pageNumber = virtualAddress / page.getSize();
    int offset = virtualAddress % page.getSize();

    //replace pages
    if (pageNumber >= 15) {
        if(pageNumber == 15) {
            return true;
        }else {
            pageNumber = pageNumber % 16;
            os.FIFO(pageNumber, currentProcessId, RAM);
            int pageFrameNumber = os.getHdd().at(currentProcessId).at(pageNumber).getPageFrameNumber();
            int pageFrameAddress = pageFrameNumber * page.getSize();
            int physicalAddress = pageFrameAddress + offset;
            return physicalAddress;
        }
    }

    //add pages
    bool presentBit = os.getHdd().at(currentProcessId).at(pageNumber).isPresentBit();
    if (!presentBit) {
        //looking for present bit in other process
        if (os.getHdd().at((currentProcessId+1)%processes.size()).at(pageNumber).isPresentBit()){
            ++pageNumber;
            currentProcess->setCurrentIndex(pageNumber * page.getSize());
            os.store(pageNumber, currentProcessId);
        } else os.store(pageNumber, currentProcessId);
    }

    int pageFrameNumber = os.getHdd().at(currentProcessId).at(pageNumber).getPageFrameNumber();
    int pageFrameAddress = pageFrameNumber * page.getSize();
    int physicalAddress = pageFrameAddress + offset;
    return physicalAddress;
}

OS &MMU::getOs() {
    return os;
}

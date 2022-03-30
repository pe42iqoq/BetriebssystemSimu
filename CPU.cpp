
#include "CPU.h"

void CPU::addProcess(Process *Process) {

    this->processes.push_back(Process);
    mmu.getOs().getHdd().push_back(Process->getPageTable());

    std::ofstream MyFile("LinearSortedFifoSimulation2.txt",std::ios_base::app);
    MyFile<<std::endl<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<std::endl
             <<std::endl;
    MyFile<<"Process "<<Process->getData()<<" added in HDD..."<<std::endl;
    for (int i = 0; i < Process->getPageTable().size(); i++) {
        char owner = Process->getPageTable().at(i).getProcessIdentifier() + 65;
        bool dirtyBit = Process->getPageTable().at(i).isDirtyBit();
        bool rBit = Process->getPageTable().at(i).isReferencedBit();
        bool pBit = Process->getPageTable().at(i).isPresentBit();
        MyFile <<"Page no:"<<i<<" Page frame:"<<Process->getPageTable().at(i).getPageFrameNumber()
                  <<" Present Bit:"<<pBit<<" R-Bit:"<<rBit<<" Dirty Bit:"<<dirtyBit<<" Owner: "<<owner
                  <<std::endl;
    }
    MyFile << std::endl << "::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::" << std::endl;
    MyFile.close();
};

int CPU::computeProbability() {
    int randomNumber = rand();
    int probability = randomNumber % 100;
    return probability;
}

bool CPU::getNextOperation() {
    int probability = computeProbability();
    switch (probability) {
        case 0 ... 50: {
            return read();
        }
        case 51 ... 80: {
            return write();
        }
        case 81 ... 99: {
            changeProcess();
            return true;
        }
        default:
            return false;
    }
}

bool CPU::read() {
    std::ofstream MyFile("LinearSortedFifoSimulation2.txt",std::ios_base::app);
    auto currentProcess = this->processes.at(this->currentProcessId);
    int virtualAddress = currentProcess->getCurrentIndex();
    if (virtualAddress == -1 || virtualAddress % 63 == 0) return true;
    int physicalAddress = mmu.translate(virtualAddress,this->processes, this->currentProcessId, this->RAM);
    Page readPage = mmu.getOs().getHdd().at(currentProcessId).at(physicalAddress / 64);
    int pageFrame = readPage.getPageFrameNumber();

    char readAddress = this->RAM[physicalAddress];
    readPage.setReferencedBit(true);
    MyFile << "CPU (Referenced bit set): Read " << readAddress << " in page frame " << pageFrame
              << " from address " << physicalAddress << " in RAM " << std::endl;
    MyFile.close();
    return true;
}

bool CPU::write() {
    std::ofstream MyFile("LinearSortedFifoSimulation2.txt",std::ios_base::app);
    auto currentProcess = this->processes.at(this->currentProcessId);
    int virtualAddress = currentProcess->getNextAddressToWriteTo();
    int physicalAddress = mmu.translate(virtualAddress,this->processes, this->currentProcessId, this->RAM);
    Page writtenPage = mmu.getOs().getHdd().at(currentProcessId).at(physicalAddress / 64);
    int pageFrame = writtenPage.getPageFrameNumber();

    this->RAM[physicalAddress] = currentProcess->getData();
    writtenPage.setDirtyBit(true);
    MyFile << "CPU (Dirty bit set): Write " << currentProcess->getData()
              << " in page frame " << pageFrame << " to address " << physicalAddress
              << " in RAM " << std::endl;
    MyFile.close();
    return true;
}

bool CPU::changeProcess() {
    std::ofstream MyFile("LinearSortedFifoSimulation2.txt",std::ios_base::app);
    this->currentProcessId = (this->currentProcessId + 1) % (int) this->processes.size();
    if (currentProcessId == 0) {
        MyFile << "CPU: Change Process to A" << std::endl;
        MyFile.close();
        return true;
    }
    if (currentProcessId == 1) {
        MyFile << "CPU: Change Process to B" << std::endl;
        MyFile.close();
        return true;
    }
    return false;
}


#ifndef UNTITLED4_PROCESS_H
#define UNTITLED4_PROCESS_H

#include "Page.h"
#include "Helper.h"

class Process {
private:
    char data {};
    int currentIndex {};
    using pageFrameNumber = int;
    std::vector<Page> pageTable {};
public:
    explicit Process(char i) {
        this->data = i;
        int processId = i - 65;
        Helper helper;
        std::vector<int> bubbleSortedAddresses = helper.bubbleSortedAddressGenerator();
        std::vector<int> randomAddresses = helper.randomAddressGenerator();
        int numberOfPages = helper.calculateNumberOfPages();
        for (int i = 0; i < numberOfPages; i++) {
            Page page;
            pageFrameNumber pageFrameIndex = bubbleSortedAddresses.at(i);
            page.setPageFrameNumber(pageFrameIndex);
            page.setProcessIdentifier(processId);
            pageTable.push_back(page);
        }
    };

    char getData() {
        return this->data;
    }

    void setCurrentIndex(int currentIndex) {
        Process::currentIndex = currentIndex;
    }

    int getCurrentIndex() const {
        return currentIndex-1;
    }

    int getNextAddressToWriteTo() {
        return currentIndex++;
    }

    std::vector<Page> &getPageTable() {
        return pageTable;
    }
};


#endif //UNTITLED4_PROCESS_H

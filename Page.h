
#ifndef UNTITLED4_PAGE_H
#define UNTITLED4_PAGE_H

class Page {
private:
    int pageFrameNumber {};
    int size = 64;
    bool presentBit = false; //no page frame for page by default
    bool referencedBit = false; //nor written or read
    bool dirtyBit = false; //not written
    int processIdentifier = 0;
public:

    Page(){}

    int getPageFrameNumber() const {
        return pageFrameNumber;
    }

    void setPageFrameNumber(int pageFrameNumber) {
        Page::pageFrameNumber = pageFrameNumber;
    }

    const int getSize() {
        return size;
    }

    bool isPresentBit() const {
        return presentBit;
    }

    void setPresentBit(bool presentBit) {
        Page::presentBit = presentBit;
    }

    bool isReferencedBit() const {
        return referencedBit;
    }

    void setReferencedBit(bool referencedBit) {
        Page::referencedBit = referencedBit;
    }

    bool isDirtyBit() const {
        return dirtyBit;
    }

    void setDirtyBit(bool dirtyBit) {
        Page::dirtyBit = dirtyBit;
    }

    int getProcessIdentifier() const {
        return processIdentifier;
    }

    void setProcessIdentifier(int processIdentifier) {
        Page::processIdentifier = processIdentifier;
    }

};


#endif //UNTITLED4_PAGE_H

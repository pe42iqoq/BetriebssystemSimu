
#ifndef UNTITLED4_MMU_H
#define UNTITLED4_MMU_H
#include "OS.h"
#include "Helper.h"
#include "Page.h"
#include "Process.h"
#include <vector>

class MMU {
private:
    Page page;
    OS os;
public:
    int translate(int virtualAddress, std::vector<Process *> &processes, int currentProcessID, char RAM[1024]);
    OS &getOs();
};


#endif //UNTITLED4_MMU_H

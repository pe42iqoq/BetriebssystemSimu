#include <iostream>
#include <unistd.h>
#include "CPU.h"

int main() {

    CPU cpu;
    auto *processA = new Process('A');
    auto *processB = new Process('B');
    cpu.addProcess(processA);
    cpu.addProcess(processB);
    bool cpuRunning = true;

    while (cpuRunning) {
        if (!cpu.getNextOperation()) {
            std::cout << "Critical error with probability" << std::endl;
            return 1;
        }
        sleep(0);
    }
    return 0;
}

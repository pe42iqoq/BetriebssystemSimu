
#ifndef UNTITLED4_HELPER_H
#define UNTITLED4_HELPER_H

#include <vector>

class Helper {
public:
    Helper(){}
    static int calculateNumberOfPages();
    static std::vector<int> bubbleSortedAddressGenerator();
    std::vector<int> randomAddressGenerator();
    template<typename ForwardIterator>
    ForwardIterator remove_duplicates(ForwardIterator first, ForwardIterator last);
};


#endif //UNTITLED4_HELPER_H

// Blood matching header file
#ifndef MATCHING_H
#define MATCHING_H
#include <vector>

class BloodMatcher {
public:
    void matchBlood(const std::vector<int>& donors, const std::vector<int>& recipients);
};

#endif // MATCHING_H

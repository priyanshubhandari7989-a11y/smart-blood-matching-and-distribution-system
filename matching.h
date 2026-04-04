#ifndef MATCHING_H
#define MATCHING_H

#include <string>
#include <vector>
using namespace std;

struct Donor {
    string name;
    string bloodGroup;
    int location;
    bool available;
};

struct Patient {
    string name;
    string bloodRequired;
    int location;
    int urgency;
};

bool isCompatible(string donor, string receiver);
void findMatches(vector<Donor>& donors, Patient& patient);

#endif
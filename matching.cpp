// Implementation of Blood Matching Engine
#include <iostream>
#include <vector>
#include <queue>
#include "graph.h"

using namespace std;

class BloodMatcher {
public:
    void matchBlood(const vector<int>& donors, const vector<int>& recipients);
};

void BloodMatcher::matchBlood(const vector<int>& donors, const vector<int>& recipients) {
    priority_queue<int, vector<int>, greater<int>> pq;
    // Implement greedy matching algorithm
    for (int donor : donors) {
        pq.push(donor);
    }
    cout << "Matched blood types:\n";
    while (!pq.empty()) {
        int donor = pq.top();
        pq.pop();
        cout << donor << endl;
    }
}

#ifndef ANALYTICS_H
#define ANALYTICS_H

#include <iostream>
using namespace std;

class ComplexityAnalyzer {
public:

    static void printReport() {
        cout << "\n--- COMPLEXITY REPORT ---\n";

        cout << "Patient Module: O(1)\n";
        cout << "Donor Search (Hash): O(1)\n";
        cout << "Matching (Dijkstra): O((V+E) log V)\n";
        cout << "Greedy Selection: O(n log n)\n";
    }

    static void printConcepts() {
        cout << "\n--- DAA CONCEPTS USED ---\n";

        cout << "1. Hash Table (Fast Search)\n";
        cout << "2. Graph (Locations)\n";
        cout << "3. Dijkstra Algorithm\n";
        cout << "4. Priority Queue\n";
        cout << "5. Greedy Method\n";
    }
};

#endif
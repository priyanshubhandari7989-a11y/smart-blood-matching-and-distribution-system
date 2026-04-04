#include <iostream>
#include "matching.h"
#include "graph.h"
using namespace std;

// Blood compatibility
bool isCompatible(string donor, string receiver) {
    if (receiver == "O-") return donor == "O-";
    if (receiver == "O+") return donor == "O-" || donor == "O+";
    if (receiver == "A+") return donor == "A+" || donor == "A-" || donor == "O+" || donor == "O-";
    if (receiver == "B+") return donor == "B+" || donor == "B-" || donor == "O+" || donor == "O-";
    if (receiver == "AB+") return true;
    if (receiver == "A-") return donor == "A-" || donor == "O-";
    if (receiver == "B-") return donor == "B-" || donor == "O-";
    if (receiver == "AB-") return donor == "A-" || donor == "B-" || donor == "AB-" || donor == "O-";
    return false;
}

// Matching logic
void findMatches(vector<Donor>& donors, Patient& patient) {

    // Create graph (5 locations example)
    Graph g(5);

    g.addEdge(0,1,10);
    g.addEdge(0,2,20);
    g.addEdge(1,3,15);
    g.addEdge(2,4,30);

    // Get shortest distances from patient location
    vector<int> dist = g.dijkstra(patient.location);

    cout << "\n--- Matching Donors ---\n";

    for(auto &d : donors) {
        if(d.available && isCompatible(d.bloodGroup, patient.bloodRequired)) {

            cout << "Donor: " << d.name
                 << " | Blood: " << d.bloodGroup
                 << " | Distance: " << dist[d.location]
                 << endl;
        }
    }
}
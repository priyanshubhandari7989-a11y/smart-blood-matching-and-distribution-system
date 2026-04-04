#ifndef BLOODBANK_H
#define BLOODBANK_H

#include <bits/stdc++.h>
#include "donor.h"
using namespace std;

class BloodBank {
private:
    unordered_map<int, DonorRecord> donorsById;
    unordered_map<string, vector<int>> donorsByBlood;
    unordered_map<int, vector<int>> donorsByLocation;

    int donorIdCounter = 1;

public:

    // Register donor
    int registerDonor(string name, string bloodGroup, int age,
                      string email, string phone, int location) {

        int id = donorIdCounter++;

        DonorRecord donor(id, name, bloodGroup, age, email, phone, location, true, 100);

        donorsById[id] = donor;
        donorsByBlood[bloodGroup].push_back(id);
        donorsByLocation[location].push_back(id);

        cout << "✓ Donor registered: " << name << " (ID: " << id << ")\n";
        return id;
    }

    // Search by blood group
    vector<DonorRecord> searchDonorsByBlood(string bloodGroup) {
        vector<DonorRecord> result;

        if (donorsByBlood.find(bloodGroup) != donorsByBlood.end()) {
            for (int id : donorsByBlood[bloodGroup]) {
                if (donorsById[id].available) {
                    result.push_back(donorsById[id]);
                }
            }
        }
        return result;
    }

    // Search by location
    vector<DonorRecord> searchDonorsByLocation(int location) {
        vector<DonorRecord> result;

        if (donorsByLocation.find(location) != donorsByLocation.end()) {
            for (int id : donorsByLocation[location]) {
                if (donorsById[id].available) {
                    result.push_back(donorsById[id]);
                }
            }
        }
        return result;
    }

    // Update availability
    void updateDonorAvailability(int id, bool available, int quantity = 0) {
        if (donorsById.find(id) == donorsById.end()) {
            cout << "Donor not found!\n";
            return;
        }

        donorsById[id].available = available;

        if (quantity > 0) {
            donorsById[id].quantity = quantity;
        }

        cout << "✓ Updated donor " << id << "\n";
    }

    // Display all donors
    void displayAllDonors() {
        cout << "\n--- ALL DONORS ---\n";

        for (auto &d : donorsById) {
            cout << "ID: " << d.second.id
                 << " | Name: " << d.second.name
                 << " | Blood: " << d.second.bloodGroup
                 << " | Location: " << d.second.location
                 << " | Available: " << (d.second.available ? "Yes" : "No")
                 << endl;
        }
    }

    // Display inventory
    void displayInventory() {
        map<string, int> inventory;

        for (auto &d : donorsById) {
            if (d.second.available) {
                inventory[d.second.bloodGroup] += d.second.quantity;
            }
        }

        cout << "\n--- BLOOD INVENTORY ---\n";

        for (auto &i : inventory) {
            cout << i.first << " : " << i.second << " units\n";
        }
    }
};

#endif
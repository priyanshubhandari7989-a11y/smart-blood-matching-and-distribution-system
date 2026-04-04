#ifndef DONOR_H
#define DONOR_H

#include <string>
#include <ctime>
using namespace std;

// Donor structure
struct DonorRecord {
    int id;
    string name;
    string bloodGroup;
    int age;
    string email;
    string phone;
    int location;
    bool available;
    int quantity;
    time_t lastDonation;

    DonorRecord() {}

    DonorRecord(int id, string name, string bg, int age, string email,
                string phone, int loc, bool avail, int qty) {
        this->id = id;
        this->name = name;
        this->bloodGroup = bg;
        this->age = age;
        this->email = email;
        this->phone = phone;
        this->location = loc;
        this->available = avail;
        this->quantity = qty;
        this->lastDonation = time(0);
    }
};

#endif
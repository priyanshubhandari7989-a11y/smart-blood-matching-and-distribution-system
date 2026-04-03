#ifndef BLOOD_BANK_H
#define BLOOD_BANK_H

struct Patient {
    int id;
    char name[100];
    char bloodType[3];
};

struct Donor {
    int id;
    char name[100];
    char bloodType[3];
    bool isAvailable;
};

void registerPatient(Patient patient);
void registerDonor(Donor donor);
void matchDonor(Patient patient);

#endif // BLOOD_BANK_H

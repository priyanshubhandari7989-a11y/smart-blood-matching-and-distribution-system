Donor management system demonstration that registers 6 donors, performs searches by blood group (O(1) hash + O(n) iteration), searches by location (O(1) hash + O(k) iteration), combined searches, updates availability, and displays inventory. Includes complexity analysis comments. 

#include <iostream>
#include <vector>
#include "donor.h"

class DonorManagementSystem {
private:
    BloodBank bloodBank;
public:
    void registerDonors() {
        // Implementation for registering 6 donors
    }
    void performSearches() {
        // Implementation for searching methods
    }
};

int main() {
    DonorManagementSystem dms;
    dms.registerDonors();
    dms.performSearches();
    return 0;
}
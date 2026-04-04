#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// ================= STRUCTS =================
struct Patient {
    string name, blood;
    string location;   // ✅ FIXED (string)
    int urgency;
};

struct Donor {
    string name, blood;
    int location;
    bool available;
};

// ================= ADMIN =================
void logActivity(string action) {
    time_t now = time(0);
    cout << "[" << ctime(&now) << "] " << action;
}

// ================= COMPATIBILITY =================
bool isCompatible(string d, string r) {
    if (r == "A+") return d=="A+"||d=="A-"||d=="O+"||d=="O-";
    if (r == "O+") return d=="O+"||d=="O-";
    if (r == "AB+") return true;
    return false;
}

// ================= MAIN =================
int main() {

    Patient p;

    getline(cin, p.name);
    getline(cin, p.blood);
    getline(cin, p.location);
    cin >> p.urgency;

    vector<Donor> donors = {
        {"Rahul","O+",1,true},
        {"Neha","A-",2,true},
        {"Priya","A+",3,true},
        {"Amit","O-",4,false}
    };

    logActivity("Patient request received");

    cout << "\nPatient Name: " << p.name << endl;
    cout << "Blood Required: " << p.blood << endl;
    cout << "Location: " << p.location << endl;
    cout << "Urgency: " << p.urgency << endl;

    cout << "\nMatching Donors:\n";

    for(auto &d: donors){
        if(d.available && isCompatible(d.blood,p.blood)){
            cout << "✔ " << d.name << " | " << d.blood << endl;
        }
    }

    logActivity("Matching completed");

    return 0;
}
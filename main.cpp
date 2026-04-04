#include <iostream>
#include "admin.cpp"
using namespace std;

int main() {

    AdminDashboard admin;

    // Log some activities
    admin.logActivity("PATIENT_REQUEST", "A+ blood needed", "SUCCESS");
    admin.logActivity("MATCHING", "Found 2 donors", "SUCCESS");
    admin.logActivity("ALLOCATION", "Assigned donor Rahul", "SUCCESS");

    // Display logs
    admin.displayLogs();

    // Show stats (example values)
    admin.showStats(5, 3);

    // Generate report
    admin.generateReport();

    return 0;
}
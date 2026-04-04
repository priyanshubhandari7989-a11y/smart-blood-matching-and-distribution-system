#include <iostream>
#include <vector>
#include "admin.h"
#include "analytics.h"
using namespace std;

class AdminDashboard {
private:
    vector<ActivityLog> logs;

public:

    // Log activity
    void logActivity(string action, string details, string status) {
        ActivityLog log(action, details, status);
        logs.push_back(log);
    }

    // Display logs
    void displayLogs() {
        cout << "\n--- SYSTEM LOGS ---\n";

        if (logs.empty()) {
            cout << "No logs available\n";
            return;
        }

        for (int i = 0; i < logs.size(); i++) {
            cout << "Log " << i+1 << ":\n";
            cout << "Action: " << logs[i].action << endl;
            cout << "Details: " << logs[i].details << endl;
            cout << "Status: " << logs[i].status << endl;
            cout << "----------------------\n";
        }
    }

    // Simple statistics
    void showStats(int totalDonors, int availableDonors) {
        cout << "\n--- SYSTEM STATISTICS ---\n";

        cout << "Total Donors: " << totalDonors << endl;
        cout << "Available Donors: " << availableDonors << endl;

        if (totalDonors > 0) {
            cout << "Availability Rate: "
                 << (availableDonors * 100.0 / totalDonors) << "%\n";
        }
    }

    // Generate report
    void generateReport() {
        cout << "\n--- SYSTEM REPORT ---\n";

        cout << "Blood Donation Management System\n";
        cout << "Modules:\n";
        cout << "1. Patient Module\n";
        cout << "2. Donor Module\n";
        cout << "3. Matching Module\n";
        cout << "4. Admin Module\n";

        ComplexityAnalyzer::printReport();
        ComplexityAnalyzer::printConcepts();
    }
};
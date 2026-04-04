#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include <vector>
#include <ctime>
using namespace std;

// Activity Log Structure
struct ActivityLog {
    time_t timestamp;
    string action;
    string details;
    string status;

    ActivityLog(string action, string details, string status) {
        this->action = action;
        this->details = details;
        this->status = status;
        this->timestamp = time(0);
    }
};

#endif
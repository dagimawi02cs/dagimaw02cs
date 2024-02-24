// manager.h
#ifndef MANAGER_H
#define MANAGER_H

#include "Node.hpp"
#include "Room.hpp"
#include "Customer.hpp"
#include <string>
using namespace std;

class Manager {
private:
    string password = "dagi123";

public:
    Node* roomsHead;
    Node* customersHead;
    Manager();
    bool authenticateManager();
    void checkIn();
    bool isAvailableRoom(int level, const string& roomType);
    void getAvailableRoom();
    void searchCustomer();
    void checkOut();
    void guestSummaryReport();
    void addRoom();
    void displayManagerMenu();
};

#endif // MANAGER_H

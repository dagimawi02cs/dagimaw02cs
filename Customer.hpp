// customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "manager.hpp"
#include <list>
#include <string>
#include "Booking.hpp"
#include "Node.hpp"
using namespace std;
class Manager;
class Customer : public Node {
private:
    string name;
    string address;
    string date;
    string paymentMethod;
    int ID;
    list<Booking> bookingsList;

public:
    Customer();
    Customer(const string& name, const string& address, const string& date, const string& paymentMethod, int ID);
    void addCustomer(Manager& manager);
    void addBooking(Manager& manager);
    void updateBooking();
    void removeBooking();
    void displayCustomerMenu(Manager& manager);
    int getId()const;
    string getName() const;
    string getaddress()const;
    string paymentmethod() const;
};

#endif // CUSTOMER_H



// customer.cpp
#include "customer.hpp"
#include "manager.hpp"
#include <iostream>
#include "Node.hpp"
using namespace std;
class Manager;
Customer::Customer() : Node() {}

Customer::Customer(const string& name, const string& address, const string& date, const string& paymentMethod, int ID)
{
    this->name=name;
    this->address=address;
    this->date=date;
    this->paymentMethod=paymentMethod;
    this->ID=ID;
    next=NULL;
}

void Customer::addCustomer(Manager& manager) {
     // Access customersHead through the Manager class
    if (manager.customersHead == NULL)
    {
        manager.customersHead = this;
    }
    else
    {
        // Traverse the list and add this customer to the end
        Node* currentNode = manager.customersHead;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = new Node();
        currentNode->next->data = this;
        cout<<"Coustomer added successfully";// Store the pointer to the Customer object
    }
}

void Customer::addBooking(Manager& manager) {
   int duration;
    cout << "Enter booking details:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Address only city: ";
    cin >> address;
    cout << "Date like this format(D/M/Y): ";
    cin >> date;
    cout << "Payment Method: ";
    cin >> paymentMethod;
    cout << "ID: ";
    cin >> ID;
    cout << "For how many days do you stay: ";
    cin >> duration;
    int level;
    string roomType;
    cout << "Enter desired room level only(1,2,3): ";
    cin >> level;
    cout << "Enter desired room type(family or single): ";
    cin >> roomType;

    if (!manager.isAvailableRoom(level, roomType)) {
        cout << "No available rooms of type " << roomType << " at level " << level << ".\n";
        return;
    }

    // If there are available rooms, proceed with booking
    Booking newBooking(ID, date, duration);
    bookingsList.push_back(newBooking);
    cout << "Successfully booked! ";
}

void Customer::updateBooking() {
    int bookingIDToUpdate;
    cout << "Enter the booking ID to update: ";
    cin >> bookingIDToUpdate;

    // Find the booking with the given ID
     std::list<Booking>::iterator it = bookingsList.begin();
    while (it != bookingsList.end())
    {
        if (it->getBookingID() == bookingIDToUpdate)
        {
            int duration;
            string date;

            cout << "Enter new booking details:\n";
            cout << "Name: ";
            cin >> name;
            cout << "Address only city: ";
            cin>> address;
            cout << "Date like this format(D/M/Y): ";
            cin >> date;
            cout << "Payment Method: ";
            cin >> paymentMethod;
            cout << "ID: ";
            cin >> ID;
            cout << "For how many days do you stay: ";
            cin >> duration;

            // Update the existing booking using member functions
            it->setBookingDate(date);
            it->setDuration(duration);

            cout << "Booking with ID " << bookingIDToUpdate << " updated successfully." << endl;
            return;
        }
        ++it;
    }
    cout << "Booking with ID " << bookingIDToUpdate << " not found." << endl;
}

void Customer::removeBooking() {
   int bookingIDToRemove;
    cout << "Enter the booking ID to remove: ";
    cin >> bookingIDToRemove;

    std::list<Booking>::iterator it = bookingsList.begin();
    while (it != bookingsList.end())
    {
        if (it->getBookingID() == bookingIDToRemove)
        {
            it = bookingsList.erase(it);
            cout << "Booking with ID " << bookingIDToRemove << " removed successfully." << endl;
            return;
        }
        else
        {
            ++it;
        }
    }
    cout << "Booking with ID " << bookingIDToRemove << " not found." << endl;
}

void Customer::displayCustomerMenu(Manager& manager) {
   system("cls");
    int choice;
    cout<< "WELCOME TO OUR HOTEL!\n";
    do
    {
        cout << "\nCustomer Menu:\n1. Booking\n2. Update Booking\n3. Remove Booking\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBooking(manager);
            break;
        case 2:
            updateBooking();
            break;
        case 3:
            removeBooking();
            break;
        case 4:
            cout << "Exiting customer menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 4);
    system("cls");
}

int Customer::getId()const {
    return ID;
}

string Customer::getName() const {
    return name;
}

string Customer::getaddress() const {
    return address;
}

string Customer::paymentmethod() const {
    return paymentMethod;
}

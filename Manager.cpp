// manager.cpp
#include "manager.hpp"
#include "customer.hpp"
#include <iostream>
using namespace std;

Manager::Manager() : roomsHead(NULL), customersHead(NULL) {}

bool Manager::authenticateManager() {
    string inputPassword;
    cout << "Enter Manager Password: ";
    cin >> inputPassword;
    return inputPassword == password;
}

void Manager::checkIn() {
  int customerID;
    int roomNumber;

    cout << "Enter customer ID: ";
    cin >> customerID;
    cout << "Enter room number: ";
    cin >> roomNumber;
    Customer* currentCustomer = static_cast<Customer*>(customersHead);
    while (currentCustomer != NULL)
    {
        if (currentCustomer->getId() == customerID)
        {
            Room* currentRoom = static_cast<Room*>(roomsHead);
            while (currentRoom != NULL)
            {
                if (currentRoom->roomNo == roomNumber)
                {
                    // Room found, check if it's available
                    if (currentRoom->state == "Available")
                    {
                        // Room is available, assign it to the customer
                        currentRoom->state = "Occupied";
                        cout << "Customer checked in successfully to room number " << roomNumber << "." << endl;
                        return;
                    }
                    else
                    {
                        cout << "Room number " << roomNumber << " is not available." << endl;
                        return;
                    }
                }
                currentRoom = static_cast<Room*>(currentRoom->next);
            }
            cout << "Room number " << roomNumber << " not found." << endl;
            return;
        }
        currentCustomer = static_cast<Customer*>(currentCustomer->next);
    }
    cout << "Customer with ID " << customerID << " not found." << endl;
}

bool Manager::isAvailableRoom(int level, const string& roomType) {
    Room* currentRoom = static_cast<Room*>(roomsHead);
    while (currentRoom != NULL)
    {
        if (currentRoom->state == "Available" && currentRoom->level == level && currentRoom->roomType == roomType)
        {
            return true;
        }
        currentRoom = static_cast<Room*>(currentRoom->next);
    }
    return false;
}

void Manager::getAvailableRoom() {
    if (roomsHead == NULL)
    {
        cout << "No available rooms.\n";
        return;
    }

    cout << "Available Rooms:\n";
    Room* currentRoom = static_cast<Room*>(roomsHead);
    while (currentRoom != NULL)
    {
        if (currentRoom->state == "Available")
        {
            cout << "Room No: " << currentRoom->getRoomNo() << endl;
            cout << "Room Type(family or single): " << currentRoom->roomType << endl;
            cout << "State: " << currentRoom->state << endl;
            cout << "Level: " << currentRoom->level << endl;
            cout << "Rent: " << currentRoom->rent << endl;
            cout << endl;
        }
        currentRoom = static_cast<Room*>(currentRoom->next);
    }
}

void Manager::searchCustomer() {
  
    system("cls");
    string name;
    cout << "Enter customer name: ";
    cin>>name;

    Customer* currentCustomer = static_cast<Customer*>(customersHead);
    while (currentCustomer != NULL)
    {
        if (currentCustomer->getName() == name)
        {
            cout << "Customer Found: " << currentCustomer->getName() << endl;
            cout <<"Customer address:"<<currentCustomer->getaddress()<<endl;
            cout <<"Customer Id :"<<currentCustomer->getId()<<endl;
            cout <<"Customer paymentMethod:"<<currentCustomer->paymentmethod()<<endl;
            return;
        }
        currentCustomer = static_cast<Customer*>(currentCustomer->next);
    }
    cout << "Customer not found." << endl;
    cout << "Press any key to continue" << endl;
    cin.ignore();
    cin.get();
    system("cls");
}

void Manager::checkOut() {
   int roomNumber;
    cout << "Enter room number for check-out: ";
    cin >> roomNumber;
    // Find the room in the linked list of rooms
    Room* currentRoom = static_cast<Room*>(roomsHead);
    while (currentRoom != NULL)
    {
        if (currentRoom->roomNo == roomNumber)
        {
            // Room found
            if (currentRoom->state == "Occupied")
            {
                // Update room state to Available
                currentRoom->state = "Available";
                cout << "Check-out completed for room number " << roomNumber << "." << endl;
                // Additional actions such as generating a bill, updating customer records, etc., can be performed here
                return;
            }
            else
            {
                // Room is not occupied, cannot check-out
                cout << "Room number " << roomNumber << " is not occupied. No check-out is possible." << endl;
                return;
            }
        }
        currentRoom = static_cast<Room*>(currentRoom->next);
    }
    // Room not found
    cout << "Room number " << roomNumber << " not found." << endl;
}

void Manager::guestSummaryReport() {
    
  cout << "Guest Summary Report:\n";
    Room* currentRoom = static_cast<Room*>(roomsHead);
    while (currentRoom != NULL)
    {
        if (currentRoom->state == "Occupied")
        {
            cout << "Room No: " << currentRoom->roomNo << endl;
            Customer* currentCustomer = static_cast<Customer*>(customersHead);
            while (currentCustomer != NULL)
            {
                if (currentCustomer->getId()== currentRoom->roomNo)
                {
                    cout << "Customer Name: " << currentCustomer->getName() << endl;
                    cout <<"Customer address:"<<currentCustomer->getaddress()<<endl;
                    cout <<"Customer Id :"<<currentCustomer->getId()<<endl;
                    cout <<"Customer paymentMethod:"<<currentCustomer->paymentmethod()<<endl;
                    break;
                }
                currentCustomer = static_cast<Customer*>(currentCustomer->next);
            }
        }
        currentRoom = static_cast<Room*>(currentRoom->next);
    }
}

void Manager::addRoom() {
   int roomNo;
    string roomType;
    int level;
    int rent;

    cout << "Enter room number: ";
    cin >> roomNo;
    cout << "Enter room type: ";
    cin >> roomType;
    cout << "Enter level: ";
    cin >> level;
    cout << "Enter rent: ";
    cin >> rent;

    // Create a new Room object
    Room* newRoom = new Room();
    newRoom->roomNo = roomNo;
    newRoom->roomType = roomType;
    newRoom->level = level;
    newRoom->rent = rent;
    newRoom->state = "Available"; // By default, the room is available

    // Add the new room to the linked list
    if (roomsHead == NULL)
    {
        roomsHead = newRoom;
    }
    else
    {
        // Find the last room in the linked list
        Room* currentRoom = static_cast<Room*>(roomsHead);
        while (currentRoom->next != NULL)
        {
            currentRoom = static_cast<Room*>(currentRoom->next);
        }
        // Assign the new room to the next pointer of the last room
        currentRoom->next = newRoom;
    }
    cout << "Room added successfully." << endl;
}

void Manager::displayManagerMenu() {
     system("cls");
    if (!authenticateManager())
    {
        cout << "Authentication failed. Exiting Manager Menu.\n";
        return;
    }
    system("cls");
    int choice;
    do
    {
        cout<< "                                HOTEL MANAGMENT SYSTEM!\n"<<endl
            << "\nManager Menu:"<<endl
            <<"1. Check-in"<<endl
            <<"2. Get Available Room"<<endl
            <<"3. Search Customer"<<endl
            <<"4. Check-out"<<endl
            <<"5. Guest Summary Report"<<endl
            <<"6. Add Room"<<endl
            <<"7. Exit"<<endl
            <<"Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            checkIn();
            break;
        case 2:
            getAvailableRoom();
            break;
        case 3:
            searchCustomer();
            break;
        case 4:
            checkOut();
            break;
        case 5:
            guestSummaryReport();
            break;
        case 6:
            addRoom();
            break;
        case 7:
            cout << "Exiting manager menu.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    while (choice != 7);
    system("cls");
}

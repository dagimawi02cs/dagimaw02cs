// main.cpp
#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include "manager.hpp"
#include "customer.hpp"

using namespace std;

int main() {
    system("cls");
    Manager manager;
    Customer customer;
    cout<< "WELCOME TO OUR HOTEL!\n";

    // Main Menu
    int mainChoice;
    do
    {
        cout<< "                                     HOTEL MANAGMENT SYSTEM!\n";
        cout << "\nMain Menu:\n1. Manager Menu\n2. Customer Menu\n3. Exit\nEnter your choice: ";
        cin >> mainChoice;

        switch (mainChoice)
        {
        case 1:
            manager.displayManagerMenu();
            break;
        case 2:
            customer.addCustomer(manager);
            customer.displayCustomerMenu(manager);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
    while (mainChoice != 3);

    return 0;
}

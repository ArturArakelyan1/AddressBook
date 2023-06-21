#include <iostream>
#include <fstream>
#include "AddressBook.h"

void AddressBook::viewAllContacts() const {
    for(int i = 0; i < contacts.size(); ++i) {
        std::cout << "Contact" << i + 1 << " {" << std::endl;
        std::cout <<  contacts[i] << '}' << std::endl;
    }
}

void AddressBook::removeContact() {
    std::string phoneNumber;
    do {
        std::cout << "Please enter phone number: " << std::endl;
        std::cin >> phoneNumber;
    } while(phoneNumber.size() != 9 || phoneNumber[0] != '0');
    for (int i = 0; i < contacts.size(); ++i) {
        if (contacts[i].getPhoneNumber() == phoneNumber) {
            contacts.erase(i + contacts.begin());
            std::cout << "Element removed successfully" << std::endl;
            file();
            return;
        }
    }
    std::cout << "No such element" << std::endl;
}

void AddressBook::addContact() {
    Contact newContact;
    newContact.setFullName();
    newContact.setMail();
    newContact.setPhoneNumber();
    contacts.push_back(newContact);
    file();
}

void AddressBook::file() const {
    std::remove("address_book.txt");
    std::ofstream out("address_book.txt");
    if(out.is_open()) {
        for(int i = 0; i < contacts.size(); ++i) {
            out << contacts[i];
        }
        out.close();
    }
}

void AddressBook::showCommands() {
    std::string command;
    do {
        std::cout << "Choose the option:" << std::endl;
        std::cout << "   addContact" << std::endl << "   removeContact" << std::endl << "   viewAllContacts" << std::endl << "   exit" << std::endl;
        std::cin >> command;
        if(command == "addContact") {
            addContact();
        }
        if(command == "removeContact") {
            removeContact();
        }
        if(command == "viewAllContacts") {
            viewAllContacts();
        }
    } while(command != "exit");
}

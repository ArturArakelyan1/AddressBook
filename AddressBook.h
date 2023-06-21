#ifndef ADDRESSBOOKH
#define ADDRESSBOOKH
#include <iostream>
#include <vector>
#include "Contact.h"

class AddressBook {
public:
void removeContact();
void addContact();
void viewAllContacts() const;
void file() const;
void showCommands();
private:
std::vector<Contact> contacts;
};

#include "AddressBook.hpp"

#endif // ADDRESS_BOOK_H
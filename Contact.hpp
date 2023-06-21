#include <iostream>
#include <fstream>
#include "Contact.h"

std::string Contact::getFullName() const {
    return fullName;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getMail() const {
    return mail;
}

void Contact::setFullName() {
    do {
        std::cout << "Please enter full name: " << std::endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, fullName);
    } while(fullName.size() == 0);
}

void Contact::setPhoneNumber() {
    do {
        std::cout << "Please enter phone number: " << std::endl;
        std::getline(std::cin, phoneNumber);
    } while (!isValidPhoneNumber(phoneNumber));
}

void Contact::setMail() {
    do {
        std::cout << "Please enter email: " << std::endl;
        std::getline(std::cin, mail);
    } while (!isValidMail(mail));
}

bool Contact::isValidPhoneNumber(std::string phoneNumber) const {
    if(phoneNumber.size() != 9 || phoneNumber[0] != '0') {
        return false;
    }
    return true;
}

bool Contact::isValidMail(std::string mail) const {
    if(mail.size() <= 10) {
        return false;
    }
    std::string tmp = mail.substr(mail.size() - 10);
    if (tmp == "@gmail.com" || tmp == "@email.com") {
        return true;
    }
    return false;
}

Contact::Contact(const Contact& other) {
    fullName = other.fullName;
    phoneNumber = other.phoneNumber;
    mail = other.mail;
}

Contact& Contact::operator=(const Contact& other) {
    if (this != &other) {
        fullName = other.fullName;
        phoneNumber = other.phoneNumber;
        mail = other.mail;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Contact& contact) {
    os << '\t' << "Full Name: " << contact.getFullName() << std::endl;
    os << '\t' << "Phone Number: " << contact.getPhoneNumber() << std::endl;
    os << '\t' << "Email: " << contact.getMail() << std::endl;
    return os;
}

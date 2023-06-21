#ifndef CONTACTH
#define CONTACTH
#include <iostream>
#include <vector>

class Contact {
public:
    Contact() = default;
    Contact(const Contact& other);
    ~Contact() = default;
    Contact& operator=(const Contact&);
    std::string getFullName() const;
    std::string getPhoneNumber() const;
    std::string getMail() const;
    void setFullName();
    void setPhoneNumber();
    void setMail();
    bool isValidPhoneNumber(std::string) const;
    bool isValidMail(std::string) const;
private:
    std::string fullName = "";
    std::string phoneNumber = "";
    std::string mail = "";
};
#include "contact.hpp"

#endif // CONTACTH

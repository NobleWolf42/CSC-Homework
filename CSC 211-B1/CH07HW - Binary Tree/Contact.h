/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <list>
#include "Charge.h"
#include <sstream>
#include <iostream>


using std::list;
using std::string;

class Contact {
public:
    // default constructor
    Contact() {
        name = "";
        address = "";
        email = "";
    }

    // non default constructor
    Contact(string name, string address, string email) {
        this->name = name;
        this->address = address;
        this->email = email;
    }

    // copy constructor
    Contact(const Contact& orig) {
        this->name = orig.getName();
        this->address = orig.getAddress();
        this->email = orig.getEmail();
    }

    virtual ~Contact() {

    }

    void setEmail(string email) {
        this->email = email;
    }

    string getEmail() const {
        return email;
    }
    
    void setAddress(string address) {
        this->address = address;
    }
    
    string getAddress() const {
        return address;
    }
    
    void setName(string name) {
        this->name = name;
    }
    
    string getName() const {
        return name;
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Contact& contact) {
        out << "Name: " << contact.getName() << " Address: " << contact.getAddress() << " Email: " << contact.getEmail() << "\n";
        return out;
    }

private:    
    string name;
    string address;
    string email;    
};



#endif /* CONTACT_H */

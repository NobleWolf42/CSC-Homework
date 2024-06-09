/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Charge.h"
#include "Contact.h"

class Customer {
public:
    Customer() {
        card_number = "";
        contact = Contact();
        limit = 0;
    }

    // non-default constructor
    Customer(string ccn, Contact& contact, double limit, list<Charge> charges) {
        this->card_number = ccn;
        this->contact = contact;
        this->limit = limit;
        this->charges = charges;
    }

    //copy constructor
    Customer(const Customer& orig) {
        this->card_number = orig.GetCard_number();
        this->contact = orig.GetContact();
        this->limit = orig.GetLimit();
        this->charges = orig.GetCharges();
    }

    virtual ~Customer() {
    }

    void SetCharges(list<Charge> charges) {
        this->charges = charges;
    }
    
    list<Charge> GetCharges() const {
        return charges;
    }
    
    void SetLimit(double limit) {
        this->limit = limit;
    }
    
    double GetLimit() const {
        return limit;
    }
    
    void SetContact(Contact& contact) {
        this->contact = contact;
    }
    
    Contact GetContact() const {
        return contact;
    }
    
    void SetCard_number(string card_number) {
        this->card_number = card_number;
    }
    
    string GetCard_number() const {
        return card_number;
    }
    
    bool operator<(const Customer& other) const {
        if (this->GetCard_number() < other.GetCard_number()) {
            return true;
        } else {
            return false;
        }
    }
    
    void push_back(Charge c) {
        charges.push_back(c);
    }
    
    friend std::ostream& operator<<(std::ostream& out, const Customer& customer) {
        out << "Customer: " << customer.GetContact() << "C#:" << customer.GetCard_number() << "\n";
        return out;
    }
    
private:
    string card_number;
    Contact contact;
    double limit;
    list<Charge> charges;
};

#endif /* CUSTOMER_H */


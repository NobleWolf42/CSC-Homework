/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CHARGE_H
#define CHARGE_H
#include <string>

using std::string;

class Charge {
public:
    Charge() {
        business = "";
        amount = 0;
    };  // default constructor

    Charge(string business, double amount) {
        this->business = business;
        this->amount = amount;
    }

    Charge(const Charge& orig) {
        this->business = orig.GetBusiness();
        this->amount = orig.GetAmount();
    }

    virtual ~Charge() {

    }

    double GetAmount() const {
        return amount;
    }

    string GetBusiness() const {
        return business;
    }

private:
    string business;    // business name
    double amount;      // charge amount
};

#endif /* CHARGE_H */

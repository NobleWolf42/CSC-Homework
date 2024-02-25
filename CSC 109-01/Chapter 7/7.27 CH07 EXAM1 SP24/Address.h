/*
Copyright 2024
Author: Ben Carpenter
*/

#ifndef ADDRESSH
#define ADDRESSH

#include <string>

using std::string;
using std::cout;
using std::endl;

class Address {
    private:
        int house_number, apartment_number;
        string street, city, state, postal_code;
   
    public:
        Address();
        Address(int house_number, string street, int apartment_number, string city, string state, string postal_code);
        Address(int house_number, string street, string city, string state, string postal_code);
        int getHouseNumber();
        void setHouseNumber(int house_number);
        string getStreet();
        void setStreet(string street);
        int getApartmentNumber();
        void setApartmentNumber(int apartment_number);
        string getCity();
        void setCity(string city);
        string getState();
        void setState(string state);
        string getPostalCode();
        void setPostalCode(string postal_code);
        void print();
        bool operator<(const Address& other);
};

#endif

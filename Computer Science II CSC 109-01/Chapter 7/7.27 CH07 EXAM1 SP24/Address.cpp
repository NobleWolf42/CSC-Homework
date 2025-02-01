/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <iostream>
#include "Address.h"

Address::Address() {
    house_number = 0;
    apartment_number = 0;
    street = "";
    city = "";
    state = "";
    postal_code = "";
}

Address::Address(int house_number, string street, int apartment_number, string city, string state, string postal_code) {
    this->house_number = house_number;
    this->street = street;
    this->apartment_number = apartment_number;
    this->city = city;
    this->state = state;
    this->postal_code = postal_code;
}

Address::Address(int house_number, string street, string city, string state, string postal_code) {
    this->house_number = house_number;
    this->street = street;
    this->apartment_number = 0;
    this->city = city;
    this->state = state;
    this->postal_code = postal_code;
}

int Address::getHouseNumber() {
    return house_number;
}

void Address::setHouseNumber(int house_number) {
    this->house_number = house_number;
}

string Address::getStreet() {
    return street;
}

void Address::setStreet(string street) {
    this->street = street;
}

int Address::getApartmentNumber() {
    return apartment_number;
}

void Address::setApartmentNumber(int apartment_number) {
    this->apartment_number = apartment_number;
}

string Address::getCity() {
    return city;
}

void Address::setCity(string city) {
    this->city = city;
}

string Address::getState() {
    return state;
}

void Address::setState(string state) {
    this->state = state;
}

string Address::getPostalCode() {
    return postal_code;
}

void Address::setPostalCode(string postal_code) {
    this->postal_code = postal_code;
}

void Address::print() {
    if (apartment_number == 0) {
        cout << house_number << " " << street << endl;
    } else {
        cout << house_number << " " << street << ", #" << apartment_number << endl;
    }

    cout << city << ", " << state << ", " << postal_code << endl;
}

bool Address::operator<(const Address& other) {
   return this->postal_code < other.postal_code;
}

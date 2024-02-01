/*
Copyright 2024
Author: Ben Carpenter
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Car.h"

void Car::SetModelYear(int userYear) {
    modelYear = userYear;
}

int Car::GetModelYear() const {
    return modelYear;
}

void Car::SetPurchasePrice(int cost) {
    purchasePrice = cost;
}

int Car::GetPurchasePrice() const {
    return purchasePrice;
}

void Car::CalcCurrentValue(int currentYear) {
    double depreciationRate = 0.15;
    int carAge = currentYear - modelYear;
      
    // Car depreciation formula
    currentValue = purchasePrice * pow((1 - depreciationRate), carAge);
}

int Car::GetCurrentValue() const {
    int curVal;

    curVal = (currentValue + .5) / 1;

    return curVal;
}

void Car::PrintInfo() {
    std::cout << "Car's information:" << std::endl;
    std::cout << "  Model year: " << modelYear << std::endl;
    std::cout << "  Purchase price: $" << purchasePrice << std::endl;
    std::cout << std::fixed << std::setprecision(0);
    std::cout << "  Current value: $" << currentValue << std::endl;
}

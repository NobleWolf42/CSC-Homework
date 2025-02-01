/*
Copyright 2024
Author: Ben Carpenter

Assignment:
Given main(), complete the Car class (in files Car.h and Car.cpp) with member functions to set and get the purchase price of a car (SetPurchasePrice(), GetPurchasePrice()), and to output the car's information (PrintInfo()).

Ex: If the input is:

    *2011
    *18000
    *2018

where 2011 is the car's model year, 18000 is the purchase price, and 2018 is the current year, the output is:

    *Car's information:
    *  Model year: 2011
    *  Purchase price: $18000
    *  Current value: $5770

Notes:

    *PrintInfo() should use two spaces for indentation.
    *Add cout << fixed << setprecision(0); right before printing currentValue to ignore cents in the output.
    
*/

#include <iostream>
#include "Car.h"
using namespace std;

int main() {
   int userYear;
   int userPrice;
   int userCurrentYear;
   Car myCar;
      
   cin >> userYear;
   cin >> userPrice;
   cin >> userCurrentYear;
      
   myCar.SetModelYear(userYear);
   myCar.SetPurchasePrice(userPrice);
   myCar.CalcCurrentValue(userCurrentYear);
      
   myCar.PrintInfo();
   
   return 0;
}

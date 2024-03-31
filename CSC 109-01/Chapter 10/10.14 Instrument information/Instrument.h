/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef INSTRUMENTH
#define INSTRUMENTH

#include <iostream>
#include <iomanip>
#include <string>

using std::string;

class Instrument {
protected:
    string instrumentName;
    string instrumentManufacturer;
    int yearBuilt;
    int cost;

public:
    void SetName(string userName);

    string GetName();

    void SetManufacturer(string userManufacturer);

    string GetManufacturer();

    void SetYearBuilt(int userYearBuilt);

    int GetYearBuilt();

    void SetCost(int userCost);

    int GetCost();

    void PrintInfo();
};

#endif

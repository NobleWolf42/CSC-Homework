/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef INSTRUMENTH
#define INSTRUMENTH

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

template <typename T1, typename T2, typename T3>
class Instrument {
protected:
	string instrumentName;
	string instrumentManufacturer;
	T1 yearBuilt;  //int string
	T2 cost;  // int, double
	T3 id; // int, double, string

public:
	void SetName(string userName);

	string GetName();

	void SetManufacturer(string userManufacturer);

	string GetManufacturer();

	void SetYearBuilt(T1 userYearBuilt);

	T1 GetYearBuilt();

	void SetCost(T2 userCost);

	T2 GetCost();

	void PrintInfo();  // override stream operator<<
};

#endif

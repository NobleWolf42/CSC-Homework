/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Instrument.h"

template <typename T1, typename T2, typename T3>
void Instrument<T1, T2, T3>::SetName(string userName) {
	instrumentName = userName;
}

template <typename T1, typename T2, typename T3>
string Instrument<T1, T2, T3>::GetName() {
	return instrumentName;
}

template <typename T1, typename T2, typename T3>
void Instrument<T1, T2, T3>::SetManufacturer(string userManufacturer) {
	instrumentManufacturer = userManufacturer;
}

template <typename T1, typename T2, typename T3>
string Instrument<T1, T2, T3>::GetManufacturer() {
	return instrumentManufacturer;
}

template <typename T1, typename T2, typename T3>
void Instrument<T1, T2, T3>::SetYearBuilt(T1 userYearBuilt) {
	yearBuilt = userYearBuilt;
}

template <typename T1, typename T2, typename T3>
T1 Instrument<T1, T2, T3>::GetYearBuilt() {
	return yearBuilt;
}

template <typename T1, typename T2, typename T3>
void Instrument<T1, T2, T3>::SetCost(T2 userCost) {
	cost = userCost;
}

template <typename T1, typename T2, typename T3>
T2 Instrument<T1, T2, T3>::GetCost() {
	return cost;
}

template <typename T1, typename T2, typename T3>
void Instrument<T1, T2, T3>::PrintInfo() {
	cout << "Instrument Information: " << endl;
	cout << "   Name: " << instrumentName << endl;
	cout << "   Manufacturer: " << instrumentManufacturer << endl;
	cout << "   Year built: " << yearBuilt << endl;
	cout << "   Cost: " << cost << endl;
}
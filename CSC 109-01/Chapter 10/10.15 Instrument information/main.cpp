/*
Author: Ben Carpenter
Copyright: 2024

Assignment:

Given main() and the Instrument class, define a derived class, StringInstrument, for string instruments, with functions to set and get private data members of the following types:

    - int to store the number of strings
    - int to store the number of frets
    - bool to store whether the instrument is bowed

Ex. If the input is:

    *Drums
    *Zildjian
    *2015
    *2500
    *Guitar
    *Gibson
    *2002
    *1200
    *6
    *19
    *0

the output is:

    *Instrument Information: 
    *   Name: Drums
    *   Manufacturer: Zildjian
    *   Year built: 2015
    *   Cost: 2500
    *Instrument Information: 
    *   Name: Guitar
    *   Manufacturer: Gibson
    *   Year built: 2002
    *   Cost: 1200
    *   Number of strings: 6
    *   Number of frets: 19
    *   Is bowed: false

*/

#include "StringInstrument.h"

int main() {
		Instrument myInstrument;
		StringInstrument myStringInstrument;

		string instrumentName, manufacturerName, stringInstrumentName, stringManufacturer;
		int yearBuilt, cost, stringYearBuilt, stringCost, numStrings, numFrets;
		bool bowed;

		cin >> instrumentName;
		cin >> manufacturerName;
		cin >> yearBuilt;
		cin >> cost;

		cin >> stringInstrumentName;
		cin >> stringManufacturer;
		cin >> stringYearBuilt;
		cin >> stringCost;
		cin >> numStrings;
		cin >> numFrets;
		cin >> bowed;

		myInstrument.SetName(instrumentName);
		myInstrument.SetManufacturer(manufacturerName);
		myInstrument.SetYearBuilt(yearBuilt);
		myInstrument.SetCost(cost);
		myInstrument.PrintInfo();

		myStringInstrument.SetName(stringInstrumentName);
		myStringInstrument.SetManufacturer(stringManufacturer);
		myStringInstrument.SetYearBuilt(stringYearBuilt);
		myStringInstrument.SetCost(stringCost);
		myStringInstrument.SetNumOfStrings(numStrings);
		myStringInstrument.SetNumOfFrets(numFrets);
		myStringInstrument.SetIsBowed(bowed);
		myStringInstrument.PrintInfo();

		cout << "   Number of strings: " << myStringInstrument.GetNumOfStrings() << endl;
		cout << "   Number of frets: " << myStringInstrument.GetNumOfFrets() << endl;
		cout << "   Is bowed: " << boolalpha << myStringInstrument.GetIsBowed() << endl;
}

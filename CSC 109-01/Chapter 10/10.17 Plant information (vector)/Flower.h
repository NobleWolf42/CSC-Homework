/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef FLOWERH
#define FLOWERH

#include "Plant.h"
#include <string>

using std::string;

class Flower : public Plant {
    public:
        void SetPlantType(bool userIsAnnual);

        bool GetPlantType() const;

        void SetColorOfFlowers(string userColorOfFlowers);

        string GetColorOfFlowers() const;

        void PrintInfo() const;

    private:
        bool isAnnual;
        string colorOfFlowers;
};

#endif

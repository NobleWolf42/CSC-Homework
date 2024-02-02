/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef FOODITEMH
#define FOODITEMH

#include <string>

class FoodItem {
    public:
        FoodItem();

        FoodItem(std::string newName, double newFat, double newCarbs, double newProtein);

        std::string GetName();

        double GetFat();

        double GetCarbs();

        double GetProtein();

        double GetCalories(double numServings);

        void PrintInfo();

    private:
        std::string name;
        double fat;
        double carbs;
        double protein;
};

#endif

/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "FoodItem.h"
#include <iostream>
#include <iomanip> 

FoodItem::FoodItem() {
    name = "Water";
    fat = 0;
    carbs = 0;
    protein = 0;
}

FoodItem::FoodItem(std::string newName, double newFat, double newCarbs, double newProtein) {
    name = newName;
    fat = newFat;
    carbs = newCarbs;
    protein = newProtein;
}

std::string FoodItem::GetName() {
    return name;
}

double FoodItem::GetFat() {
    return fat;
}

double FoodItem::GetCarbs() {
    return carbs;
}

double FoodItem::GetProtein() {
    return protein;
}

double FoodItem::GetCalories(double numServings) {
    // Calorie formula
    double calories = ((fat * 9) + (carbs * 4) + (protein * 4)) * numServings;
    return calories;
}

void FoodItem::PrintInfo() {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Nutritional information per serving of " << name  << ":" << std::endl;
    std::cout << "  Fat: " << fat << " g" << std::endl;
    std::cout << "  Carbohydrates: " << carbs << " g" << std::endl;
    std::cout << "  Protein: " << protein << " g" << std::endl;
}

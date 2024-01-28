/*
Copyright 2024
Author: Ben Carpenter
*/
#include "Restaurant.h"
#include <iostream>


void Restaurant::SetName(std::string restaurantName) {
    name = restaurantName;
}

void Restaurant::SetRating(int userRating) {
    rating = userRating;
}

void Restaurant::Print() {
    std::cout << name << " Rating: " << rating << std::endl;
}

Restaurant::Restaurant() {
    name = "";
    rating = 0;
}

Restaurant::Restaurant(std::string name, int userRating) {
    this->name = name;
    rating = userRating;

}

const std::string &Restaurant::GetName() const {
    return name;
}

int Restaurant::GetRating() const {
    return rating;
}



/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Cat.h"
#include <iostream>
#include <string>
using namespace std;

void Cat::SetBreed(string userBreed) {
    catBreed = userBreed;
}

string Cat::GetBreed() {
    return catBreed;
}
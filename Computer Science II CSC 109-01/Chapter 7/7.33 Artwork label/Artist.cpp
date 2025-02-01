/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Artist.h"
#include <iostream>
#include <string>

Artist::Artist() {
    artistName = "unknown";
    birthYear = -1;
    deathYear = -1;
}

Artist::Artist(std::string artistName, int birthYear, int deathYear) {
    this->artistName = artistName;
    this->birthYear = birthYear;
    this->deathYear = deathYear;
}

std::string Artist::GetName() const {
    return artistName;
}

int Artist::GetBirthYear() const {
    return birthYear;
}

int Artist::GetDeathYear() const {
    return deathYear;
}

void Artist::PrintInfo() const {
    std::cout << "Artist: " << GetName() << " (";
    if (GetBirthYear() != -1 && GetDeathYear() != -1) {
        std::cout << GetBirthYear() << " to " << GetDeathYear() << ")" << std::endl;
    } else if (GetBirthYear() != -1) {
        std::cout << GetBirthYear() << " to present)" << std::endl;
    } else {
        std::cout << "unknown)" << std::endl;
    }
}

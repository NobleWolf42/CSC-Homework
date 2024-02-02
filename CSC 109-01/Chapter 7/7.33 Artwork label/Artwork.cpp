/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Artwork.h"
#include <iostream>


Artwork::Artwork() {
    Artist newArtist;
    title = "Unknown";
    yearCreated = -1;
    artist = newArtist;
}

Artwork::Artwork(std::string title, int yearCreated, Artist artist) {
    this->title = title;
    this->yearCreated = yearCreated;
    this->artist = artist;
}

std::string Artwork::GetTitle() {
    return title;
}

int Artwork::GetYearCreated() {
    return yearCreated;
}

void Artwork::PrintInfo() {
    artist.PrintInfo();
    std::cout << "Title: " << GetTitle() << ", " << GetYearCreated() << std::endl;
}

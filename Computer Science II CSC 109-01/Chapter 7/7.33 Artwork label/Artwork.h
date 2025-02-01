/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef ARTWORKH
#define ARTWORKH

#include "Artist.h"

class Artwork{
    public:
        Artwork();

        Artwork(std::string title, int yearCreated, Artist artist);

        std::string GetTitle();

        int GetYearCreated();

        void PrintInfo();
   
    private:
        std::string title;
        int yearCreated;
        Artist artist;

};

#endif

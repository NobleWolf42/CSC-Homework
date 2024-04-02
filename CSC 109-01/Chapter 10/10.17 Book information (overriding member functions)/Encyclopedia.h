/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef ENCYCLOPEDIAH
#define ENCYCLOPEDIAH

#include "Book.h"

class Encyclopedia : public Book {
    private:
        string eEdition;
        int ePages, eVolumes;

    public:
        
        void SetEdition(string edition);
        
        void SetNumPages(int pages);

        void SetNumVolumes(int volumes);
        
        string GetEdition();
        
        int GetNumPages();

        int GetNumVolumes();
        
        void PrintInfo();

};

#endif

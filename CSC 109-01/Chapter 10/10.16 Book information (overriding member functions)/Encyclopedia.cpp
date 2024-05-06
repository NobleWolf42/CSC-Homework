/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Encyclopedia.h"
#include <iostream>

using std::cout;
using std::endl;

void Encyclopedia::SetEdition(string edition) {
    eEdition = edition;
}
        
void Encyclopedia::SetNumPages(int pages) {
    ePages = pages;
}

void Encyclopedia::SetNumVolumes(int volumes) {
    eVolumes = volumes;
}
        
string Encyclopedia::GetEdition() {
    return eEdition;
}
        
int Encyclopedia::GetNumPages() {
    return ePages;
}

int Encyclopedia::GetNumVolumes() {
    return eVolumes;
}
        
void Encyclopedia::PrintInfo() {
    Book::PrintInfo();
    cout << "   Edition: " << eEdition << endl;
    cout << "   Number of Pages: " << ePages << endl;
}

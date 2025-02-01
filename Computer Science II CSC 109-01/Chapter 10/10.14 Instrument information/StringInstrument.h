/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

class StringInstrument : public Instrument {
    private:
        int numStrings, numFrets;
        bool isBowed;
    
    public:
        void SetNumOfStrings(int strings);

        void SetNumOfFrets(int frets);

        void SetIsBowed(bool bowed);

        int GetNumOfStrings();

        int GetNumOfFrets();

        bool GetIsBowed();

};

#endif

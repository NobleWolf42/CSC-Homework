/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef STR_INSTRUMENTH
#define STR_INSTRUMENTH

#include "Instrument.h"

template <typename T1, typename T2, typename T3, typename T4>
class StringInstrument : public Instrument<T1, T2, T3> {
    private:
        
        int numStrings, numFrets;
        T4 isBowed;
	
    public:
        
        void SetNumOfStrings(int strings);
        
        void SetNumOfFrets(int frets);
        
        void SetIsBowed(T4 bowed);

        int GetNumOfStrings();
        
        int GetNumOfFrets();
        
        T4 GetIsBowed();
};

#endif

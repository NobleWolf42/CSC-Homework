/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "StringInstrument.h"

template <typename T1, typename T2, typename T3, typename T4>
void StringInstrument<T1, T2, T3, T4>::SetNumOfStrings(int strings) {
    numStrings = strings;
}

template <typename T1, typename T2, typename T3, typename T4>  
void StringInstrument<T1, T2, T3, T4>::SetNumOfFrets(int frets) {
    numFrets = frets;
}

template <typename T1, typename T2, typename T3, typename T4> 
void StringInstrument<T1, T2, T3, T4>::SetIsBowed(T4 bowed) {
    isBowed = bowed;
}

template <typename T1, typename T2, typename T3, typename T4>
int StringInstrument<T1, T2, T3, T4>::GetNumOfStrings() {
    return numStrings;
}

template <typename T1, typename T2, typename T3, typename T4>
int StringInstrument<T1, T2, T3, T4>::GetNumOfFrets() {
    return numFrets;
}

template <typename T1, typename T2, typename T3, typename T4>
T4 StringInstrument<T1, T2, T3, T4>::GetIsBowed() {
    return isBowed;
}

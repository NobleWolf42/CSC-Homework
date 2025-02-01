/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "ElectricStrInstrument.h"

template <typename T1, typename T2, typename T3, typename T4, typename T5>
void ElectricStrInstrument<T1, T2, T3, T4, T5>::setCurrent(T5 currentIn) {
    current = currentIn;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5>
T5 ElectricStrInstrument<T1, T2, T3, T4, T5>::getCurrent() {
    return current;
}

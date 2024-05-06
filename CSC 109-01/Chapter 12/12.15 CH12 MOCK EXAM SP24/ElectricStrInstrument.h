#ifndef ESTR_INSTRUMENTH
#define ESTR_INSTRUMENTH

#include "StringInstrument.h"

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class ElectricStrInstrument : public StringInstrument<T1, T2, T3, T4> {
	private:

        T5 current;

    public:

        void setCurrent(T5 currentIn);

        T5 getCurrent();

};

#endif

/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Number.h"
#include <iostream>
#include <sstream>

Number::Number(int number) {
	num = number;
}

void Number::SetNum(int number) {
	num = number;
}

int Number::GetNum() {
	return num;
}

ostream& operator<<(ostream &out, const  Number& n) {
    std::ostringstream output;
    output << "You number is " << n.num << std::endl;
    return output;
}
/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Daily.h"

Daily::Daily() : Appointment() {

}
        
Daily::Daily(string desc, Time s, Time e):Appointment(desc, s, e) {

}

void Daily::save(ostream& out) const {
    out << "Daily\n";
    Appointment::save(out);
}

bool Daily::occurs_on(int year, int month, int day) const {
    return true;
}

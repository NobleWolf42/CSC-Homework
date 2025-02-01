/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Monthly.h"

Monthly::Monthly():Appointment() {
    day = 0;
}

Monthly::Monthly(string desc, int d, Time s, Time e):Appointment(desc, s, e) {
    day = d;
}

void Monthly::read() {
    int d;
    
    Appointment::read();

    cout << "Enter day: " << endl;
    
    cin >> d;
    day = d;
}

void Monthly::save(ostream& out) const {
    out << "Monthly\n" << day << "\n";
    Appointment::save(out);
}
   
void Monthly::load(istream& in) {
    int d;

    in >> d;
    day = d;
    Appointment::load(in);
}

bool Monthly::occurs_on(int year, int month, int day) const {
    if (this->day == day) {
        return true;
    } else {
        return false;
    }
}

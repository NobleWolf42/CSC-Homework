/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Onetime.h"


Onetime::Onetime():Appointment() {
    Date temp;
    when = temp;
}

        /**
            Constructs a Onetime appointment.
            @param desc the description of a daily appointment
            @param d the date of the appointment
            @param s the start time of the appointment
            @param e the end time of the appointment
        */
Onetime::Onetime(string desc, Date d, Time s, Time e):Appointment(desc, s, e) {
    when = d;
}

void Onetime::read() {
    int year, month, day;

    Appointment::read();

    cout << "Enter year month day: " << endl;

    cin >> year >> month >> day;

    when = Date(year, month, day);



}

void Onetime::save(ostream& out) const {
    out << "Onetime\n" << when.get_year() << " " << when.get_month() << " " << when.get_day() << "\n";

    Appointment::save(out);
}

void Onetime::load(istream& in) {
    int year, month, day;

    in >> year >> month >> day;

    when = Date(year, month, day);

    Appointment::load(in);
}

bool Onetime::occurs_on(int year, int month, int day) const {
    Date d(year, month, day);
    if (when == d) {
        return true;
    } else {
        return false;
    }
}

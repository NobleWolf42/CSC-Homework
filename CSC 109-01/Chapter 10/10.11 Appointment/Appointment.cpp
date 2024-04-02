/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <string>
#include <iostream>
#include <iomanip>
#include "Appointment.h"

Appointment::Appointment() {
    Time s;
    Time e;
    description = "";
    start = s;
    end = e;
}

Appointment::Appointment(std::string desc, Time s, Time e) {
    description = desc;
    start = s;
    end = e;
}

Time Appointment::getStart() {
    return start;
}

Time Appointment::getEnd() {
    return end;
}

string Appointment::getDescription() {
    return description;
}

void Appointment::print() const {
    cout << setfill('0') << start.get_hours() << ":" << setw(2) << start.get_minutes() << " - " << end.get_hours() << ":" << setw(2) << end.get_minutes() << " " << description << endl;
}

void Appointment::read() {
    int sh, sm, eh, em;
    string desc;

    cout << "Enter start_hours start_mins end_hours end_mins descript: " << endl;
    
    cin >> sh >> sm >> eh >> em;
    getline(cin, desc);

    Time s(sh, sm, 0);
    Time e(eh, em, 0);

    start = s;
    end = e;
    description = desc;
}

void Appointment::save(std::ostream& out) const {
    out << start.get_hours() << " " << start.get_minutes() << " " << end.get_hours() << " " << end.get_minutes() << description << "\n";
}

void Appointment::load(std::istream& in) {
    int sh, sm, eh, em;
    string desc;
    
    in >> sh >> sm >> eh >> em;
    getline(in, desc);

    Time s(sh, sm, 0);
    Time e(eh, em, 0);

    start = s;
    end = e;
    description = desc;
}

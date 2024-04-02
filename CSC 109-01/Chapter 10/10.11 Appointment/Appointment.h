/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>
#include <iostream>
#include <iostream>
#include <iomanip>
#include "Time.h"

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::cin;
using std::getline;

class Appointment {
    public:
        /**
            Constructs an appointment object 
        */
        Appointment();
        
        /**
            Constructs a appointment.
            @param desc the description of the appointment
            @param s the start time of the appointment
            @param e the end time of the appointment
        */
        Appointment(std::string desc, Time s, Time e);
   
        /*
            * print out the appointment in the following format
            * 5:00 - 6:00  dentist
        */
        void print() const;
   
        /*
            read in the appointment in the following format
            * start_hours start_mins end_hours end_mins descript
            * 5 0 6 0 dentist 
        */
        void read();
   
        /*
            save the appointment separate by space
            * Enter start_hours start_mins end_hours end_mins descript:
            * 5 0 6 0 dentist
        */
        virtual void save(std::ostream& out) const;
        
        /*
            * Load the appointment from file
            * start_hours start_mins end_hours end_mins descript; for example:
            * 5 0 6 0 dentist
        */
        virtual void load(std::istream& in);
        
        /**
            Determines if the appointment occurs on the given date.
            @param year a year value
            @param month a month value of 1 for Jan, to 12 for Dec
            @param day a day value
            @return true if the appointment occurs on the given date
        */
        virtual bool occurs_on(int year, int month, int day) const = 0;

    private:
        string description;  // appointment description
        Time start;  // start time appointment
        Time end;    // end time appointment
};


#endif /* APPOINTMENT_H */


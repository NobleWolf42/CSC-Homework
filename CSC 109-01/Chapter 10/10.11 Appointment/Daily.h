/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef DAILY_H
#define DAILY_H

#include "Appointment.h"
#include "Time.h"
/*
 * Daily appointment.  Inherit from appointment class
 * 
 */
class Daily : public Appointment {
    public:
        /**
            Constructs a daily appointment 
        */
        Daily();
        
        /**
            Constructs daily appointment.
            @param desc the description of a daily appointment
            @param s the start time of the appointment
            @param e the end time of the appointment 
        */
        Daily(string desc, Time s, Time e);

        /*
            * save the daily appointment with a header
            * appointment type
            * start_hours start_mins end_hours end_mins descript; for example:
            * Daily
            * 5 0 6 0 dentist
        */   
        virtual void save(ostream& out) const;

        /**
            Determines if the appointment occurs on the given date.
            @param year a year value
            @param month a month value of 1 for Jan, to 12 for Dec
            @param day a day value
            @return true if the appointment occurs on the given date
        */
        virtual bool occurs_on(int year, int month, int day) const;
};

#endif /* DAILY_H */


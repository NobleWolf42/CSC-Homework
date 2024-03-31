/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Time.h"

using std::time;
using std::localtime;

Time::Time(int hour, int min, int sec) {
    time_in_secs = hour*3600 + min*60 + sec;
}

   /**
      Constructs a Time object that is set to 
      the time at which the constructor executes.
   */
Time::Time() {
    time_t now = time(0);
    struct tm *local_time = localtime(&now);

}


   /**
      Gets the hours of this time.
      @return the hours
   */
int Time::get_hours() const {
    time_in_secs = time;
}

   /**
      Gets the minutes of this time.
      @return the minutes
   */
int Time::get_minutes() const {

}

   /**
      Gets the seconds of this time.
      @return the seconds
   */
int Time::get_seconds() const {

}


   /**
      Computes the seconds between this time and another.
      @param t the other time
      @return the number of seconds between this time and t
   */
int Time::seconds_from(Time t) const {

}

   /**
      Adds a number of seconds to this time.
      @param s the number of seconds to add
   */
void Time::add_seconds(int s) {

}

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

Time::Time() {
    time_t now = time(nullptr);
    struct tm *local_time = localtime(&now);
    time_in_secs = local_time->tm_sec + local_time->tm_min*60 + local_time->tm_hour*3600;
}

int Time::get_hours() const {
    return time_in_secs/3600;
}

int Time::get_minutes() const {
    int mins;
    mins = time_in_secs%3600;

    return mins/60;
}

int Time::get_seconds() const {
    int secs;
    secs = time_in_secs%3600;
    secs = secs%60;

    return secs;
}

int Time::seconds_from(Time t) const {
    return time_in_secs - t.time_in_secs;
}

void Time::add_seconds(int s) {
    time_in_secs+= s;
}

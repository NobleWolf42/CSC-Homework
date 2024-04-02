/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Date.h"

using std::time;
using std::localtime;

Date::Date() {
    time_t now = time(nullptr);
    struct tm *local_time = localtime(&now);

    year = local_time->tm_year + 1900;
    month = local_time->tm_mon + 1;
    day = local_time->tm_mday;
}

Date::Date(int y, int m, int d) {
    year = y;
    month = m;
    day = d;
}

int Date::get_year() const {
    return year;
}

int Date::get_month() const {
    return month;
}

int Date::get_day() const {
    return day;
}

bool Date::operator==(Date other) const {
    if (this->year == other.year && this->month == other.month && this->day == other.day) {
        return true;
    } else {
        return false;
    }
}

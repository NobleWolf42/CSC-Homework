/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Course.h"

Course::Course() {
    dept = "None";
    coursenum = 0.0;
    term = "None";
    sections = 0;
    seats = 0;
}

Course::Course(string dept, double coursenum, string term, int sections, int seats) {
    this->dept = dept;
    this->coursenum = coursenum;
    this->term = term;
    this->sections = sections;
    this->seats = seats;
}

// copy constructor
Course::Course(const Course& orig) {
    this->coursenum = orig.GetCoursenum();
    this->dept = orig.GetDept();
    this->seats = orig.GetSeats();
    this->sections = orig.GetSections();
    this->term = orig.GetTerm();
}

// assignment operator
void Course::operator=(const Course& orig) {
    coursenum = orig.coursenum;
    dept = orig.dept;
    seats = orig.seats;
    sections = orig.sections;
    term = orig.term;
}

// == comparison operator
bool Course::operator==(const Course& orig) {
    if (this->dept == orig.GetDept() && this->coursenum == orig.GetCoursenum() && this->term == orig.GetTerm() && this->sections == orig.GetSections() && this->seats == orig.GetSeats()) {
        return true;
    } else {
        return false;
    }
}

// != comparison operator
bool Course::operator!=(const Course& orig) {
    if (this->dept == orig.GetDept() && this->coursenum == orig.GetCoursenum() && this->term == orig.GetTerm() && this->sections == orig.GetSections() && this->seats == orig.GetSeats()) {
        return false;
    } else {
        return true;
    }
}

// < comparison operator
// compare course number
bool Course::operator<(const Course& orig) {
    if (this->coursenum < orig.GetCoursenum()) {
        return true;
    } else {
        return false;
    }
}

bool Course::operator>=(const Course& orig) {
    if (this->coursenum >= orig.GetCoursenum()) {
        return true;
    } else {
        return false;
    }
}

// override the insertion operator
// return ostream in the following format.  Fields are separate
// by space and newline at the end.
// dept coursenum term sections course.seats 
std::ostream& operator<<(std::ostream& out, const Course& course) {
    out << course.GetDept() << " " << course.GetCoursenum() << " " << course.GetTerm() << " " << course.GetSections() << " " << course.GetSeats() << endl;
    return out;
}

// accessor and mutator methods
void Course::SetSeats(int seats) {
    this->seats = seats;
}

int Course::GetSeats() const {
    return seats;
}

void Course::SetSections(int sections) {
    this->sections = sections;
}

int Course::GetSections() const {
    return sections;
}

void Course::SetTerm(string term) {
    this->term = term;
}

string Course::GetTerm() const {
    return term;
}

void Course::SetCoursenum(double coursenum) {
    this->coursenum = coursenum;
}

double Course::GetCoursenum() const {
    return coursenum;
}

void Course::SetDept(string dept) {
    this->dept = dept;
}

string Course::GetDept() const {
    return dept;
}


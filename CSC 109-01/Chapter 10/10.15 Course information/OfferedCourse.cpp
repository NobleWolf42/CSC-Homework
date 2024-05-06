/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "OfferedCourse.h"

void OfferedCourse::SetInstructorName(string instructor) {
    courseInstructor = instructor;
}

void OfferedCourse::SetLocation(string location) {
    courseLocation = location;
}

void OfferedCourse::SetClassTime(string classTime) {
    courseTime = classTime;
}

void OfferedCourse::SetTerm(string term) {
    courseTerm = term;
}

string OfferedCourse::GetInstructorName() {
    return courseInstructor;
}

string OfferedCourse::GetLocation() {
    return courseLocation;
}

string OfferedCourse::GetClassTime() {
    return courseTime;
}

string OfferedCourse::GetTerm() {
    return courseTerm;
}

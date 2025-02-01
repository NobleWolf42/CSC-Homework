/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(string first, string last, double gpa) {
    this->first = first;
    this->last = last;
    this->gpa = gpa;
}

double Student::GetGPA() const {
    return this->gpa;
}

string Student::GetLast() const {
    return this->last;
}

string Student::GetFirst() const {
    return this->first;
}

ostream& operator<<(ostream &out, const  Student& s) {
    out << s.first << " " << s.last << " " << s.gpa;

    return out;
}

bool Student::operator==(Student s1) {
    if (this->first == s1.first && this->last == s1.last && this->gpa == s1.gpa) {
        return true;
    } else {
        return false;
    }
}

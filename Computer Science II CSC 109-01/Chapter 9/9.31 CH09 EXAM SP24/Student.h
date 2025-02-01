/*
Author: Ben Carpenter
Copyright: 2024
*/


#ifndef CSC109CH09EXAM1_STUDENT_H
#define CSC109CH09EXAM1_STUDENT_H


#include <string>

using std::string;
using std::ostream;

// Class representing a student
class Student {
public:
    /**
     * Initialize first, last, and gpa
     * @param first
     * @param last
     * @param gpa
     */
    Student(string first, string last, double gpa);  // student constructor (4 points)
    /*
     * @return gpa
     */
    double GetGPA() const; // return gpa (2 points)
    /**
     * @return last
     */
    string GetLast() const; // return last name (2 points)
    /**
     * @return first
     */
    string GetFirst() const; // return first name (2 points)
    //
    /**
     * override stream operator<< with first, last, gpa separate with a space (10 points)
     * @param out
     * @param s
     * @return ostream
     * See course.txt for output format
     * You will need to use this stream operator<< for Print and PassCourse functions
     * in Course.h to get full credits.
     */
    friend ostream& operator<<(ostream &out, const  Student& s);

    /**
     * Overload opeator== to check if two student objects are equal (5 points)
     * @param s1
     * @return
     */
    bool operator==(Student s1);

private:
    string first;  // first name
    string last;   // last name
    double gpa;    // grade point average
};


#endif //CSC109CH09EXAM1_STUDENT_H

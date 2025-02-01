/*
Author: Ben Carpenter
Copyright: 2024
*/

//
// Created by hloi on 10/29/2021.
// 60 points
//

#ifndef CSC109CH09EXAM1_COURSE_H
#define CSC109CH09EXAM1_COURSE_H

#include <vector>
#include "Student.h"

using std::ostream;
using std::vector;

class Course {
public:
    /**
     * roster getter
     * @return roster
     */
    const vector<Student> &GetRoster() const; // (5 points)
    /**
     * find the highest GPA from the vector roster; (10 points)
     * @return a student object with a first highest GPA.
     */
    Student FindStudentHighestGpa();
    /**
     * add a student to the vector roster
     * @param student
     */
    void AddStudent(Student s);  //  add a student to vector roster (5 points)

    /**
     * PassCourse selects students with a GPA greater than 74 and save them to filename (10 points)
     * @param fileName
     * Throw a runtime_error exception if the file can't be opened.
     * write to a file using the overload stream operator<< in Student.h for the following function
     * if you don't use the overload stream operator<<, you will loss 5 points.
     * See course.txt for output format.
     */
    void PassCourse(string fileName);
    /**
     * Load a student file into roster (10 points)
     * @param fileName
     * Throw a runtime_error exception if the file can't be opened.
     * See course.txt for input file format
     */
    void LoadFile(string fileName);  // Load file into rosters
    /**
     * Print out the student roster (10 point)
     * if you don't use the overload stream operator<<, you will get 5 points instead
     * See course.txt for output format.
     */
    void Print();  // print all the students in the roster using operator<< (5 points)

    /**
     *
     * @param out
     * @param Course
     * @return the list of students as ostream, each student is separated with a newline.
     * This function must use the operator<< from the student class. (5 points)
     */
    friend ostream& operator<<(ostream &out, const  Course& s);

    /** (10 points)
     * The RemoveStudent function first checks if the students vector is empty. If it's empty, it throws a
     * std::runtime_error exception indicating that the vector is empty and therefore a student cannot be removed.
     * If the vector is not empty, it proceeds to search for and remove the specified student using their first
     * name and last name as before.  Throw an exception if the student is not found in the vector.
     * Note, my test cases will just try to test if there is an exception thrown.  The exception message is not
     * tested.
     * @param student the student to be remove.  This is a student object.
     */
    void RemoveStudent(const Student& student);

private:
    vector<Student> roster;    //collection of Student objects
};



#endif //CSC109CH09EXAM1_COURSE_H

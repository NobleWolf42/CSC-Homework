/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Complete the Course and Student class by implementing the member functions. Assume that no two students have the same highest GPA.

Given classes:

    - Class Course represents a course, which contains a vector of Student objects as a course roster.
    - Class Student represents a classroom student, which has three private data members: first name, last name, and GPA. Note: For testing purposes, different student values will be used.

Please see Student.h and Course.h for additional instruction.

Ex. Create a file with the following students. The file consists of first name, last name, and gpa. Each field is separated by a space.

    *Marvin Sandoval 70
    *Brent Bridges 65
    *Dwayne Clayton 94
    *Maggie Miller 92
    *Joseph Pearson 69

Course.h has the following functions:

    1. LoadFile function will load the file into the student roster. Throw an runtime_error exception if the file can't be opened.
    2. PassCourse function will save the students with gpa 75 or greater into filename. Throw an exception if the file can't be opened.
    3. AddStudent function will add a student to the vector, roster.
    4. GetRoster function will return the vector, roster.
    5. operator<< return the list of students as ostream, each student is separated with a newline. This function must use the operator<< from the student class.
    6. Print function will print the vector roster using the stream operator<<.
    7. Remove function will remove a student from the vector, roster.

Student.h has the following functions:

    1. Student Constructor.
    2. GetFirst returns the first name.
    3. GetLast returns the last name.
    4. GetGPA returns the GPA.
    5. operator<< returns first, last, and GPA, each field is separated with a space, except the last field.
    6. Overload operator== to compare two student objects.

Please download the header files .h for your exam.

Please submit your code on Zybook and Web-CAT. Zybooks will count for 50%, and Web-CAT with student-written test cases will count for 50% of your grades.
*/

#include <iostream>
#include "Course.h"
#include "Student.h"
using namespace std;

int main() {
    Course course;
    cout << "Load course:" << endl;
    course.LoadFile("course1.txt");
    course.Print();
    course.PassCourse("passcourse1.txt");
    Course pCourse;
    cout << endl;
    cout << "Pass course:" << endl;
    pCourse.LoadFile("passcourse1.txt");
//    pCourse.Print();
    vector<Student> s = pCourse.GetRoster();
    for (size_t i=0; i<s.size(); i++) {
        cout << s.at(i) << endl;
    }
    cout << endl << "Test remove student Maggie" << endl;
    Student testStudent("Maggie", "Miller",  92);
    course.RemoveStudent(testStudent);
    course.Print();
    return 0;
}

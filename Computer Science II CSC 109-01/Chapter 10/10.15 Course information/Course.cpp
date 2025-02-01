/*
Author: Ben Carpenter
Copyright: 2024
*/

#include "Course.h"

using std::cout;
using std::endl;

void Course::SetCourseNumber(string cnum) {
    courseNum = cnum;
}

void Course::SetCourseTitle(string title) {
    courseTitle = title;
}

string Course::GetCourseNumber() {
    return courseNum;
}

string Course::GetCourseTitle() {
    return courseTitle;
}

void Course::PrintInfo() {
    cout << "Course Information:" << endl;
    cout << "   Course Number: " << courseNum <<endl;
    cout << "   Course Title: " << courseTitle << endl;
}

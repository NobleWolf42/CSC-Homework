/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef COURSEH
#define COURSEH

#include <iostream>
#include <string>

using std::string;

class Course {
    private:
        string courseNum, courseTitle;

    public:
        void SetCourseNumber(string cnum);

        void SetCourseTitle(string title);

        string GetCourseNumber();

        string GetCourseTitle();

        void PrintInfo();
        
};

#endif

/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef OFFERED_COURSEH
#define OFFERED_COURSEH

#include "Course.h"

class OfferedCourse : public Course {
    private:
        string courseInstructor, courseLocation, courseTime, courseTerm;
    
    public:
        void SetInstructorName(string instructor);

        void SetLocation(string location);

        void SetClassTime(string classTime);

        void SetTerm(string term);

        string GetInstructorName();

        string GetLocation();

        string GetClassTime();

        string GetTerm();

};

#endif

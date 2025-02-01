/*
Author: Ben Carpenter
Copyright: 2024
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Course.h"

using namespace std;

const vector<Student> &Course::GetRoster() const {
    return roster;
}

Student Course::FindStudentHighestGpa() {
    Student output("error", "error", 0.00);
    if (roster.size() != 0) {
        for (size_t i = 0; i < roster.size(); ++i) {
            if (roster.at(i).GetGPA() > output.GetGPA()) {
                output = roster.at(i);
            }
        }
    }
    return output;
}

void Course::AddStudent(Student s) {
    this->roster.push_back(s);
}

void Course::PassCourse(string fileName) {
    ofstream outputFS;

    try {
        outputFS.open(fileName);

        if (outputFS.fail()) {
            throw(runtime_error("Cannot open output file"));
        }

        for (size_t i = 0; i < this->roster.size(); ++i) {
            if (this->roster.at(i).GetGPA() > 74) {
                outputFS << roster.at(i) << "\n";
            }
        }
    
        outputFS.close();
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}

void Course::LoadFile(string fileName) {
    ifstream inputFS;
    bool running = true;
    string fName, lName;
    double gpa;

    try {
        cout << "Opening file " << fileName << endl;
        inputFS.open(fileName);

        if (inputFS.fail()) {
            throw(runtime_error("File did not load"));
        }

        while (running) {
            fName = "";
        
            inputFS >> fName >> lName >> gpa;

            if (fName == "") {
                running = false;
            } else {
                Student input(fName, lName, gpa);
                this->roster.push_back(input);
            }
        }
    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
    
}

void Course::Print() {
    for (size_t i = 0; i < this->roster.size(); ++i) {
        cout << this->roster.at(i) << endl;
    }
}

ostream& operator<<(ostream &out, const  Course& s) {
    for (size_t i = 0; i < s.roster.size(); ++i) {
        cout << s.roster.at(i) << endl;
    }

    return out;
}

void Course::RemoveStudent(const Student& student) {
    try {        
        if (this->roster.size() == 0) {
            throw(runtime_error("Roster is empty"));
        }

        bool studentFound = false;

        for (size_t i = 0; i < this->roster.size(); ++i) {
            if (this->roster.at(i) == student) {
                this->roster.erase(roster.begin() + i);
                studentFound = true;
            }
        }

        if (!studentFound) {
            throw(runtime_error("Student not found"));
        }

    } catch (runtime_error& e) {
        cout << e.what() << endl;
    }
}

/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Chapter 10 homework

Implement a base class Appointment and derived classes Onetime, Daily, and Monthly. An appointment has a description (for example, “see the dentist”) and a date and time. Write a virtual function occurs_on(int year, int month, int day) that checks whether the appointment occurs on that date. For example, for a monthly appointment, you must check whether the day of the month matches. Write a main function to test the appointment program by filling a vector of Appointment* with a mixture of appointments. Have the user enter a date and print out all appointments that happen on that date. Give the user the option to add new appointments. The user must specify the type of the appointment, the description, and the date and time. Let the user save the appointment data to a file and reload the data from a file. The saving part is straightforward: Make a virtual function save. Save out the type, description, date, and time. The loading part is not so easy. You must first determine the type of the appointment to be loaded, create an object of that type with its default constructor, and then call a virtual load function to load the remainder.

Running example:

    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): d
    *Enter start_hours start_mins end_hours end_mins descript:
    *10 11 11 10 dentist
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): m
    *Enter start_hours start_mins end_hours end_mins descript:
    *12 10 13 10 student
    *Enter day: 5
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): o
    *Enter start_hours start_mins end_hours end_mins descript:
    *13 30 14 20 dept
    *Enter year month day: 2018 3 20
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): c
    *Enter year month day: 2018 2 5
    *You have these appointments: 
    * 10:11 - 11:10  dentist
    * 12:10 - 13:10  student
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): s
    *File name: app.txt
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): q

Running example:

    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): l
    *File name: app.txt
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): c
    *Enter year month day: 2018 3 20
    *You have these appointments: 
    * 10:11 - 11:10   dentist
    * 13:30 - 14:20   dept
    *Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): q

*/

#include "Daily.h"
#include "Monthly.h"
#include "Onetime.h"
#include <iostream>

using namespace std;

void menu(char uIn, vector<Appointment*> &appts) {
    int year, month, day;
    string filename, type;
    ifstream inputFS;
    ofstream outputFS;
    bool running = true;
    
    switch (uIn) {
        case 'q': {
            cout << uIn;
            break;
        }

        case 'd': {
            cout << uIn << " ";
            Daily* itemp = new Daily();
            Appointment* temp = itemp;
            
            itemp->read();
            appts.push_back(temp);
            
            break;
        }

        case 'm': {
            cout << uIn << endl;
            Monthly* itemp = new Monthly();
            Appointment* temp = itemp;

            itemp->read();
            appts.push_back(temp);

            break;
        }

        case 'o': {
            cout << uIn << endl;
            Onetime* itemp = new Onetime();
            Appointment* temp = itemp;
            
            itemp->read();
            appts.push_back(temp);

            break;
        }

        case 'c': {
            cout << uIn << endl;
            cout << "Enter year month day: " << endl;
            cin >> year >> month >> day;
            cout << "You have these appointments: " << endl;
            
            for (size_t i = 0; i < appts.size(); i++) {
                if (appts.at(i)->occurs_on(year, month, day)) {
                    appts.at(i)->print();
                }
            }

            break;
        }

        case 's': {
            cout << uIn << endl;
            cin.ignore();
            cout << "File name: " << endl;
            getline(cin, filename);

            outputFS.open(filename);

            for (size_t i = 0; i < appts.size(); i++) {
                appts.at(i)->save(outputFS);
            }

            outputFS.close();

            break;
        }

        case 'l': {
            cout << uIn << endl;
            cin.ignore();
            cout << "File name: " << endl;
            getline(cin, filename);

            inputFS.open(filename);

            while(running) {
                type = "";
                inputFS >> type;
                if (type != "") {
                    if (type == "Daily") {
                        Daily* itemp = new Daily();
                        Appointment* temp = itemp;
                        itemp->load(inputFS);
                        appts.push_back(temp);
                    } else if (type == "Monthly") {
                        Monthly* itemp = new Monthly();
                        Appointment* temp = itemp;
                        itemp->load(inputFS);
                        appts.push_back(temp);
                    } else if (type == "Onetime") {
                        Onetime* itemp = new Onetime();
                        Appointment* temp = itemp;
                        itemp->load(inputFS);
                        appts.push_back(temp);
                    }
                } else {
                    running = false;
                }
            }

            inputFS.close();
            
            break;
        }

        default:
            break;
    }
}

int main() {
    char input;
    vector<Appointment*> userAppt;

    while (input != 'q') {
        cout << "Daily Monthly Onetime Check Save Load Quit (d/m/o/c/s/l/q): ";
        cin >> input;
        menu(input, userAppt);
    }

    return 0;
}
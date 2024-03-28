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


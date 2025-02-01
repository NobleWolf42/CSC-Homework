/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Write a program that reads the student information from a tab separated values (tsv) file. The program then creates a text file that records the course grades of the students. Each row of the tsv file contains the Last Name, First Name, Midterm1 score, Midterm2 score, and the Final score of a student. A sample of the student information is provided in StudentInfo.tsv. Assume the number of students is at least 1 and at most 20. Assume also the last names and first names do not contain whitespaces.

The program performs the following tasks:

    - Read the file name of the tsv file from the user.
    - Open the tsv file and read the student information.
    - Compute the average exam score of each student.
    - Assign a letter grade to each student based on the average exam score in the following scale:
        - A: 90 =< x
        - B: 80 =< x < 90
        - C: 70 =< x < 80
        - D: 60 =< x < 70
        - F: x < 60
    - Compute the average of each exam.
    - Output the last names, first names, exam scores, and letter grades of the students into a text file named report.txt. Output one student per row and separate the values with a tab character.
    - Output the average of each exam, with two digits after the decimal point, at the end of report.txt. Hint: Use the setprecision manipulator to format the output.

Ex: If the input of the program is:

    *StudentInfo.tsv

and the contents of StudentInfo.tsv are:

    *Barrett    Edan    70  45  59
    *Bradshaw    Reagan  96  97  88
    *Charlton    Caius   73  94  80
    *Mayo    Tyrese  88  61  36
    *Stern    Brenda  90  86  45

the file report.txt should contain:

    *Barrett    Edan    70  45  59  F
    *Bradshaw    Reagan  96  97  88  A
    *Charlton    Caius   73  94  80  B
    *Mayo    Tyrese  88  61  36  D
    *Stern    Brenda  90  86  45  C
    *
    *Averages: midterm1 83.40, midterm2 76.60, final 61.60

*/

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

char letterGrade(double grade) {
	char letter;
	
	if (grade >= 90) {
		letter = 'A';
    } else if (grade >= 80) {
		letter = 'B';
    } else if (grade >= 70) {
		letter = 'C';
	} else if (grade >= 60) {
		letter = 'D';
	} else {
		letter = 'F';
    }

	return letter;
}

int main() {

   /* TODO: Declare any necessary variables here. */
    ifstream inputFS;
    ofstream outputFS;
    string studentGrades, uIn, fName, lName;
    int grade1, grade2, grade3, g1Total = 0, g2Total = 0, g3Total = 0;
    double count = 0.0;
    bool running = true;
      
      
   /* TODO: Read a file name from the user and read the tsv file here. */
    cin >> uIn;

    // Try to open file
    outputFS.open("report.txt");
    inputFS.open(uIn);

    while (running) {
        fName = "";
        
        inputFS >> fName >> lName >> grade1 >> grade2 >> grade3;

        if (fName == "") {
            running = false;
        } else {
            outputFS << fName << "\t" << lName << "\t" << grade1 << "\t" << grade2 << "\t" << grade3  << "\t" << letterGrade((grade1 + grade2 + grade3) / 3.0) << "\n";
            g1Total += grade1;
            g2Total += grade2;
            g3Total += grade3;

            count++;
        }
    }

    inputFS.close();
   
   /* TODO: Compute student grades and exam averages, then output results to a text file here. */

   outputFS << fixed << setprecision(2)<< "\nAverages: midterm1 " << g1Total/count << ", midterm2 " << g2Total/count << ", final " << g3Total/count << "\n";

   outputFS.close();

   return 0;
}

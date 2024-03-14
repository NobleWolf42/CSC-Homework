/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
(1) Prompt the user for a title for data. Output the title. (1 pt)

Ex:

    *Enter a title for the data:
    *Number of Novels Authored
    *You entered: Number of Novels Authored

(2) Prompt the user for the headers of two columns of a table. Output the column headers. (1 pt)

Ex:

    *Enter the column 1 header:
    *Author name
    *You entered: Author name
    *
    *Enter the column 2 header:
    *Number of novels
    *You entered: Number of novels

(3) Prompt the user for data points. Data points must be in this format: string, int. Store the information before the comma into a string variable and the information after the comma into an integer. The user will enter -1 when they have finished entering data points. Output the data points. Store the string components of the data points in a vector of strings. Store the integer components of the data points in a vector of integers. (4 pts)

Ex:

    *Enter a data point (-1 to stop input):
    *Jane Austen, 6
    *Data string: Jane Austen
    *Data integer: 6

(4) Perform error checking for the data point entries. If any of the following errors occurs, output the appropriate error message and prompt again for a valid data point.

If entry has no comma
Output: Error: No comma in string. (1 pt)
If entry has more than one comma
Output: Error: Too many commas in input. (1 pt)
If entry after the comma is not an integer
Output: Error: Comma not followed by an integer. (2 pts)

Ex:

    *Enter a data point (-1 to stop input):
    *Ernest Hemingway 9
    *Error: No comma in string.
    *
    *Enter a data point (-1 to stop input):
    *Ernest, Hemingway, 9
    *Error: Too many commas in input.
    *
    *Enter a data point (-1 to stop input):
    *Ernest Hemingway, nine
    *Error: Comma not followed by an integer.
    *
    *Enter a data point (-1 to stop input):
    *Ernest Hemingway, 9
    *Data string: Ernest Hemingway
    *Data integer: 9

(5) Output the information in a formatted table. The title is right justified with a setw() value of 33. Column 1 has a setw() value of 20. Column 2 has a setw() value of 23. (3 pts)

Ex:

    *        Number of Novels Authored
    *Author name         |       Number of novels
    *--------------------------------------------
    *Jane Austen         |                      6
    *Charles Dickens     |                     20
    *Ernest Hemingway    |                      9
    *Jack Kerouac        |                     22
    *F. Scott Fitzgerald |                      8
    *Mary Shelley        |                      7
    *Charlotte Bronte    |                      5
    *Mark Twain          |                     11
    *Agatha Christie     |                     73
    *Ian Flemming        |                     14
    *Stephen King        |                     54
    *Oscar Wilde         |                      1

(6) Output the information as a formatted histogram. Each name is right justified with a setw() value of 20. (4 pts)

Ex:

    *         Jane Austen ******
    *     Charles Dickens ********************
    *    Ernest Hemingway *********
    *        Jack Kerouac **********************
    * F. Scott Fitzgerald ********
    *        Mary Shelley *******
    *    Charlotte Bronte *****
    *          Mark Twain ***********
    *     Agatha Christie *************************************************************************
    *        Ian Flemming **************
    *        Stephen King ******************************************************
    *         Oscar Wilde *

*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
    ostringstream outputTable;
    ostringstream outputHist;
    string title, col1, col2, data;
    
    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, col1);
    cout << "You entered: " << col1 << endl << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, col2);
    cout << "You entered: " << col2 << endl << endl;

    //The title is right justified with a setw() value of 33. Column 1 has a setw() value of 20. Column 2 has a setw() value of 23. (3 pts)

    outputTable << right << setw(33) << title << endl;
    outputTable << left << setw(20) << col1 << "|" << right << setw(23) << col2 << endl;
    outputTable << string(44, '-') << endl;
    
    while (data != "-1") {
        string uStr;
        int uInt;
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, data);

        if (data == "-1") {
            cout << endl;
            break;
        }

        try {

            if (data.find(',') == string::npos) {
                throw runtime_error("No comma in string.");
            } else if (data.find(',', data.find(',') + 1) != string::npos) {
                throw runtime_error("Too many commas in input.");
            }

            istringstream dataIn(data);
            getline(dataIn, uStr, ',');

            if (!(dataIn >> uInt)) {
                throw runtime_error("Comma not followed by an integer.");
            }

            cout << "Data string: " << uStr << endl;
            cout << "Data integer: " << uInt << endl << endl;

           outputTable << left << setw(20) << uStr << "|" << right << setw(23) << uInt << endl;
           outputHist << right << setw(20) << uStr << " " << left << string(uInt, '*') << endl;
        }
        catch(runtime_error &error){
            cout << "Error: " << error.what() << endl << endl;
        }
    }

    cout << outputTable.str() << endl;
    cout << outputHist.str();
    
    return 0;
}

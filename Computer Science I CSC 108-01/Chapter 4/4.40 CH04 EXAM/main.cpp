/*
Create a program that prompts the user to input a paragraph and a single word, and then searches for or replaces all of the words in the paragraph. If the user selects replace, you will prompt the user for further information about the word to replace in the paragraph. You will continue to prompt the user to input the paragraph and the word to search for or replace until the user enter the 'q' key to exit, at which point your program will terminate and display the message "Program ended," indicating that your software has been terminated.

Running search examples:

    *Enter s for search, r for replace, or q to quit:
    *s
    *Enter a paragraph:
    *To be, or not to be, that is the question.
    *Enter a word to search:
    *be
    *Occurrences of Word = 2
    *Enter s for search, r for replace, or q to quit:
    *s
    *Enter a paragraph:
    *To be, or not to be, that is the question.
    *Enter a word to search:
    *is
    *Occurrences of Word = 1
    *Enter s for search, r for replace, or q to quit:
    *s
    *Enter a paragraph:
    *To be, or not to be, that is the question.
    *Enter a word to search:
    *are
    *Occurrences of Word = 0
    *Enter s for search, r for replace, or q to quit:
    *q
    *Program terminated.

Running replace examples:

    *Enter s for search, r for replace, or q to quit:
    *r
    *Enter a paragraph:
    *To be, or not to be, that is the question.
    *Enter a word to search:
    *be
    *Enter word to replace:
    *is
    *New string: To is, or not to is, that is the question.
    *Occurrences of Word = 2
    *Enter s for search, r for replace, or q to quit:
    *r
    *Enter a paragraph:
    *To be, or not to be, that is the question.
    *Enter a word to search:
    *is
    *Enter word to replace:
    *are
    *New string: To be, or not to be, that are the question.
    *Occurrences of Word = 1
    *Enter s for search, r for replace, or q to quit:
    *r
    *Enter a paragraph:
    *To be, or not to be, that is the question.
    *Enter a word to search:
    *are
    *Enter word to replace:
    *is
    *New string: To be, or not to be, that is the question.
    *Occurrences of Word = 0
    *Enter s for search, r for replace, or q to quit:
    *q
    *Program terminated.

Note 1: Given that vector and array have not been discussed, you are not permitted to include vector or array in your application. Also, zyBooks won't print out the user inputs, you must print out the user inputs.

Notes 2: You must use loops and if statement in your program to get any credits for the exam.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {

    //Declaring variables
    char method;
    string userInput, replace, search;
    bool running = true;

    //Main program loop
    while (running) {
        cout << "Enter s for search, r for replace, or q to quit:" << endl;
        cin >> method;
        cout << method << endl;
        if (method == 's') {
            cout << "Enter a paragraph:" << endl;
            cin.ignore();
            getline(cin, userInput);
            cout << userInput << endl << "Enter a word to search:" << endl;
            cin >> search;
            cout << search << endl;

            //Declaring internal variables
            int found = 0;
            for (int i = 0; i < userInput.length(); ++i) {
                if (userInput.substr(i, search.length()) == search) {
                    found ++;
                }
            }
            cout << "Occurrences of Word = " << found << endl;
        } else if (method == 'r') {
            cout << "Enter a paragraph:" << endl;
            cin.ignore();
            getline(cin, userInput);
            cout << userInput << endl << "Enter a word to search:" << endl;
            cin >> search;
            cout << search << endl << "Enter word to replace:" << endl;
            cin >> replace;
            cout << replace << endl;
        
            //Declaring internal variables
            int found = 0, difference = search.length() - replace.length();
            for (int i = 0; i < userInput.length(); ++i) {
                if (userInput.substr(i, search.length()) == search) {
                    userInput.replace(i, search.length(), replace);
                    i += difference;
                    found ++;
                }
            }
            cout << "New string: " << userInput << endl;
            cout << "Occurrences of Word = " << found << endl;
        } else if (method == 'q') {
            cout << "Program terminated." << endl;
            running = false;
        } else {
            cout << "Invalid Input." << endl;
        }
    }

    return 0;
}
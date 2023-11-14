/*
(1) Prompt the user to enter a string of their choosing. Store the text in a string. Output the string. (1 pt)

Ex:

    *Enter a sample text:
    *We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!

    *You entered: We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!

(2) Implement the PrintMenu() function to print the following command menu. (1 pt)

Ex:

    *MENU
    *c - Number of non-whitespace characters
    *w - Number of words
    *f - Find text
    *r - Replace all !'s
    *s - Shorten spaces
    *q - Quit

(3) Implement the ExecuteMenu() function that takes 2 parameters: a character representing the user's choice and the user provided sample text. ExecuteMenu() performs the menu options, according to the user's choice, by calling the appropriate functions described below. (1 pt)


(4) In the main() function, call PrintMenu() and prompt for the user's choice of menu options for analyzing/editing the string. Each option is represented by a single character.

If an invalid character is entered, continue to prompt for a valid choice. When a valid option is entered, execute the option by calling ExecuteMenu(). Then, print the menu, and prompt for a new option. Continue until the user enters 'q'. Hint: Implement Quit before implementing other options. (1 pt)

Ex:

    *MENU
    *c - Number of non-whitespace characters
    *w - Number of words
    *f - Find text
    *r - Replace all !'s
    *s - Shorten spaces
    *q - Quit
    *
    *Choose an option:

(5) Implement the GetNumOfNonWSCharacters() function. GetNumOfNonWSCharacters() has a constant string as a parameter and returns the number of characters in the string, excluding all whitespace. Call GetNumOfNonWSCharacters() in the ExecuteMenu() function, and then output the returned value. (4 pts)

Ex:

    *Enter a sample text:
    *We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing    *ends here;  our hopes and our journeys continue!
    *
    *You entered: We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue!
    *
    *MENU
    *c - Number of non-whitespace characters
    *w - Number of words
    *f - Find text
    *r - Replace all !'s
    *s - Shorten spaces
    *q - Quit
    *
    *Choose an option:
    *c
    *Number of non-whitespace characters: 181

(6) Implement the GetNumOfWords() function. GetNumOfWords() has a constant string as a parameter and returns the number of words in the string. Hint: Words end when a space is reached except for the last word in a sentence. Call GetNumOfWords() in the ExecuteMenu() function, and then output the returned value. (3 pts)

Ex:

    *Number of words: 35

(7) Implement the FindText() function, which has two strings as parameters. The first parameter is the text to be found in the user provided sample text, and the second parameter is the user provided sample text. The function returns the number of instances a word or phrase is found in the string. In the ExecuteMenu() function, prompt the user for a word or phrase to be found. Then call FindText() and output the returned value. Before the prompt, call cin.ignore() to allow the user to input a new string.(3 pts)

Ex:

    *Enter a word or phrase to be found:
    *more
    *"more" instances: 5

(8) Implement the ReplaceExclamation() function. ReplaceExclamation() has a string parameter and updates the string by replacing each '!' character in the string with a '.' character. ReplaceExclamation() DOES NOT output the string. Call ReplaceExclamation() in the ExecuteMenu() function, and then output the edited string. (3 pts)

Ex.

    *Edited text: We'll continue our quest in space.  There will be more shuttle flights and more shuttle crews and,  yes,  more volunteers, more civilians,  more teachers in space.  Nothing ends here;  our hopes and our journeys continue.

(9) Implement the ShortenSpace() function. ShortenSpace() has a string parameter and updates the string by replacing all sequences of 2 or more spaces with a single space. ShortenSpace() DOES NOT output the string. Call ShortenSpace() in the ExecuteMenu() function, and then output the edited string. (3 pt)

Ex:

    *Edited text: We'll continue our quest in space. There will be more shuttle flights and more shuttle crews and, yes, more volunteers, more civilians, more teachers in space. Nothing ends here; our hopes and our journeys continue!

*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void PrintMenu() {
    cout << "MENU\nc - Number of non-whitespace characters\nw - Number of words\nf - Find text\nr - Replace all !\'s\ns - Shorten spaces\nq - Quit\n" << endl;
}

int GetNumOfNonWSCharacters(const string userValue) {
    int nonSpace = 0;
    for (size_t i = 0; i < userValue.length(); ++i) {
        if (userValue[i] != ' ' && userValue[i] != '\t') {
            nonSpace++;
        }
    }
    return nonSpace;
}

int GetNumOfWords(const string userValue) {
    int numWord = 0;
    for (size_t i = 0; i < userValue.length(); ++i) {
        if (userValue[i] == ' ' && userValue[i + 1] != ' ') {
            numWord++;
        }
    }
    return numWord + 1;
}

int FindText(const string findMe, const string userValue) {
    int textOccurrence = 0;
    for (size_t i = 0; i < userValue.length(); ++i) {
        if (userValue[i] == findMe[0]) {
            bool same = true;
            int mainCharPos = i;
            size_t findCharPos = 0;
            while (same) {
                if (findCharPos + 1 == findMe.length()) {
                    textOccurrence++;
                    same = false;
                } else if (userValue[mainCharPos] != findMe[findCharPos]) {
                    same = false;
                }
                mainCharPos++;
                findCharPos++;
            }
        }
    }
    return textOccurrence;
}

void ReplaceExclamation(string& userValue) {
    for (size_t i = 0; i < userValue.length(); ++i) {
        if (userValue[i] == '!') {
            userValue.replace(i, 1, ".");
        }
    }
}

void ShortenSpace(string& userValue) {
    for (size_t i = 0; i < userValue.length(); ++i) {
        if (userValue[i] == ' ' && (userValue[i + 1] == ' ')) {
            int replace = 0;
            size_t test = i;
            bool space = true;
            while (space) {
                if (userValue[test] == ' ') {
                    replace++;
                } else {
                    space = false;
                }
                test ++;
            }
            userValue.replace(i, replace, " ");
        }
    }
}

void ExecuteMenu(char choice, string& userIn) {
    string uIn2;
    switch (choice) {
        case 'c':
            cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userIn) << endl << endl;
            break;
        case 'w':
            cout << "Number of words: " << GetNumOfWords(userIn) << endl << endl;
            break;
        case 'f':
            cout << "Enter a word or phrase to be found:" << endl;
            cin.ignore();
            getline(cin, uIn2);
            cout << "\"" << uIn2 << "\" instances: " << FindText(uIn2, userIn) << endl << endl;
            break;
        case 'r':
            ReplaceExclamation(userIn);
            cout << endl << "Edited text: " << userIn << endl << endl;
            break;
        case 's':
            ShortenSpace(userIn);
            cout << endl << "Edited text: " << userIn << endl << endl;
            break;
        default:
            cout << "Invalid Option" << endl;
            break;
        }
}

int main() {

    //Declaring variables
    string uIn;
    bool running = true;

    //Getting user input
    cout << "Enter a sample text:" << endl;
    getline(cin, uIn);

    //Using user input
    cout << endl << "You entered: " << uIn << endl << endl;
    while (running == true) {
        char uChoice;
        PrintMenu();
        cout << "Choose an option:" << endl;
        cin >> uChoice;
        if (uChoice == 'q') {
            running = false;
        } else {
            ExecuteMenu(uChoice, uIn);
        }
    }

    return 0;
}
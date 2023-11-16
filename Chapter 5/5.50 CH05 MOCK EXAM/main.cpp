/*
Create a program that prompts the user to input a paragraph and a single word, and then searches for or replaces all of the words in the paragraph. If the user selects replace, you will prompt the user for further information about the word to replace in the paragraph. You will continue to prompt the user to input the paragraph and the word to search for or replace until the user enter the 'q' key to exit, at which point your program will terminate and display the message "Program ended," indicating that your software has been terminated.

    1. Write a search function that takes in a sentence string and a search string. If the search string exists in the sentence string, then return the number of occurrences of the search string in the sentence.

    2. Write a replace function that takes in a sentence string by reference, a search string, and a replace string. If the search string exists in the sentence string, replace the string in the sentence, then return the count and update the sentence string with the new changes.

    3. Write an inputOutput function that takes no input and returns nothing. Ask the user whether they want to search for or replace a string, and print out the result after performing the function.

    4. write 5 unit testing for the search and the replace functions in the main function. Running search examples:

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
#include <cassert>

using namespace std;

int search(string userInput, string search) {
    //Declaring internal variables
    int found = 0;
    for (size_t i = 0; i < userInput.length(); ++i) {
        if (userInput.substr(i, search.length()) == search) {
            found ++;
        }
    }
    return found;
}

int replace(string& userInput, string search, string replace) {    
    //Declaring internal variables
    int found = 0, difference = search.length() - replace.length();
    for (size_t i = 0; i < userInput.length(); ++i) {
        if (userInput.substr(i, search.length()) == search) {
            userInput.replace(i, search.length(), replace);
            i += difference;
            found ++;
        }
    }
    return found;
}

void InputOutput() {
    
    //Declaring variables
    int occur;
    char method;
    bool running = true;
    string userInput, toReplace, toSearch;

    while(running) {
        cout << "Enter s for search, r for replace, or q to quit:" << endl;
        cin >> method;
        cout << method << endl;
        switch (method){
            case 's':
                cout << "Enter a paragraph:" << endl;
                cin.ignore();
                getline(cin, userInput);
                cout << userInput << endl << "Enter a word to search:" << endl;
                cin >> toSearch;
                cout << toSearch << endl;
                cout << "Occurrences of Word = " << search(userInput, toSearch) << endl;
                break;
            case 'r':
                cout << "Enter a paragraph:" << endl;
                cin.ignore();
                getline(cin, userInput);
                cout << userInput << endl << "Enter a word to search:" << endl;
                cin >> toSearch;
                cout << toSearch << endl << "Enter word to replace:" << endl;
                cin >> toReplace;
                cout << toReplace << endl;
                occur = replace(userInput, toSearch, toReplace);
                cout << "New string: " << userInput << endl;
                cout << "Occurrences of Word = " << occur << endl;
                break;
            case 'q':
                cout << "Program terminated." << endl;
                running = false;
                break;
            default:
                cout << "Invalid Input." << endl;
                break;
        }
    }

}

int main() {
    
    InputOutput();

    assert(search("To be or not to be.", "be") == 2);
    assert(search("To be or not to be.", "or") == 1);
    assert(search("Hellohello world", "hello") == 1);
    assert(search("Testing this program program program...", "program") == 3);
    assert(search("This is a question!", "question") == 1);


    string test1 = "To be or not to be.", test2 = "Hellohello world", test3 = "We are testing this now.", test4 = "I don't know what else to try here.";
    assert(replace(test1, "be", "is") == 2);
    assert(replace(test1, "or", "testing") == 1);
    assert(replace(test2, "hello", "test") == 1);
    assert(replace(test3, "testing", "a") == 1);
    assert(replace(test4, "else", "aaaaaaaaaaaaaaaaaaaaaa") == 1);

    return 0;
}
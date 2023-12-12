/*
Define a function named GetWordFrequency that takes a vector of strings and a search word as parameters. Function GetWordFrequency() then returns the number of occurrences of the search word in the vector parameter (case insensitive).

Then, write a main program that reads a list of words into a vector, calls function GetWordFrequency() repeatedly, and outputs the words in the vector with their frequencies. The input begins with an integer indicating the number of words that follow.

Ex: If the input is:

    *5 hey Hi Mark hi mark

the output is:

    *hey 1
    *Hi 2
    *Mark 2
    *hi 2
    *mark 2

Hint: Use tolower() to set the first letter of each word to lowercase before comparing.

The program must define and use the following function:
int GetWordFrequency(vector<string> wordsList, string currWord)
*/
#include <iostream>
#include <vector> 
#include <string>
#include <cctype>
using namespace std;

int GetWordFrequency(vector<string> wordsList, string currWord) {
    int temp = 0;
    char lower = tolower(currWord[0]);
    string lowerCurrWord = "";
    lowerCurrWord += lower;
    lowerCurrWord += currWord.substr(1);
    for (size_t i = 0; i < wordsList.size(); ++i) {
        string tempStr = "";
        char tempLower = tolower(wordsList.at(i)[0]);
        tempStr += tempLower;
        tempStr += wordsList.at(i).substr(1);

        if (tempStr == lowerCurrWord) {
            temp++;
        }
    }

    return temp;
}

int main() {
    
    //Declaring variables
    int N;
    vector<string> words;

    //Getting user input
    cin >> N;
    words.resize(N);

    //Filling vector
    for (size_t i = 0; i < words.size(); ++i) {
        cin >> words.at(i);
    }

    //Outputting result
    for (size_t i = 0; i < words.size(); ++i) {
        cout << words.at(i) << " " << GetWordFrequency(words, words.at(i)) << endl;
    }

    return 0;
}
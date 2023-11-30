/*
Write a program that reads a list of words. Then, the program outputs those words and their frequencies. The input begins with an integer indicating the number of words that follow. Assume that the list will always contain fewer than 20 words.

Ex: If the input is:

    *5 hey hi Mark hi mark

the output is:

    *hey - 1
    *hi - 2
    *Mark - 1
    *hi - 2
    *mark - 1

Hint: Use two vectors, one vector for the strings and one vector for the frequencies.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    //Declaring variables
    int N;
    vector<string> words;
    vector<int> frequency;

    //Getting user input
    cin >> N;

    //Setting size of vectors
    words.resize(N);
    frequency.resize(N);

    //Getting user input for words
    for (int i = 0; i < N; ++i) {
        string tempIn;
        cin >> tempIn;
        words.at(i) = tempIn;
    }

    //Checking frequencies
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (words.at(i) == words.at(j)) {
                frequency.at(i) = frequency.at(i) + 1;
            }
        }
    }

    //Outputting words and frequencies
    for (int i = 0; i < N; ++i) {
        cout << words.at(i) << " - " << frequency.at(i) << endl;
    }

    return 0;
}
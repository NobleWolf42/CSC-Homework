/*
A contact list is a place where you can store a specific contact with other associated information such as a phone number, email address, birthday, etc. Write a program that first takes as input an integer N that represents the number of word pairs in the list to follow. Word pairs consist of a name and a phone number (both strings), separated by a comma. That list is followed by a name, and your program should output the phone number associated with that name. Output "None" if name is not found.

Ex: If the input is:

    *3 Joe,123-5432 Linda,983-4123 Frank,867-5309 Frank

the output is:

    *867-5309

Your program must define and call the following function. The return value of GetPhoneNumber is the phone number associated with the specific contact name.
string GetPhoneNumber(vector<string> nameVec, vector<string> phoneNumberVec, string contactName)

Hint: Use two vectors: One for the string names, and the other for the string phone numbers.
*/
#include <iostream>
#include <vector>
using namespace std;

string GetPhoneNumber(vector<string> nameVec, vector<string> phoneNumberVec, string contactName) {
    string output;
    for (size_t i = 0; i < nameVec.size(); ++i) {
        if (nameVec.at(i) == contactName) {
            return phoneNumberVec.at(i);
        }
    }
    return "None";
}

int main() {
    
    //Declaring variable
    int N;
    string search;
    vector<string> names;
    vector<string> numbers;

    //Getting user input
    cin >> N;
    names.resize(N);
    numbers.resize(N);

    //Filling vectors
    for (size_t i = 0; i < names.size(); ++i) {
        string tempIn;
        cin >> tempIn;
        names.at(i) = tempIn.substr(0, tempIn.find(','));
        numbers.at(i) = tempIn.substr(tempIn.find(',') + 1);
    }

    //Getting search term
    cin >> search;

    //Outputting results
    cout << GetPhoneNumber(names, numbers, search) << endl;


    return 0;
}
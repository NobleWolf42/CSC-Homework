/*
Write a program that takes user input describing a playing card in the following shorthand notation:

    *A Ace
    *2 ... 10 Card values
    *J Jack
    *Q Queen
    *K King
    *D Diamonds
    *H Hearts
    *S Spades
    *C Clubs

Your program should print the full description of the card. For example, (User input in bold)

    *Enter the card notation: <b>QS</b>
    *Queen of spades
*/
#include <iostream>
#include <string>
using namespace std;
int main() {

    //Declaring variables
    string card, value_code, suit_code, value, suit;
    
    //Getting user input
    cout << "Enter the notation for the card: ";
    getline(cin, card);
    
    //Splitting up user input
    if (card.length() == 3) {
        value_code = card.substr(0, 2);
        suit_code = card.substr(2, 1);
    } else {
        value_code = card.substr(0, 1);
        suit_code = card.substr(1, 1);
    }

    //Getting card value
    if (value_code == "A") {
        value = "Ace";
    } else if (value_code == "K") {
        value = "King";
    } else if  (value_code == "Q") {
        value = "Queen";
    } else if  (value_code == "J") {
        value = "Jack";
    } else {
        value = value_code;
    }
   
    if (suit_code == "H") {
        suit = "Hearts";
    } else if (suit_code == "D") {
        suit = "Diamonds";
    } else if (suit_code == "S") {
        suit = "Spades";
    } else {
        suit = "Clubs";
    }

    cout << "That card is the " << value << " of " << suit << "\n";
    return 0;
}
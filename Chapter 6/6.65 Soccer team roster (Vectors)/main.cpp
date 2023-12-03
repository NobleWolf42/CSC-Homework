/*
This program will store roster and rating information for a soccer team. Coaches rate players during tryouts to ensure a balanced team.

(1) Prompt the user to input five pairs of numbers: A player's jersey number (0 - 99) and the player's rating (1 - 9). Store the jersey numbers in one int vector and the ratings in another int vector. Output these vectors (i.e., output the roster). (3 pts)

Ex:

    *Enter player 1's jersey number:
    *84
    *Enter player 1's rating:
    *7
    *
    *Enter player 2's jersey number:
    *23
    *Enter player 2's rating:
    *4
    *
    *Enter player 3's jersey number:
    *4
    *Enter player 3's rating:
    *5
    *
    *Enter player 4's jersey number:
    *30
    *Enter player 4's rating:
    *2
    *
    *Enter player 5's jersey number:
    *66
    *Enter player 5's rating:
    *9
    *
    *ROSTER
    *Player 1 -- Jersey number: 84, Rating: 7
    *Player 2 -- Jersey number: 23, Rating: 4
    *...

(2) Implement a menu of options for a user to modify the roster. Each option is represented by a single character. The program initially outputs the menu, and outputs the menu after a user chooses an option. The program ends when the user chooses the option to Quit. For this step, the other options do nothing. (2 pts)

Ex:

    *MENU
    *a - Add player
    *d - Remove player
    *u - Update player rating
    *r - Output players above a rating
    *o - Output roster
    *q - Quit
    *
    *Choose an option:

(3) Implement the "Output roster" menu option. (1 pt)

Ex:

    *ROSTER
    *Player 1 -- Jersey number: 84, Rating: 7
    *Player 2 -- Jersey number: 23, Rating: 4
    *...
    
(4) Implement the "Add player" menu option. Prompt the user for a new player's jersey number and rating. Append the values to the two vectors. (1 pt)

Ex:

    *Enter a new player's jersey number:
    *49
    *Enter the player's rating:
    *8

(5) Implement the "Delete player" menu option. Prompt the user for a player's jersey number. Remove the player from the roster (delete the jersey number and rating). (2 pts)

Ex:

    *Enter a jersey number:
    *4

(6) Implement the "Update player rating" menu option. Prompt the user for a player's jersey number. Prompt again for a new rating for the player, and then change that player's rating. (1 pt)

Ex:

    *Enter a jersey number:
    *23
    *Enter a new rating for player:
    *6

(7) Implement the "Output players above a rating" menu option. Prompt the user for a rating. Print the jersey number and rating for all players with ratings above the entered value. (2 pts)

Ex:

    *Enter a rating:
    *5

    *ABOVE 5
    *Player 1 -- Jersey number: 84, Rating: 7
    *...

*/

#include <iostream>
#include <vector>
using namespace std;

void printRoster(vector<int> jersey, vector<int> rating) {
    cout << "ROSTER" << endl;
    for (size_t i = 0; i < jersey.size(); ++i) {
        cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
    }
    cout << endl;
}

void printMenu() {
    cout << "MENU" << endl << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
}

void addPlayer(vector<int> &jersey, vector<int> &rating) {
    int tempInt1, tempInt2;
    cout << "Enter a new player's jersey number:" << endl;
    cin >> tempInt1;
    cout << "Enter the player's rating:" << endl;
    cin >> tempInt2;
    jersey.push_back(tempInt1);
    rating.push_back(tempInt2);
    cout << endl;
}

void removePlayer(vector<int> &jersey, vector<int> &rating) {
    int tempInt1, toDelete = -1;
    cout << "Enter a jersey number:" << endl;
    cin >> tempInt1;
    for (size_t i = 0; i < jersey.size(); ++i) {
        if (jersey.at(i) == tempInt1) {
            toDelete = i;
        }
    }
    jersey.erase(jersey.begin() + toDelete);
    rating.erase(rating.begin() + toDelete);
}

void updatePlayer(vector<int> &jersey, vector<int> &rating) {
    int tempInt1, tempInt2;
    cout << "Enter a jersey number:" << endl;
    cin >> tempInt1;
    cout << "Enter a new rating for player:" << endl;
    cin >> tempInt2;
    for (size_t i = 0; i < jersey.size(); ++i) {
        if (jersey.at(i) == tempInt1) {
            rating.at(i) = tempInt2;
        }
    }
}

void filterByRating(vector<int> &jersey, vector<int> &rating) {
    int tempInt1;
    cout << "Enter a rating:" << endl;
    cin >> tempInt1;
    cout << "ABOVE " << tempInt1 << endl;
    for (size_t i = 0; i < jersey.size(); ++i) {
        if (rating.at(i) > tempInt1) {
            cout << "Player " << i + 1 << " -- Jersey number: " << jersey.at(i) << ", Rating: " << rating.at(i) << endl;
        }
    }
    cout << endl;
}

void executeMenu(char choice, vector<int> &jersey, vector<int> &rating) {
    switch (choice) {
        case 'o':
            printRoster(jersey, rating);
            break;
        case 'a':
            addPlayer(jersey, rating);
            break;
        case 'd':
            removePlayer(jersey, rating);
            break;
        case 'u':
            updatePlayer(jersey, rating);
            break;
        case 'r':
            filterByRating(jersey, rating);
            break;
        default:
            break;
    }
}

int main() {

    //Declaring variables
    int N = 5;
    bool running = true;
    vector<int> jersey(N);
    vector<int> rating(N);

    //Getting user input
    for (int i = 0; i < N; ++i) {
        cout << "Enter player " << i + 1 <<"'s jersey number:" << endl;
        cin >> jersey.at(i);
        cout << "Enter player " << i + 1 << "'s rating:" << endl;
        cin >> rating.at(i);
        cout << endl;
    }

    //Outputting roster
    printRoster(jersey, rating);

    //Printing Menu
    while (running) {
        char choice;
        printMenu();
        cin >> choice;
        switch (choice) {
            case 'q':
                running = false;
                break;
            default:
                executeMenu(choice, jersey, rating);
                break;
        }
    }

    return 0;
}
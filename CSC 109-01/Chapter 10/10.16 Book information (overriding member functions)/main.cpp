/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Given main() and a base Book class, define a derived class called Encyclopedia with member functions to get and set private class data members of the following types:

    - string to store the edition
    - int to store the number of pages

Within the derived Encyclopedia class, define a PrintInfo() member function that overrides the Book class' PrintInfo() function by printing the title, author, publisher, publication date, edition, and number of pages.

Ex. If the input is:

    *The Hobbit
    *J. R. R. Tolkien
    *George Allen & Unwin
    *21 September 1937
    *The Illustrated Encyclopedia of the Universe
    *Ian Ridpath
    *Watson-Guptill
    *2001
    *2nd
    *384

the output is:

    *Book Information: 
    *   Book Title: The Hobbit
    *   Author: J. R. R. Tolkien
    *   Publisher: George Allen & Unwin
    *   Publication Date: 21 September 1937
    *Book Information: 
    *   Book Title: The Illustrated Encyclopedia of the Universe
    *   Author: Ian Ridpath
    *   Publisher: Watson-Guptill
    *   Publication Date: 2001
    *   Edition: 2nd
    *   Number of Pages: 384

Note: Indentations use 3 spaces.
*/

#include "Book.h"
#include "Encyclopedia.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Book myBook;
    Encyclopedia myEncyclopedia;

    string title, author, publisher, publicationDate;
    string eTitle, eAuthor, ePublisher, ePublicationDate, edition;
    int numPages;

    getline(cin, title);
    getline(cin, author);
    getline(cin, publisher);
    getline(cin, publicationDate);

    getline(cin, eTitle);
    getline(cin, eAuthor);
    getline(cin, ePublisher);
    getline(cin, ePublicationDate);
    getline(cin, edition);
    cin >> numPages;

    myBook.SetTitle(title);
    myBook.SetAuthor(author);
    myBook.SetPublisher(publisher);
    myBook.SetPublicationDate(publicationDate);
    myBook.PrintInfo();

    myEncyclopedia.SetTitle(eTitle);
    myEncyclopedia.SetAuthor(eAuthor);
    myEncyclopedia.SetPublisher(ePublisher);
    myEncyclopedia.SetPublicationDate(ePublicationDate);
    myEncyclopedia.SetEdition(edition);
    myEncyclopedia.SetNumPages(numPages);
    myEncyclopedia.PrintInfo();

    return 0;
}

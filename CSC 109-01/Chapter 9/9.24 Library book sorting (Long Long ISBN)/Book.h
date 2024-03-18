/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef BOOKH
#define BOOKH

#include <string>
using std::string;

class Book{
    public:
        Book();

        Book(string userBookTitle, string userBookAuthor, long long userBookISBN);

        long long GetBookISBN() const;

        void PrintInfo() const;
   
    private:
        string bookTitle;
        string bookAuthor;
        long long bookISBN;
};

#endif

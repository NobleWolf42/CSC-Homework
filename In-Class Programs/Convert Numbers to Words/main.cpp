#include <iostream>
#include <cassert>

void UserInputOutput();

using namespace std;

//string &getString(size_t num, size_t count, string &numstr, int tdigit);

string spellDigit(size_t d) {
    string numstr = "";
    switch (d) {
        case 0:
            numstr = "zero";
            break;
        case 1:
            numstr = "one";
            break;
        case 2:
            numstr = "two";
            break;
        case 3:
            numstr = "three";
            break;
        case 4:
            numstr = "four";
            break;
        case 5:
            numstr = "five";
            break;
        case 6:
            numstr = "six";
            break;
        case 7:
            numstr = "seven";
            break;
        case 8:
            numstr = "eight";
            break;
        case 9:
            numstr = "nine";
            break;

    }
    return numstr;
}

string spellTenth(size_t d2, size_t d1) {
    string numstr = "";
    switch (d2) {
        case 0:
            numstr = spellDigit(d1);
            break;
        case 1:
            switch (d1) {
                case 0:
                    numstr = "ten";
                    break;
                case 1:
                    numstr = "eleven";
                    break;
                case 2:
                    numstr = "twelve";
                    break;
                case 3:
                    numstr = "thirteen";
                    break;
                case 4:
                    numstr = "fourteen";
                    break;
                case 5:
                    numstr = "fifteen";
                    break;
                case 6:
                    numstr = "sixteen";
                    break;
                case 7:
                    numstr = "seventeen";
                    break;
                case 8:
                    numstr = "eighteen";
                    break;
                case 9:
                    numstr = "nineteen";
                    break;
                default:
                    numstr = "invalid digit";
            }

            break;
        case 2:
            numstr = "twenty";
            if (d1 > 0) {
                numstr = "twenty";
                numstr = numstr + " " + spellDigit(d1);
            }

            break;
        case 3:
            numstr = "thirty";
            if (d1 > 0) {
                numstr = "thirty";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        case 4:
            numstr = "forty";
            if (d1 > 0) {
                numstr = "forty";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        case 5:
            numstr = "fifty";
            if (d1 > 0) {
                numstr = "fifty";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        case 6:
            numstr = "sixty";
            if (d1 > 0) {
                numstr = "sixty";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        case 7:
            numstr = "seventy";
            if (d1 > 0) {
                numstr = "seventy";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        case 8:
            numstr = "eighty";
            if (d1 > 0) {
                numstr = "eighty";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        case 9:
            numstr = "ninety";
            if (d1 > 0) {
                numstr = "ninety";
                numstr = numstr + " " + spellDigit(d1);
            }
            break;
        default:
            numstr = "invalid digit";
    }
    return numstr;
}

string spell3Digits(int num) {
    size_t count = 0;
    string numstr = "";
    size_t d0;
    while (num > 0) {
        size_t digit = num % 10;
        // cout << digit << endl;

        if (count == 0) {
            numstr = spellDigit(digit);
        } else if (count == 1) {
            numstr = spellTenth(digit, d0);
        } else if (count == 2) {
            if (digit > 0) {
                if (numstr == "zero") {
                    numstr = spellDigit(digit) + " hundred ";
                } else {
                    numstr = spellDigit(digit) + " hundred " + numstr;
                }

            }
        }

        // cout << numstr << " " << count << endl;
        count++;
        d0 = digit;
        num = num / 10;  // get rid of one digit
    }
    return numstr;
}

string &getString(size_t num, size_t count, string &numstr, int tdigit) {
    switch (count) {
        case 0:
            numstr = spell3Digits(num % 1000);
            break;
        case 1:
            tdigit = num % 1000;
            if (tdigit > 0) {
                numstr = spell3Digits(num % 1000) + " thousand " + numstr;
            }
            break;
        case 2:
            tdigit = num % 1000;
            if (tdigit > 0) {
                numstr = spell3Digits(num % 1000) + " million " + numstr;
            }
            break;
        case 3:
            tdigit = num % 1000;
            if (tdigit > 0) {
                numstr = spell3Digits(num % 1000) + " billion " + numstr;
            }

            break;
    }
    return numstr;
}

int main() {
    UserInputOutput();


    assert(spellDigit(0) == "zero");
    assert(spellDigit(1) == "one");
    assert(spellDigit(2) == "two");
    assert(spellDigit(3) == "three");
    assert(spellDigit(4) == "four");
    assert(spellDigit(5) == "five");
    assert(spellDigit(6) == "six");
    assert(spellDigit(7) == "seven");
    assert(spellDigit(8) == "eight");
    assert(spellDigit(9) == "nine");

    assert(spellTenth(1, 0) == "ten");
    assert(spellTenth(1, 1) == "eleven");
    assert(spellTenth(1, 2) == "twelve");
    assert(spellTenth(1, 3) == "thirteen");
    assert(spellTenth(1, 4) == "fourteen");
    assert(spellTenth(1, 5) == "fifteen");
    assert(spellTenth(1, 6) == "sixteen");
    assert(spellTenth(1, 7) == "seventeen");
    assert(spellTenth(1, 8) == "eighteen");
    assert(spellTenth(1, 9) == "nineteen");

    assert(spellTenth(2, 0) == "twenty");
    assert(spellTenth(3, 0) == "thirty");
    assert(spellTenth(4, 0) == "forty");
    assert(spellTenth(5, 0) == "fifty");
    assert(spellTenth(6, 0) == "sixty");
    assert(spellTenth(7, 0) == "seventy");
    assert(spellTenth(8, 0) == "eighty");
    assert(spellTenth(9, 0) == "ninety");

    assert(spellTenth(2, 1) == "twenty one");
    assert(spellTenth(3, 2) == "thirty two");
    assert(spellTenth(4, 3) == "forty three");
    assert(spellTenth(5, 4) == "fifty four");
    assert(spellTenth(6, 5) == "sixty five");
    assert(spellTenth(7, 6) == "seventy six");
    assert(spellTenth(8, 7) == "eighty seven");
    assert(spellTenth(9, 8) == "ninety eight");

    assert(spell3Digits(100) == "one hundred");
    assert(spell3Digits(200) == "two hundred");
    assert(spell3Digits(300) == "three hundred");
    assert(spell3Digits(400) == "four hundred");
    assert(spell3Digits(500) == "five hundred");
    assert(spell3Digits(600) == "six hundred");
    assert(spell3Digits(700) == "seven hundred");
    assert(spell3Digits(800) == "eight hundred");
    assert(spell3Digits(900) == "nine hundred");

    assert(spell3Digits(111) == "one hundred eleven");
    assert(spell3Digits(222) == "two hundred twenty two");
    assert(spell3Digits(333) == "three hundred thirty three");
    assert(spell3Digits(444) == "four hundred forty four");
    assert(spell3Digits(555) == "five hundred fifty five");
    assert(spell3Digits(666) == "six hundred sixty six");
    assert(spell3Digits(777) == "seven hundred seventy seven");
    assert(spell3Digits(888) == "eight hundred eighty eight");
    assert(spell3Digits(999) == "nine hundred ninety nine");

    return 0;
}

void UserInputOutput() {
    cout << "Enter a number:" << endl;
    size_t num;
    cin >> num;
    size_t count = 0;
    string numstr = "";
    int tdigit = 0;
    while (num > 0) {
        numstr = getString(num, count, numstr, tdigit);
        count++;
        num = num / 1000;
    }
    cout << numstr << endl;
}
/*
Write a unit conversion program using the conversion factors of Table 2 in Chapter 2. Ask the users from which unit they want to convert (fl. oz, gal, oz, lb, in, ft, mi) and which unit they want to convert to (ml, l, g, kg, mm, cm, m, km). Reject incompatible conversions (such as gal → km). Ask for the value to be converted; then display the result: (User input in bold)

    *Convert from? <b>gal</b>
    *Convert to? <b>ml</b>
    *Value? <b>2.5</b>
    *2.5 gal = 9462.5 ml
*/
#include <iostream>
#include <string>
using namespace std;
int main() {  
    
    //Declaring constants
    const double floz_ml = 29.5735;
    const double gal_ml = 3785.41;
    const double oz_g = 28.3495;
    const double lb_g = 453.592;
    const double in_mm = 25.4;
    const double ft_mm = 304.8;
    const double mi_mm = 1609000;

    //Declaring variables
    string from, to, value, cfactor;
    
    //Getting user input
    cout <<  "Convert from? (fl.oz, gal, oz, lb, in, ft, mi) ";
    cin >> from;
    cout <<  "Convert to? (ml, l, g, kg, mm, cm, m, km) ";
    cin >> to;
    cout <<  "Value?: ";
    cin >> value;
    cfactor = 0.0;
          
    // TODO Determine cfactor from the conversion table
   
   
   
   
   
   
   
    if (cfactor == 0.0) {
        cout << "Requested conversion " << from << " -> " << to << " is not available.\n";
    } else {  
        double converted = value * cfactor;
        cout <<  value << " " << from << " = " << converted << " " << to << "\n";
    }
    return 0;
}

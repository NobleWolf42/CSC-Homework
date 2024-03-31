/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef DATE_H
#define DATE_H
/**
   A class that describe a date 
*/
class Date
{
public:
   /*
      Constructs a date object that is set to 
      the date at which the constructor executes.
    */
   Date();
   /* Constructs a date.
      @param y the year
      @param m the month
      @param d the day
    * 
    */
   Date(int y, int m, int d);
   /*
    * return the year
    */
   int get_year() const;
   /*
    * return the month
    */
   int get_month() const;
   /*
    * return the day
    */
   int get_day() const;
   /*
    compare this date with other date
    */
   bool operator==(Date other) const;
   
private:
   int day;  
   int month;
   int year;
};


#endif /* DATE_H */


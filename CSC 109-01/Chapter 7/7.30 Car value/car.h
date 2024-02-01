/*
Copyright 2024
Author: Ben Carpenter
*/
#ifndef CARH
#define CARH

class Car {
    private:
        int modelYear; 
        int purchasePrice;
        double currentValue;
   
    public:
        void SetModelYear(int userYear);

        int GetModelYear() const;
   
        void SetPurchasePrice(int cost);
   
        int GetPurchasePrice() const;
   
        void CalcCurrentValue(int currentYear);

        int GetCurrentValue() const;
   
        void PrintInfo();
   
};

#endif

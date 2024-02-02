/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>

class ItemToPurchase{
    private:
        std::string itemName;
        int itemPrice;
        int itemQuantity;

    public:
        ItemToPurchase();

        void SetName(std::string itemName);
        
        void SetPrice(int itemPrice);

        void SetQuantity(int itemQuantity);

        std::string GetName() const;

        int GetPrice() const;

        int GetQuantity() const;

};

#endif

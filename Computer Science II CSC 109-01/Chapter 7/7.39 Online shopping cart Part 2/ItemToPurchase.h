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
        std::string itemDescription;
        int itemPrice;
        int itemQuantity;

    public:
        ItemToPurchase();

        explicit ItemToPurchase(std::string name, std::string description = "none", int price = 0, int quantity = 0);

        void SetName(std::string itemName);

        void SetDescription(std::string itemDescription);
        
        void SetPrice(int itemPrice);

        void SetQuantity(int itemQuantity);

        std::string GetName() const;

        std::string GetDescription() const;

        int GetPrice() const;

        int GetQuantity() const;

        void PrintItemCost();

        void PrintItemDescription();

};

#endif

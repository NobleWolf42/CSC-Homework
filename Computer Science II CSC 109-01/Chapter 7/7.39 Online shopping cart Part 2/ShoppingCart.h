/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include "ItemToPurchase.h"

class ShoppingCart{
    private:
        std::string customerName;
        std::string currentDate;
        std::vector<ItemToPurchase> cartItems;

    public:
        ShoppingCart();

        ShoppingCart(std::string name, std::string date);

        void AddItem(ItemToPurchase item1);

        void RemoveItem(std::string name);

        void ModifyItem(ItemToPurchase item1);

        std::string GetCustomerName() const;

        std::string GetDate() const;

        int GetNumItemsInCart();

        int GetCostOfCart();

        void PrintTotal();

        void PrintDescriptions();

};

#endif

/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef CUSTOMERS_H
#define CUSTOMERS_H
#include "Binary_Search_Tree.h"
#include "Customer.h"
#include <iostream>

using std::cout;
using std::endl;

template<typename Item_Type>
class Customers : public Binary_Search_Tree<Item_Type> {
public:

    Customers() : Binary_Search_Tree<Item_Type>() {
    }

    Customers(const Customers& orig) {}

    virtual ~Customers() {}

    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount
    int count_big_limits(double limit) {
        return count_big_limits(*this, limit);
    }

    bool any_over_limit() {
        return any_over_limit(*this);
    }
    
    // increase-limit: BST Natural Number -> BST
    // consumes a BST, a credit card number, and an amount of money. Function finds that
    // card number in the BST and changes that customer's credit limit, adding the amount of money
    // given to the limit. Function returns BST identical except for limit change
    Item_Type* increase_limit(string card_number, double limit_add) {
        BTNode<Item_Type>* node = find_node(this->root, card_number);
        if (node != nullptr) {
            node->data.SetLimit(node->data.GetLimit() + limit_add);
            return &(node->data);
        } else {
            return nullptr;
        }
    }
    
    const Item_Type* find(const string& target) const {
        return find(this->root, target);
    }
    
private: 
    // count-big-limits: BST Number -> Natural
    // consumes a binary search tree and a credit limit amount, produces the number of customers
    // who have a credit limit higher than the given amount    
    int count_big_limits(const Binary_Tree<Item_Type>& the_tree, double limit) {
        if (the_tree.is_null()) {
            return 0;
        } else {
            int count = check_limit(the_tree.get_data(), limit);
            count += count_big_limits(the_tree.get_left_subtree(), limit);
            count += count_big_limits(the_tree.get_right_subtree(), limit);
            return count;
        }
    }

    // check-limit: Number Number -> Natural
    // takes in a customer's credit limit and a given credit limit, returns 1 if the customers's
    // credit limit is higher than the given limit, 0 otherwise.
    int check_limit(Customer data, double limit) {
        if (data.GetLimit() > limit) {
            return 1;
        } else {
            return 0;
        }
    }
    
    // any-over-limit?: BST -> Boolean
    // consumes a binary search tree and produces true if any customer in that tree has exceeded
    // their credit limit with their total purchases (charges)
    bool any_over_limit(const Binary_Tree<Item_Type>& the_tree) {
        
        if (the_tree.is_null()) {
            return false;
        }
        list<Charge> temp = the_tree.get_data().GetCharges();
        if (sum_charges(temp.begin(), temp.end()) > the_tree.get_data().GetLimit()) {
            return true;
        } else {
            return any_over_limit(the_tree.get_left_subtree()) || any_over_limit(the_tree.get_right_subtree());
        }
    }

    // sum-charges: ListOfCharge -> Number
    // consumes a ListOfCharge, produces the sum cost of those charges as a Number
    double sum_charges(list<Charge>::iterator begin, list<Charge>::iterator end) {
        if (begin == end) {
            return 0;
        } else {
            return begin->GetAmount() + sum_charges(++begin, end);
        }
    }

    //added to help find card number, might not be pretty, but it works
    const Item_Type* find(BTNode<Item_Type>* local_root, const string& target) const {
        if (local_root == NULL) {
            return NULL;
        } else if (target < local_root->data.GetCard_number()) {
            return find(local_root->left, target);
        } else if (target > local_root->data.GetCard_number()) {
            return find(local_root->right, target);
        } else {
            return &local_root->data;
        }
    }

    //added to fix an issue with the increase limit function
    BTNode<Item_Type>* find_node(BTNode<Item_Type>* node, const string& target) const {
        if (node == nullptr) {
            return nullptr;
        } else if (node->data.GetCard_number() == target) {
            return node;
        } else if (node->data.GetCard_number() < target) {
            return find_node(node->right, target);
        } else {
            return find_node(node->left, target);
        }
    }

};



#endif /* CUSTOMERS_H */

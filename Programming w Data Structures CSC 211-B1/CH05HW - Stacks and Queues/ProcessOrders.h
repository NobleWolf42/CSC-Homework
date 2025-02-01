/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef PROCESSORDERS_H_
#define PROCESSORDERS_H_

#include <stack>
#include <queue>
#include "Inventory.h"
#include "Order.h"

class ProcessOrders
{
public:

	/** Process new Shipment
	 @param q Quantity of widgets in shipment
	 @param c Cost of the widgets in shipment
	 Also process any un-filled orders in the orders_to_be_filled stack
	 @return total amount that were processed from orders_to_be_filled stack
	 */
	double process_shipment(int q, double c) {
        double done = 0;
        double orderTotal = 0;
        bool InventoryPopped = false;
        std::cout << "Process inventory " << q << std::endl;
        Inventory_on_hand.push(Inventory(q, c));

        if (orders_to_be_filled.empty()) {
            std::cout << std::endl;
            std::cout << q << " items in shipment;" << std::endl;
            std::cout << "shipment pushed into stack" << std::endl;
            std::cout << "items cost $" << c << std::endl;
        }

        while (!orders_to_be_filled.empty() && !Inventory_on_hand.empty()) {
            if (orders_to_be_filled.front().get_quantity() < Inventory_on_hand.top().get_quantity()) {
                
                if (orderTotal == 0) {
                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity() << std::endl;

                    Inventory_on_hand.top().set_quantity(Inventory_on_hand.top().get_quantity() - orders_to_be_filled.front().get_quantity());
                } else {
                    orderTotal += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();

                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << orderTotal << std::endl;

                    Inventory_on_hand.top().set_quantity(Inventory_on_hand.top().get_quantity() - orders_to_be_filled.front().get_quantity());
                }

                done += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();
                orders_to_be_filled.pop();

                orderTotal = 0;

            } else if (orders_to_be_filled.front().get_quantity() == Inventory_on_hand.top().get_quantity()) {

                if (orderTotal == 0) {
                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity() << std::endl;
                } else {
                    orderTotal += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();

                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << orderTotal << std::endl;
                }

                done += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();

                Inventory_on_hand.pop();
                orders_to_be_filled.pop();

                InventoryPopped = true;
                orderTotal = 0;

            } else {
                std::cout << "\n" << "Processed " << Inventory_on_hand.top().get_quantity() << " items for order, obtained from most recent shipment;\nno more items in shipment, removed from stack." << std::endl;
                std::cout << "Cost:" << Inventory_on_hand.top().get_cost() << " Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;

                orderTotal += Inventory_on_hand.top().get_cost() * 1.5 * Inventory_on_hand.top().get_quantity();

                std::cout << "total order: " << orderTotal << std::endl;

                done += Inventory_on_hand.top().get_cost() * 1.5 * Inventory_on_hand.top().get_quantity();
                orders_to_be_filled.front().set_quantity(orders_to_be_filled.front().get_quantity() - Inventory_on_hand.top().get_quantity());

                Inventory_on_hand.pop();
                InventoryPopped = true;
            }
        }

        if (!InventoryPopped) {
            std::cout << "\n" << Inventory_on_hand.top().get_quantity() << " items in shipment;" << std::endl;
            std::cout << "shipment pushed into stack" << std::endl;
            std::cout << "items cost $" << c << std::endl;
        }

        std::cout << "Finished processing new Inventory" << std::endl;
        return done;
    }  // process shipments arrive; return total shipment


	/** Process new Order
	 @param q Quantity of widgets in shipment
	 @return total amount that were processed from orders_to_be_filled stack
	 */
	double process_order(int q) {
        double done = 0;
        double orderTotal = 0;
        std::cout << "Process order " << q << std::endl;
        orders_to_be_filled.push(Order(q));

        while (!Inventory_on_hand.empty() && !orders_to_be_filled.empty()) {
            if (orders_to_be_filled.front().get_quantity() < Inventory_on_hand.top().get_quantity()) {
                
                if (orderTotal == 0) {
                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity() << std::endl;
                } else {
                    orderTotal += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();

                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << orderTotal << std::endl;
                }

                done += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();
                Inventory_on_hand.top().set_quantity(Inventory_on_hand.top().get_quantity() - orders_to_be_filled.front().get_quantity());
                orders_to_be_filled.pop();

                orderTotal = 0;

            } else if (orders_to_be_filled.front().get_quantity() == Inventory_on_hand.top().get_quantity()) {

                if (orderTotal == 0) {
                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity() << std::endl;
                } else {
                    orderTotal += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();

                    std::cout << "\n" << "Processed " << orders_to_be_filled.front().get_quantity() << " items from most recent order;\nOrder processed completely and removed from stack." << std::endl;
                    std::cout << " Cost:" << Inventory_on_hand.top().get_cost() << std::endl;
                    std::cout << "Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                    std::cout << "total order: " << orderTotal << std::endl;
                }

                done += Inventory_on_hand.top().get_cost() * 1.5 * orders_to_be_filled.front().get_quantity();

                Inventory_on_hand.pop();
                orders_to_be_filled.pop();

                orderTotal = 0;

            } else {
                std::cout << "\n" << "Processed " << Inventory_on_hand.top().get_quantity() << " items for order, obtained from most recent shipment;\nno more items in shipment, removed from stack." << std::endl;
                std::cout << "Cost:" << Inventory_on_hand.top().get_cost() << " Selling price: " << Inventory_on_hand.top().get_cost() * 1.5 << std::endl;
                orderTotal += Inventory_on_hand.top().get_cost() * 1.5 * Inventory_on_hand.top().get_quantity();
                std::cout << "total order: " << orderTotal << std::endl;

                done += Inventory_on_hand.top().get_cost() * 1.5 * Inventory_on_hand.top().get_quantity();
                orders_to_be_filled.front().set_quantity(orders_to_be_filled.front().get_quantity() - Inventory_on_hand.top().get_quantity());

                Inventory_on_hand.pop();
            }
        }

        std::cout << "Finished processing new order" << std::endl;
        return done;
    }                // process orders

//	void do_shipment_arrived();					// get inputs from user when the shipments arrive
//	void do_order_arrived();					// get inputs from user when the orders arrive

private:

	std::stack<Inventory> Inventory_on_hand;	// keep track of inventory on hand
	std::queue<Order> orders_to_be_filled;		// keep track of orders

};

#endif /* PROCESSORDERS_H_ */

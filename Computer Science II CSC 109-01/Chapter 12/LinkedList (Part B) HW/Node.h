/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef NODE_H
#define NODE_H

#include <cstddef>

template <typename Item_Type>
class Node {
    public:
    
        // Constructor
        Node() {

        }

        /** Creates a new Node that points to another Node.
            @param data_item The data stored
            @param next_ptr Pointer to the Node that is
                            pointed to by the new Node
         */
        explicit Node(const Item_Type& data_item, Node* next_ptr = NULL) {
            data = data_item;
            next = next_ptr;
        }
    
        // copy constructor
        Node(const Node& orig) {
            data = orig.GetData();
            next = orig.GetNext();
        }
    
        // destructor
        virtual ~Node() {
        } 
    
        // accessor and mutator methods    
        void SetNext(Node* next) {
            this->next = next;
        }

        Node* GetNext() const {
            return next;
        }

        Node*& GetNext() {
            return next;
        }

        void SetData(Item_Type data) {
            this->data = data;
        }

        Item_Type GetData() const {
            return data;
        }

        Item_Type& GetData() {
            return data;
        }
    
    private:
        // Data Fields
        /** The data */
        Item_Type data;
        /** The pointer to the next node. */
        Node* next;
};

#endif /* NODE_H */

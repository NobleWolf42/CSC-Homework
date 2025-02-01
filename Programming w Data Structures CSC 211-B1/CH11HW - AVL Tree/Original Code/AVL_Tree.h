#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "BST_With_Rotate.h"
#include "AVLNode.h"

/** Definition of the AVL Binary Search Tree class.
    @param Item_Type The type of item to be stored in the tree
    Note: Item_Type must define the less-than operator as a 
    total ordering.
*/
template<typename Item_Type>
class AVL_Tree : public BST_With_Rotate<Item_Type> {

public:
    // Constructor
    /** Construct an empty AVL_Tree */
    AVL_Tree() : BST_With_Rotate<Item_Type>() {}

    // Public Member Functions
    /** Insert an item into the tree by calling overridden insert function.
        post: The item is in the tree.
        @param item The item to be inserted
        @return true only if the item was not already in the tree
    */
    virtual bool insert(const Item_Type& item) {
        return insert(this->root, item); }

    /*<exercise chapter="11" type="programming-project" number="5">*/
    /** Remove an item from the tree by calling overridden erase function.
        post: The item is no longer in the tree.
        @param item The item to be removed
        @return true only if the item was in the tree
    */
    virtual bool erase(const Item_Type& item) {
        return erase(this->root, item); }
    /*</exercise>*/
	
	/** Function to verify the structure of the AVL tree.
        @throws Bad_Structure if the structure is invalid
        @returns true if structure is valid.
    */
    bool verify_structure() {
        verify_structure(this->root, 0);
        return true;
    }
	
	

private:

    // Private member functions declarations
    /** Insert an item into the tree. Called by starter function (see
        listing 11.2) with this->root as first argument.
        post: The item is in the tree.
        @param local_root A reference to the current root
        @param item The item to be inserted
        @return true only if the item was not already in the
    */
    virtual bool insert(BTNode<Item_Type>*&, const Item_Type&);

    /** Correct a critical left balance condition
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */
    void rebalance_left(BTNode<Item_Type>*& local_root);

    /** Correct a critical right balance condition
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */
    void rebalance_right(BTNode<Item_Type>*& local_root);

    /*<exercise chapter="11" type="programming-project" number="5">*/
    /** Remove an item from the tree
        @param local_root A reference to the current ro
        @param item The item to be removed
        @return true only if the item was in the tree
        Post: The item is no longer in the tree.
    */
    virtual bool erase(BTNode<Item_Type>*& local_root,
                       const Item_Type& item);

    /** Find a replacement for a node that is being deleted
        This function finds the right-most local root that
        does not have a right child. The data in this local_root
        replaces the data in old_root. The pointer to local_root
        is then saved in old_root and local_root is replaced
        by its left child.
        @param old_root Reference to the pointer to old parent
        @param local_root Reference to the pointer to local root
    */
    virtual void replace_parent(BTNode<Item_Type>*& old_root,
                                BTNode<Item_Type>*& local_root);


    /** Correct a critical left balance condition due to erase
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */
    void erase_rebalance_left(BTNode<Item_Type>*& local_root);

    /** Correct a critical right balance condition due to erase
        pre:  local_root is the root of an AVL subtree that is
        critically heavy.
        post: balance is restored
        @param local_root is the root of the AVL subtree
        that needs rebalancing
    */
    void erase_rebalance_right(BTNode<Item_Type>*& local_root);
    /*</exercise>*/

/** Verify the strucure of the AVL tree
        @throws BadStructure if the structure is invalid
        @param local_root The local root
        @param parent The parent of the local root
        @return The height of the tree
    */
    int verify_structure(BTNode<Item_Type>* local_root,
                         BTNode<Item_Type>* parent);
						 
						 
    // Data Fields
    /** A flag to indicate that the height of the tree has increased */
    bool increase;
    /*<exercise chapter="11" type="programming-project" number="5">*/
    /** A flag to indicate that the height of the tree has decreased */
    bool decrease;
    /*</exercise>*/

}; // End of AVL_Tree class definition

// Implementation of member functions
template<typename Item_Type>
int AVL_Tree<Item_Type>::verify_structure(BTNode<Item_Type>* local_root,
                                          BTNode<Item_Type>* parent) {
    if (local_root == 0) return 0;
    AVLNode<Item_Type>* avl_root =
            dynamic_cast<AVLNode<Item_Type>* >(local_root);
    if (avl_root == 0) {
        throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                       "Node not AVLNode");
    }
    if (avl_root->left == 0 && avl_root->right == 0) {
        if (avl_root->balance != AVLNode<Item_Type>::BALANCED) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Leaf node not balanced");
        }
        return 1;
    } else {
        int left_height = verify_structure(avl_root->left, local_root);
        int right_height = verify_structure(avl_root->right, local_root);
        int delta = right_height - left_height;
        if (delta < -1) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Balance < -1");
        }
        if (delta > 1) {
            throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                           "Balance > +1");
        }
        switch (delta) {
            case -1:
                if (avl_root->balance != AVLNode<Item_Type>::LEFT_HEAVY) {
                    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                                   "Balance value not correct, should be -1");
                }
                break;
            case 0:
                if (avl_root->balance != AVLNode<Item_Type>::BALANCED) {
                    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                                   "Balance value not correct, should be 0");
                }
                break;
            case +1:
                if (avl_root->balance != AVLNode<Item_Type>::RIGHT_HEAVY) {
                    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                                   "Balance value not correct, should be +1");
                }
                break;
        }
        if (avl_root->left != 0) {
            if (avl_root->left->data >= avl_root->data) {
                throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                               "Left child >= parent");
            }
        }
        if (avl_root->right != 0) {
            if (avl_root->right->data <= avl_root->data) {
                throw Bad_Structure<Item_Type>(local_root, parent, this->root,
                                               "Right child <= parent");
            }
        }
        return (left_height > right_height ? left_height : right_height) + 1;
    }
}

#endif

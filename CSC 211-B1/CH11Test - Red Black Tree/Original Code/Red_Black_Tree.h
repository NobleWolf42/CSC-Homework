#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdexcept>
#include "BST_With_Rotate.h"
#include "RBNode.h"

/** Definition of the Red-Black Tree class 
 @param Item_Type the type of item to be stored in the tree
 Note: Item_Type must define the less than operator as a 
 total order.
 */
template <typename Item_Type>
class Red_Black_Tree : public BST_With_Rotate<Item_Type> {
public:
    // Constructor

    /** Construct an empty Red_Black_Tree */
    Red_Black_Tree() : BST_With_Rotate<Item_Type>() {
    }

    // Public Member Functions
    /** Insert an item into the tree 
        @param item The item to be inserted
        @return true if the item was not already
        in the tree, false otherwise.
        post: The item is in the tree.
     */
    virtual bool insert(const Item_Type& item);

    /** Remove an item from the tree 
        @param item The item to be removed
        @return true if the item was in the tree,
        false otherwise.
        Post: The item is no longer in the tree.
     */
    virtual bool erase(const Item_Type& item);

private:

    // Private member functions

    /** Insert an item into a the tree 
        @param local_root A reference to the current root
        @param item The item to be inserted
        @return true if the item was not already in the
        tree, false otherwise
        post: The item is in the tree.
     */
    bool insert(BTNode<Item_Type>*& local_root,
            const Item_Type& item);

    /** Function to make the two children of the a sub-tree
        black and the localRoot black.
        @param RB_local_root The root of the sub-tree
        cast to a RBNode<Item_Type>*
     */
    void move_black_down(BTNode<Item_Type>* RB_local_root);

    /** Determine whether a node is red.
        @param node A pointer to a BTNode<Item_Type>
        @return true if node points to a RBNode<Item_Type> that is red
     */
    static bool is_red(BTNode<Item_Type>* node);

    /** Set the color of a node.
        @param node A pointer to a BTNode<Item_Type>
        @param red A bool value that is true if the
               node is to be set red, false if to be set black
     */
    static void set_red(BTNode<Item_Type>* node, bool red);

    /** Recursive erase from method.  
        Removes the given item from the Red-Black tree.  
        Note that the item must implement the less-than operator.
        Pre: The values of local_root is not NULL
        @post The object is removed from the tree
        @param local_root - Root of the subtree
        @param item - The item to be removed
        @return true if the item is removed
        false if the item is not in the tree 
     */
    bool erase(BTNode<Item_Type>*& local_root, const Item_Type& item);

    /** Function to find a replacement for a node that is being
        deleted from a Red-Black tree.  If the node has a NULL
        child, then the replacement is the other child.  If neither
        are NULL, then the replacement is the largest value less
        than the item being removed.
        @pre  node is not NULL
        @post a node replaced by its replacement 
        @param node The node to be deleted or replaced
     */
    void find_replacement(BTNode<Item_Type>*& node);

    /** Find the node such that parent->right->right == NULL
        @post The found node is removed from the tree and replaced
        by its left child (if any)
        @param parent - The possible parent
        @return the value of the found node
     */
    Item_Type find_largest_child(BTNode<Item_Type>* parent);

    /** Method to restore black balance to a subtree whose right black
        height is currently one less than the left black height.
        @param local_root - The root of the tree needing fixing
     */
    void fixup_right(BTNode<Item_Type>*& local_root);

    /** Method to restore black balance to a subtree whose left black
        height is currently one less than the right black height.
        @param local_root - The root of the tree needing fixing
     */
    void fixup_left(BTNode<Item_Type>*& local_root);


    // Data Fields
    /** A boolean variable to indicate that the black height
        was reduced by a call to the recursive erase function
        or one of its subfunctions. 
     */
    bool fixup_required;

}; // Red-Black tree

// Implementation of member functions



#endif

/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <stdexcept>
#include "BST_With_Rotate.h"
#include "RBNode.h"
#include "Bad_Structure.h"

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
    Red_Black_Tree() : BST_With_Rotate<Item_Type>() {}

    // Public Member Functions
    /** Insert an item into the tree 
        @param item The item to be inserted
        @return true if the item was not already
        in the tree, false otherwise.
        post: The item is in the tree.
     */
    virtual bool insert(const Item_Type& item) {
        if (this->root == NULL) {
            RBNode<Item_Type>* new_root = new RBNode<Item_Type>(item);
            new_root->is_red = false;
            this->root = new_root;
            return true;
        } else {
            //Call the recursive insert function.
            bool return_value = insert(this->root, item);
            //Force the root to be black
            set_red(this->root, false);
            return return_value;
        }
    }

    /** Remove an item from the tree 
        @param item The item to be removed
        @return true if the item was in the tree,
        false otherwise.
        Post: The item is no longer in the tree.
     */
    virtual bool erase(const Item_Type& item) {
        bool return_value = erase(this->root, item);
        //Force the root to be black
        set_red(this->root, false);
        return return_value;
    }

    bool verify_structure() {
        verify_structure(this->root, 0);
        return true;
    }

private:

    // Private member functions

    /** Insert an item into a the tree 
        @param local_root A reference to the current root
        @param item The item to be inserted
        @return true if the item was not already in the
        tree, false otherwise
        post: The item is in the tree.
     */
    bool insert(BTNode<Item_Type>*& local_root, const Item_Type& item) {
        if (item < local_root->data) {
            if (local_root->left == NULL) {
                local_root->left = new RBNode<Item_Type>(item);
                return true;
            } else {
                // Check for two red children, swap colors if found
                move_black_down(local_root);
                //Recusively insert into the left subtree
                bool return_value = insert(local_root->left, item);
                //See if the left-child is red
                if (is_red(local_root->left)) {
                    if (is_red(local_root->left->left)) {
                        //Child and left-left grandchild are both red
                        //Need to change colours and rotate
                        set_red(local_root->left, false);
                        set_red(local_root, true);
                        this->rotate_right(local_root);
                        return return_value;
                        //Else check right grandchild
                    } else if (is_red(local_root->left->right)) {
                        //This will require a double rotation
                        set_red(local_root->left->right, false);
                        set_red(local_root, true);
                        this->rotate_left(local_root->left);
                        this->rotate_right(local_root);
                        return return_value;
                    }
                }
                return return_value;
            }
        } else if (item > local_root->data) {
            if (local_root->right == NULL) {
                local_root->right = new RBNode<Item_Type>(item);
                return true;
            } else {
                // Check for two red children, swap colors if found
                move_black_down(local_root);
                //Recusively insert into the right subtree
                bool return_value = insert(local_root->right, item);
                //See if the right-child is red
                if (is_red(local_root->right)) {
                    if (is_red(local_root->right->right)) {
                        //Child and right-right grandchild are both red
                        //Need to change colours and rotate
                        set_red(local_root->right, false);
                        set_red(local_root, true);
                        this->rotate_left(local_root);
                        return return_value;
                        //Else check left grandchild
                    } else if (is_red(local_root->right->left)) {
                        //This will require a double rotation
                        set_red(local_root->right->left, false);
                        set_red(local_root, true);
                        this->rotate_right(local_root->right);
                        this->rotate_left(local_root);
                        return return_value;
                    }
                }
                return return_value;
            }
        } else {
            return false;
        }
    }

    /** Function to make the two children of the a sub-tree
        black and the localRoot red.
        @param RB_local_root The root of the sub-tree
        cast to a RBNode<Item_Type>*
     */
    void move_black_down(BTNode<Item_Type>* RB_local_root) {
        RBNode<Item_Type>* Cast_RB_local_root = dynamic_cast<RBNode<Item_Type>*>(RB_local_root);
        RBNode<Item_Type>* Cast_RB_left_child = dynamic_cast<RBNode<Item_Type>*>(RB_local_root->left);
        RBNode<Item_Type>* Cast_RB_right_child = dynamic_cast<RBNode<Item_Type>*>(RB_local_root->right);

        if (Cast_RB_local_root != NULL && Cast_RB_left_child != NULL && Cast_RB_right_child != NULL) {
            if (Cast_RB_right_child->is_red == true && Cast_RB_left_child->is_red == true) {
                Cast_RB_local_root->is_red = true;
                Cast_RB_left_child->is_red = false;
                Cast_RB_right_child->is_red = false;
            }
        }
    }

    /** Determine whether a node is red.
        @param node A pointer to a BTNode<Item_Type>
        @return true if node points to a RBNode<Item_Type> that is red
     */
    static bool is_red(BTNode<Item_Type>* node) {
        RBNode<Item_Type>* RB_node = dynamic_cast<RBNode<Item_Type>*>(node);
        if (RB_node != NULL) {
            return RB_node->is_red;
        } else {
            return false;
        }
    }

    /** Set the color of a node.
        @param node A pointer to a BTNode<Item_Type>
        @param red A bool value that is true if the
               node is to be set red, false if to be set black
     */
    static void set_red(BTNode<Item_Type>* node, bool red) {
        RBNode<Item_Type>* RB_node = dynamic_cast<RBNode<Item_Type>*>(node);
        if (RB_node != NULL) {
            RB_node->is_red = red;
        }
    }

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
    bool erase(BTNode<Item_Type>*& local_root, const Item_Type& item) {
        if (local_root == NULL) {
            return false;
        } else if (item < local_root->data) {
            bool returnVal = erase(local_root->left, item);
            if (fixup_required) {
                fixup_left(local_root);
                fixup_required = false;
            }
            return returnVal;
        } else if (local_root->data < item) {
            bool returnVal = erase(local_root->right, item);
            if (fixup_required) {
                fixup_right(local_root);
                fixup_required = false;
            }
            return returnVal;
        } else {
            find_replacement(local_root);
            return true;
        }
    }


    /** Function to find a replacement for a node that is being
        deleted from a Red-Black tree.  If the node has a NULL
        child, then the replacement is the other child.  If neither
        are NULL, then the replacement is the largest value less
        than the item being removed.
        @pre  node is not NULL
        @post a node replaced by its replacement 
        @param node The node to be deleted or replaced
     */
    void find_replacement(BTNode<Item_Type>*& node) {
        BTNode<Item_Type>* temp = node;
        if (node->left == NULL) {
            node = node->right;
            
            if (!is_red(temp) && (node == NULL || is_red(node) == false)) {
                fixup_required = true;
            } else {
                if (!is_red(temp)) {
                    set_red(node, false);
                }
                fixup_required = false;
            }
            
            delete temp;
        } else if (node->right == NULL) {
            node = node->left;

            if (!is_red(temp) && (node == NULL || is_red(node) == false)) {
                fixup_required = true;
            } else {
                if (!is_red(temp)) {
                    set_red(node, false);
                }
                fixup_required = false;
            }

            delete temp;
        } else {
            node->data = find_largest_child(node->left);

            if (!is_red(temp) && (node == NULL || is_red(node) == false)) {
                fixup_required = true;
            } else {
                if (!is_red(temp)) {
                    set_red(node, false);
                }
                fixup_required = false;
            }
        }
    }


    /** Find the node such that parent->right->right == NULL
        @post The found node is removed from the tree and replaced
        by its left child (if any)
        @param parent - The possible parent
        @return the value of the found node
     */
    Item_Type find_largest_child(BTNode<Item_Type> *&parent) {
        Item_Type returnVal = parent->data;
        if (parent->right == NULL) {
            returnVal = parent->data;

            if (parent->left != nullptr && is_red(parent->left)) {
                set_red(parent->left, false);
                BTNode<Item_Type>* temp = parent;
                parent = parent->left;
                delete temp;
            } else {
                erase(parent, parent->data);
            }

        } else {
            returnVal = find_largest_child(parent->right);
            if (fixup_required) {
                fixup_right(parent);
            }
        }
        return returnVal;
    }

    /** Method to restore black balance to a subtree whose right black
        height is currently one less than the left black height.
        @param local_root - The root of the tree needing fixing
     */
    void fixup_right(BTNode<Item_Type>*& local_root) {
        if (is_red(local_root->left)) {
            set_red(local_root, true);
            set_red(local_root->left, false);
            this->rotate_right(local_root);
            fixup_right(local_root->right);
        } else if (!is_red(local_root->left) && (!local_root->left || !is_red(local_root->left->left) && !is_red(local_root->left->right))) {
            set_red(local_root, false);
            set_red(local_root->left, true);
        } else if (!is_red(local_root->left) && is_red(local_root->left->right)) {
            set_red(local_root->left, true);
            set_red(local_root->left->right, false);
            this->rotate_left(local_root->left);
            fixup_right(local_root);
        } else if (!is_red(local_root->left) && is_red(local_root->left->left)) {
            set_red(local_root, false);
            set_red(local_root->left, is_red(local_root));
            set_red(local_root->left->left, false);
            this->rotate_right(local_root);
            fixup_required = false;
        }
    }

    /** Method to restore black balance to a subtree whose left black
        height is currently one less than the right black height.
        @param local_root - The root of the tree needing fixing
     */
    void fixup_left(BTNode<Item_Type>*& local_root) {
        if (is_red(local_root->right)) {
            set_red(local_root, true);
            set_red(local_root->right, false);
            this->rotate_left(local_root);
        } else if (!is_red(local_root->right) && (!local_root->right || !is_red(local_root->right->left) && !is_red(local_root->right->right))) {
            set_red(local_root, false);
            set_red(local_root->right, true);
        } else if (!is_red(local_root->right) && is_red(local_root->right->left)) {
            set_red(local_root->right, true);
            set_red(local_root->right->left, false);
            this->rotate_right(local_root->right);
            fixup_left(local_root);
        } else if (!is_red(local_root->right) && is_red(local_root->right->right)) {
            set_red(local_root, false);
            set_red(local_root->right, is_red(local_root));
            set_red(local_root->right->right, false);
            this->rotate_left(local_root);
            fixup_required = false;
        }
    }

    // Data Fields
    /** A boolean variable to indicate that the black height
        was reduced by a call to the recursive erase function
        or one of its subfunctions. 
     */
    bool fixup_required;

    /** Verify the strucure of the Red-Black tree
		@throws BadStructure if the structure is invalid
		@param local_root The local root
		@param parent The parent of the local root
		@return The black height of the tree
	*/
	int verify_structure(BTNode<Item_Type>* local_root,
		       BTNode<Item_Type>* parent);

}; // Red-Black tree

// Implementation of member functions

/** Verify the strucure of the Red-Black tree
    @throws BadStructure if the structure is invalid
    @param local_root The local root
    @param parent The parent of the local root
    @return The black height of the tree
*/
template<typename Item_Type>
int Red_Black_Tree<Item_Type>::verify_structure(BTNode<Item_Type>* local_root,
						BTNode<Item_Type>* parent)
{
  if (local_root == 0) return 0;
  RBNode<Item_Type>* rb_node = dynamic_cast<RBNode<Item_Type>*>(local_root);
  if (rb_node == 0) {
    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
				   "Node is not a RBNode");
  }
  if (rb_node->is_red) {
    if (parent == 0) {
      throw Bad_Structure<Item_Type>(local_root, parent, this->root,
				     "Root is red");
    }
    RBNode<Item_Type>* rb_parent = 
      dynamic_cast<RBNode<Item_Type>*>(parent);
    if (rb_parent == 0) {
      throw Bad_Structure<Item_Type>(local_root, parent, this->root,
				     "Parent is not a RB Node");
    }
    if (rb_parent->is_red) {
      throw Bad_Structure<Item_Type>(local_root, parent, this->root,
				     "Red child of a red parent");
    }
  }
  int lbh = verify_structure(rb_node->left, rb_node);
  int rbh = verify_structure(rb_node->right, rb_node);
  if (lbh != lbh) {
    throw Bad_Structure<Item_Type>(local_root, parent, this->root,
				   "Unequal black heights");
  }
  if (rb_node->is_red) {
    return lbh;
  } else {
    return lbh + 1;
  }
}

#endif


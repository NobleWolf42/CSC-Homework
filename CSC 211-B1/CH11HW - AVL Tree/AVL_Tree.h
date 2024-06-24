/*
Author: Ben Carpenter
Copyright: 2024
*/

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
  
  
 private:

int AVL_Tree<Item_Type>::verify_structure(BTNode<Item_Type> *local_root,
                                          BTNode<Item_Type> *parent) {
    if (local_root == 0) return 0;
    AVLNode<Item_Type> *avl_root =
            dynamic_cast<AVLNode<Item_Type> * >(local_root);
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
  
  // Private member functions declarations
  /** Insert an item into the tree. Called by starter function (see
      listing 11.2) with this->root as first argument.
      post: The item is in the tree.
      @param local_root A reference to the current root
      @param item The item to be inserted
      @return true only if the item was not already in the
  */
  virtual bool insert(BTNode<Item_Type>*& local_root, const Item_Type& item) {
    if (local_root == NULL) {
        local_root = new AVLNode<Item_Type>(item);
        increase = true;
        return true;
    } else if (item < local_root->data) {
        bool return_value = insert(local_root->left, item);
        if (increase) {
            AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
            
            switch (AVL_local_root->balance) {
                case AVLNode<Item_Type>::BALANCED:
                    AVL_local_root->balance = AVLNode<Item_Type>::LEFT_HEAVY;
                    break;
                
                case AVLNode<Item_Type>::RIGHT_HEAVY:
                    AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
                    increase = false;
                    break;

                case AVLNode<Item_Type>::LEFT_HEAVY:
                    rebalance_left(local_root);
                    increase = false;
                    break;
            
                default:
                    break;
            }
        }
        return return_value;
    } else if (local_root->data < item) {
        bool return_value = insert(local_root->right, item);
        if (increase) {
            AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
            
            switch (AVL_local_root->balance) {
                case AVLNode<Item_Type>::BALANCED:
                    AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
                    break;
                
                case AVLNode<Item_Type>::LEFT_HEAVY:
                    AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
                    increase = false;
                    break;

                case AVLNode<Item_Type>::RIGHT_HEAVY:
                    rebalance_right(local_root);
                    increase = false;
                    break;
            
                default:
                    break;
            }
        }
        return return_value;
    } else {
        increase = false;
        return false;
    }
  }
  
  /** Correct a critical left balance condition
      pre:  local_root is the root of an AVL subtree that is
      critically heavy.
      post: balance is restored
      @param local_root is the root of the AVL subtree
      that needs rebalancing
  */
  void rebalance_left(BTNode<Item_Type>*& local_root) {
    AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
    AVLNode<Item_Type>* left_child = dynamic_cast<AVLNode<Item_Type>*>(local_root->left);
    
    if (left_child->balance == AVLNode<Item_Type>::RIGHT_HEAVY) {
        AVLNode<Item_Type>* left_right_child = dynamic_cast<AVLNode<Item_Type>*>(left_child->right);

        if (left_right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        } else if (left_right_child->balance == AVLNode<Item_Type>::BALANCED) {
            left_child->balance = AVLNode<Item_Type>::BALANCED;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        } else {
            left_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
            left_right_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }

        BST_With_Rotate<Item_Type>::rotate_left(local_root->left);
    } else {
        left_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }

    BST_With_Rotate<Item_Type>::rotate_right(local_root);
  }
  
  /** Correct a critical right balance condition
      pre:  local_root is the root of an AVL subtree that is
      critically heavy.
      post: balance is restored
      @param local_root is the root of the AVL subtree
      that needs rebalancing
  */
  void rebalance_right(BTNode<Item_Type>*& local_root) {
    AVLNode<Item_Type>* AVL_local_root = dynamic_cast<AVLNode<Item_Type>*>(local_root);
    AVLNode<Item_Type>* right_child = dynamic_cast<AVLNode<Item_Type>*>(local_root->right);
    
    if (right_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
        AVLNode<Item_Type>* right_left_child = dynamic_cast<AVLNode<Item_Type>*>(right_child->left);

        if (right_left_child->balance == AVLNode<Item_Type>::LEFT_HEAVY) {
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::RIGHT_HEAVY;
        } else if (right_left_child->balance == AVLNode<Item_Type>::BALANCED) {
            right_child->balance = AVLNode<Item_Type>::BALANCED;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        } else {
            right_child->balance = AVLNode<Item_Type>::LEFT_HEAVY;
            right_left_child->balance = AVLNode<Item_Type>::BALANCED;
            AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
        }

        BST_With_Rotate<Item_Type>::rotate_right(local_root->right);
    } else {
        right_child->balance = AVLNode<Item_Type>::BALANCED;
        AVL_local_root->balance = AVLNode<Item_Type>::BALANCED;
    }
    
    BST_With_Rotate<Item_Type>::rotate_left(local_root);
  }


  // Data Fields
  /** A flag to indicate that the height of the tree has increased */
  bool increase;

}; // End of AVL_Tree class definition

// Implementation of member functions


#endif

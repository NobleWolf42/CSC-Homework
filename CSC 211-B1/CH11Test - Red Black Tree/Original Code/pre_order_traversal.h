#ifndef PRE_ORDER_TRAVERSAL_H
#define PRE_ORDER_TRAVERSAL_H

// get it from https://stackoverflow.com/questions/36802354/print-binary-tree-in-a-pretty-way-using-c

#include "Binary_Tree.h"
#include <ostream>


template<typename Item_Type>
int getHeight(const Binary_Tree<Item_Type>& p)
{
    if (p.is_null())
    {
        return 0;
    }
    int left = getHeight(p.get_left_subtree());
    int right = getHeight(p.get_right_subtree());
    int h;
    if (left > right)
    {
        h = 1 + left;
    }
    else
    {
        h = 1 + right;
    }
    return h;
}

template<typename Item_Type>
void pre_order_traversal(const Binary_Tree<Item_Type>& the_tree, 
			 std::ostream& out, int level)
{
  if (the_tree.is_null()) { 
    for (int i = 0; i < level; i++)
      out << "  ";
    out << "null\n";
  }
  else {
    for (int i = 0; i < level; i++)
      out << "  ";
    out << the_tree.get_data() << std::endl;
    pre_order_traversal(the_tree.get_left_subtree(), out, level + 1);
    pre_order_traversal(the_tree.get_right_subtree(), out, level + 1);
  }
}




#endif

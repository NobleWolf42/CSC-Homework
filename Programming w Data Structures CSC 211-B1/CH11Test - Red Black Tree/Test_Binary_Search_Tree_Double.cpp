/** Program to test binary tree class */

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
#include "Red_Black_Tree.h"
#include "pre_order_traversal.h"
#include "Binary_pretty_print.h"

using namespace std;

int main(int argc, char* argv[]) 
{

  Binary_Search_Tree<double>* the_tree = NULL;
      the_tree = new Red_Black_Tree<double>;

  double value;

  the_tree->insert(1.0);
  the_tree->insert(2.0);
  the_tree->insert(3.0);
  the_tree->insert(4.0);
  the_tree->insert(5.0);
  the_tree->insert(6.0);
  the_tree->insert(7.0);
  the_tree->insert(8.0);
  the_tree->insert(9.0);
  
  Dump(*the_tree);
  
  the_tree->erase(4.0);
  Dump(*the_tree);
  the_tree->erase(6.0);
  Dump(*the_tree);
  the_tree->erase(8.0);
  Dump(*the_tree);
  cout << "Height of the tree: " << get_max_depth(*the_tree) << endl;
}


  

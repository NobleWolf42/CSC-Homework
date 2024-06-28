/** Program to test binary tree class */

#include <string>
#include <iostream>
#include <fstream>
#include "Binary_Search_Tree.h"
#include "Red_Black_Tree.h"
#include "pre_order_traversal.h"

using namespace std;

int main(int argc, char* argv[]) 
{

  Binary_Search_Tree<string>* the_tree = NULL;
      the_tree = new Red_Black_Tree<string>;

  string word;
  while (cin >> word) {
    the_tree->insert(word);
    pre_order_traversal(*the_tree, cout, 0);
  }
  cin.clear();
  while (cin >> word) {
    the_tree->erase(word);
    pre_order_traversal(*the_tree, cout, 0);
  }
}


  

/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef TESTCASES_H
#define TESTCASES_H

#include <cxxtest/TestSuite.h>

//Include your classes header file(s) below and uncomment.
#include "Red_Black_Tree.h"
#include "pre_order_traversal.h"
#include <string>
#include <iostream>
#include <fstream>

class TestCases : public CxxTest::TestSuite {
public:

    //All tests should start with the word 'test' followed by
    //the name of the function being tested.

    void testAVL() {
        Red_Black_Tree<int> test1;
        Red_Black_Tree<int> test2;
        Red_Black_Tree<int> test3;
        Red_Black_Tree<std::string> test4;
        Red_Black_Tree<int> test5;
        Binary_Search_Tree<int> test6;
        BTNode<int> testNode(55);
        Red_Black_Tree<int> test7;

        std::ifstream testFile1 ("C:/Users/NobleWolf42/Documents/School/CSC-Homework/CSC 211-B1/CH11Test - Red Black Tree/BSTtest1.txt");
        std::ifstream testFile2 ("C:/Users/NobleWolf42/Documents/School/CSC-Homework/CSC 211-B1/CH11Test - Red Black Tree/BSTtest2.txt");
        std::ifstream testFile3 ("C:/Users/NobleWolf42/Documents/School/CSC-Homework/CSC 211-B1/CH11Test - Red Black Tree/BSTtest3.txt");
        std::ifstream testFile4 ("C:/Users/NobleWolf42/Documents/School/CSC-Homework/CSC 211-B1/CH11Test - Red Black Tree/BSTtest4.txt");
        std::ifstream testFile5 ("C:/Users/NobleWolf42/Documents/School/CSC-Homework/CSC 211-B1/CH11Test - Red Black Tree/BSTtest1.txt");
        std::ifstream testFile6 ("C:/Users/NobleWolf42/Documents/School/CSC-Homework/CSC 211-B1/CH11Test - Red Black Tree/BSTtest1.txt");

        TS_ASSERT(test1.is_null());
        TS_ASSERT(!test1.erase(31));
        TS_ASSERT(!test6.erase(31));
        TS_ASSERT(test1.is_leaf());
        TS_ASSERT_THROWS_ANYTHING(test1.get_data());
        TS_ASSERT_THROWS_ANYTHING(test1.get_left_subtree());
        TS_ASSERT_THROWS_ANYTHING(test1.get_right_subtree());

        std::cout << "Test BTNode to_string (should be 55): " << testNode.to_string() << std::endl;

        if (testFile1.is_open()) {
            int testInt1 = 0; 
            //std::cout << "File 1" << std::endl;
            while (testFile1) {
                testFile1 >> testInt1;
                test1.insert(testInt1);
                //std::cout << testInt1 << std::endl;
            }
        }

        if (testFile2.is_open()) {
            int testInt2 = 0;
            //std::cout << "File 2" << std::endl;
            while (testFile2) {
                testFile2 >> testInt2;
                test2.insert(testInt2);
                //std::cout << testInt2 << std::endl;
            }
        }

        if (testFile3.is_open()) {
            int testInt3 = 0;
            //std::cout << "File 3" << std::endl;
            while (testFile3) {
                testFile3 >> testInt3;
                test3.insert(testInt3);
                //std::cout << testInt3 << std::endl;
            }
        }

        if (testFile4.is_open()) {
            std::string testStr4 = "";
            //std::cout << "File 4" << std::endl;
            while (testFile4) {
                testFile4 >> testStr4;
                test4.insert(testStr4);
                //std::cout << testStr4 << std::endl;
            }
        }

        testFile5 >> test5;

        if (testFile6.is_open()) {
            int testInt6 = 0;
            //std::cout << "File 6" << std::endl;
            while (testFile6) {
                testFile6 >> testInt6;
                test6.insert(testInt6);
                //std::cout << testInt6 << std::endl;
            }
        }

        TS_ASSERT_DIFFERS(test5.get_data(), test1.get_data());

        std::cout << "Test 4 Output:" << std::endl << std::endl << test4;
        
        TS_ASSERT(test1.find(31));
        TS_ASSERT(test2.find(41));
        TS_ASSERT(test3.find(51));
        TS_ASSERT(test4.find("lazy"));

        TS_ASSERT(test4.verify_structure());

        pre_order_traversal(test4, std::cout, 0);
        TS_ASSERT(test4.erase("dog"));

        TS_ASSERT(test6.find(31));
        TS_ASSERT(test6.find(50));
        TS_ASSERT(test6.find(30));
        TS_ASSERT(test6.erase(31));
        TS_ASSERT(test6.erase(50));
        TS_ASSERT(test6.erase(30));
        TS_ASSERT(!test6.find(31));
        TS_ASSERT(!test6.find(50));
        TS_ASSERT(!test6.find(30));

        TS_ASSERT(test1.find(31));
        TS_ASSERT(test2.find(41));
        TS_ASSERT(test3.find(51));
        TS_ASSERT(!test4.is_leaf());
        TS_ASSERT(test4.get_left_subtree().get_left_subtree().is_leaf());
        TS_ASSERT_EQUALS(test4.get_right_subtree().get_right_subtree().get_data(), "the");
        TS_ASSERT_EQUALS(test4.get_data(), "jumps");

        TS_ASSERT(test1.verify_structure());
        TS_ASSERT(test2.verify_structure());
        TS_ASSERT(test3.verify_structure());
        TS_ASSERT(test4.verify_structure());

        TS_ASSERT(test1.erase(31));
        TS_ASSERT(test2.erase(41));
        TS_ASSERT(test3.erase(51));
        TS_ASSERT(test4.erase("brown"));
        TS_ASSERT(test4.verify_structure());
        TS_ASSERT(test4.erase("quick"));
        TS_ASSERT(test4.verify_structure());
        TS_ASSERT(test4.erase("jumps"));
        //pre_order_traversal(test4, std::cout, 0);

        TS_ASSERT(!test1.find(31));
        TS_ASSERT(!test2.find(41));
        TS_ASSERT(!test3.find(51));
        TS_ASSERT(!test4.find("brown"));
        TS_ASSERT(!test4.find("quick"));
        TS_ASSERT(!test4.find("jumps"));
        TS_ASSERT(test1.verify_structure());
        TS_ASSERT(test2.verify_structure());
        TS_ASSERT(test3.verify_structure());
        TS_ASSERT(test4.verify_structure());
        TS_ASSERT_THROWS_ANYTHING(test5.verify_structure());



        //std::cout << "Test 4 Output:" << std::endl << std::endl << test4;

        test7.insert(50);
        test7.insert(60);
        test7.insert(25);
        test7.insert(20);
        test7.insert(40);
        test7.insert(52);
        test7.insert(61);
        test7.insert(45);
        test7.insert(30);
        test7.insert(26);
        //test7.erase(40);
        //test7.erase(45);
        //test7.erase(60);
        //pre_order_traversal(test7, std::cout, 0);
        TS_ASSERT(test7.verify_structure());
        //test7.erase(61);

        //pre_order_traversal(test7, std::cout, 0);
        TS_ASSERT(test7.verify_structure());

        Red_Black_Tree<int> E;

        for (int i = 0; i < 11; i++) {
            E.insert(i);
        }

        //E.erase(0);
        //E.erase(2);
        //E.erase(1);

        //pre_order_traversal(E, std::cout, 0);
        TS_ASSERT(E.verify_structure());

        Red_Black_Tree<int> B;

        B.insert(8);
        B.insert(3);
        B.insert(11);
        B.insert(1);
        B.insert(6);
        B.insert(5);
        B.insert(0);

        //B.erase(8);
        B.erase(6);
        //B.erase(11);

        //pre_order_traversal(B, std::cout, 0);
        //std::cout << "Test Output:" << std::endl << std::endl << B;
        TS_ASSERT(B.verify_structure());

        Red_Black_Tree<int> C;

        C.insert(60);
        C.insert(9);
        C.insert(6);
        C.insert(110);
        C.insert(55);
        C.insert(99);
        C.insert(31);
    
        //C.erase(31);
        C.erase(60);

        //pre_order_traversal(C, std::cout, 0);
        //std::cout << "Test Output:" << std::endl << std::endl << C;
        TS_ASSERT(C.verify_structure());

        Red_Black_Tree<int> D;

        D.insert(61);
        D.insert(52);
        D.insert(85);
        D.insert(20);
        D.insert(55);
        D.insert(76);
        D.insert(93);
        D.insert(16);
        D.insert(57);
        D.insert(71);
        D.insert(81);
        D.insert(90);
        D.insert(101);
        D.insert(65);
    
        //D.erase(71);
        //D.erase(93);
        //D.erase(90);
        //D.erase(76);
        //D.erase(61);
        D.erase(57);


        //pre_order_traversal(D, std::cout, 0);
        //std::cout << "Test Output:" << std::endl << std::endl << D;
        TS_ASSERT(D.verify_structure());
    }

};
#endif /* TESTCASES_H */

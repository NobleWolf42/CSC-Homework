/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
Exam Instructions: Implementation of a Tree Class Hierarchy with Protected Attributes
Objective:
The goal of this programming exam is to design and implement a class hierarchy in C++ for modeling trees within a forest ecosystem. This hierarchy will include an abstract base class Tree and several derived classes for specific species: PineTree, WhitePineTree, OakTree, and RedOakTree. Your implementation should demonstrate a clear understanding of object-oriented programming principles such as inheritance, polymorphism, encapsulation, and the use of protected attributes and virtual functions.

Task Specifications:
    1. Abstract Base Class Tree Implementation:

        - Incorporate common attributes species and location as protected members to ensure they are accessible to derived classes.
        - Define a pure virtual function estimateAge() for age estimation, to be implemented by derived classes.
        - Implement a public method displayInfo() that prints the tree's species, location, and estimated age.

    2. Derived Class Implementations:

        - PineTree Class: Derives from Tree. Introduces a protected attribute branchRings for the count of branch rings, correlating directly to the tree's age.
        - WhitePineTree Class: A specialization of PineTree. May adjust the age estimation process to reflect specific growth characteristics of white pines.
        - OakTree Class: Derives from Tree. Includes a protected attribute diameter to aid in the age estimation of oak trees.
        - RedOakTree Class: A specialization of OakTree. Could use a modified age estimation method based on the diameter, perhaps applying a unique factor specific to red oaks.

Running example:

    *Species: Oak, Estimated Age: 12.6, Location: Oakwood Park
    *Species: Pine, Estimated Age: 75, Location: Pinecrest Forest
    *Species: White Pine, Estimated Age: 60, Location: Northern Forest
    *Species: Red Oak, Estimated Age: 30, Location: Deciduous Forest

Requirements:
    - Class Definitions and Implementations: Separate your class declarations (.h files) and definitions (.cpp files) to promote clean code organization.

Evaluation Criteria:
    - Correct Implementation: The hierarchy should be accurately represented with appropriate use of inheritance and protected attributes.
    - Code Quality and Documentation: Code should be well-structured, clearly commented, and follow standard naming conventions. Proper encapsulation of attributes and polymorphism in method implementation must be demonstrated.
    - Functionality: The program must compile without errors and run as expected, showcasing the distinct characteristics of each tree type in the hierarchy.

Submission Guidelines:
    - Submit the following files as per the instructions: Tree.h, Tree.cpp, PineTree.h, PineTree.cpp, WhitePineTree.h, WhitePineTree.cpp, OakTree.h, OakTree.cpp, RedOakTree.h, RedOakTree.cpp, and main.cpp/newCxxTest.h to Zybooks and Web-CAT. Each submission worth 50%.
    - Ensure your work is original and adheres to the academic integrity guidelines provided by your syllabus.
*/

#include "PineTree.h"
#include "WhitePineTree.h"
#include "OakTree.h"
#include "RedOakTree.h"
#include "Tree.h"
#include <iostream>

int main() {
    OakTree myOakTree("Oak", "Oakwood Park", 10.5);
    PineTree myPineTree("Pine", "Pinecrest Forest", 75);

    // std::cout << "Oak Tree Info:" << std::endl;
    myOakTree.dislayInfo();
    // std::cout << "Estimated Age: " << myOakTree.estimateAge() << " years" << std::endl;

    // std::cout << "Pine Tree Info:" << std::endl;
    myPineTree.dislayInfo();
    // std::cout << "Estimated Age: " << myPineTree.estimateAge() << " years" << std::endl;

    WhitePineTree whitePine("White Pine", "Northern Forest", 50);
    RedOakTree redOak("Red Oak", "Deciduous Forest", 20);

    whitePine.dislayInfo();
    // std::cout << "Estimated Age: " << whitePine.estimateAge() << " years" << std::endl;

    redOak.dislayInfo();
    // std::cout << "Estimated Age: " << redOak.estimateAge() << " years" << std::endl;


    return 0;
}

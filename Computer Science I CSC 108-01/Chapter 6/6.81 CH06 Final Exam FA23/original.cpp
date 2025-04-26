/*
Programming Exam: Implement assign, printVector, and main Functions in C++
Objective: Create three functions in C++. The first, assign, is for entering numbers into a vector. The second is the main function, which calls assign to populate the vector, then prompts for lower and upper bounds, calls the range function with this data, and displays the result using printVector.

Part 1 - Implement the assign Function

Function Specifications for assign:

    - Function Name: assign
    - Return Type: std::vector<int>
    - Parameter: None

Requirements:

    - Prompt for Number Count: Ask the user how many numbers they want to enter.
    - Input and Store Numbers: Use a loop to input each number and store it in a std::vector<int>.
    - Return the Vector: After all numbers are entered, return the populated vector.

Part 2 - Implement the printVector Function

Function Specifications:

    - Function Name: printVector.
    - Parameter: A std::vector to be printed.
    - Return Type: None

Requirements:

    - Display Contents: Print each element of the vector. If the vector is empty, print a message such as "Empty vector".
    - Formatting: Ensure the output is user-friendly and clearly formatted (See example below).

Part 3 - Implement the range Function

Function Specifications:

    - The function iterates through each number in the numbers vector and checks if it falls within the specified bounds (inclusive of the bounds themselves). If a number falls within the bounds, it is added to the result vector.
    - Function Name: range.
    - Parameter: A std::vector a vector containing the numbers to be filtered
    - Parameter: A lower parameter is the lower bound of the range.
    - Parameter: An upper parameter is the upper bound of the range.
    - Return Type: A std::vector of filtered numbers.

Part 4 - Implement the main Function

Task for Main Function:

    1. Call assign Function: Use assign to input numbers and receive the populated vector.
    2. Request Bounds: Ask the user for the lower and upper bounds for the range.
    3. Call range Function: Pass the vector from assign and the bounds to range, storing the returned vector.
    4. Display Results with printVector: Use printVector to show the contents of the vector returned by range.

Example Interaction:

    *Enter the number of elements: 4
    *Enter element 1: 8
    *Enter element 2: 3
    *Enter element 3: 5
    *Enter element 4: 1
    *Enter lower bound: 2
    *Enter upper bound: 6
    *Result: 3, 5

Testing:

    - Test the range function to ensure it correctly gathers and stores numbers in a vector (60%).
    - Write six test cases at the end of the main function to test the range function (20%).
    - Test the main function for its ability to integrate assign, range, and printVector, handling various input scenarios (20%).

Submission Guidelines:

    - Submit your C++ source file (.cpp) containing the assign, main, range, and printVector functions through Zybooks.
    - Comment your code to explain the functionality and logic of each function.
    - Adhere to C++ coding standards and best practices.

Evaluation Criteria:

    - Proper implementation of the assign function for user input.
    - Integration and functionality of the main function with assign, range, and printVector.
    - Code quality, including readability, organization, and commenting.
    - Handling of different input cases and robustness in error checking.

This instruction set is designed for a C++ programming exam, focusing on function implementation for user input handling, vector manipulation, and integration with existing functions.

Please be aware that the scores you receive on Zybooks for your programming exam are preliminary and should be considered for reference only.

Make sure your program compiles without any syntax errors to receive any credits for the exam.

The final grade for your exam will be determined after I have personally hand-graded each submission.
*/
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<int> assign()
{
}

vector<int> range(vector<int> vec, int ll, int ul)
{
}

void printVector(vector<int> vec)
{
}

void testVector(vector<int> test, vector<int> result, size_t numTest)
{
}

int main()
{

    return 0;
}
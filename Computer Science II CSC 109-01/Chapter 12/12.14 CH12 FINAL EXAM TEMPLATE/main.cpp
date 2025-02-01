/*
Author: Ben Carpenter
Copyright: 2024

Assignment:
CH12 Exam

Problem Statement

You are tasked with implementing a mileage tracking system for a transportation company that includes drivers for both regular Uber and UberEats services. Your program should have three classes: MileageTracker, Uber, and UberEats.

Class Descriptions

    1. MileageTracker:

        - This class represents a basic mileage tracker for an employee.
        - It should have the following private members:
            - employeeId (template type)
            - employeeName (string)
            - totalMiles (double)
        - It should have the following public member functions:
            - MileageTracker(EmployeeIdType employeeId, std::string employeeName) - Constructor to initialize the employee ID and name.
            - void addMiles(double miles) - Method to add miles to the total mileage.
            - EmployeeIdType getEmployeeId() - Method to get the employee ID.
            - std::string getEmployeeName() - Method to get the employee name.
            - double getTotalMiles() - Method to get the total miles.
            - If an attempt is made to add negative miles, throw an runtime_error exception with an error message: Mileage can't be negative.

    2. Uber (inherits from MileageTracker):

        - This class represents an Uber driver and should inherit from MileageTracker.
        - It should have an additional private member:
            - vehicleType (template type)
        - It should have the following public member functions:
            - Uber(EmployeeIdType employeeId, std::string employeeName, VehicleType vehicleType) - Constructor to initialize employee ID, name, and vehicle type.
            - VehicleType getVehicleType() - Method to get the vehicle type.
            - void setVehicleType(VehicleType newVehicleType) - Method to set the vehicle type.

    3. UberEats (inherits from Uber):

        - This class represents an UberEats driver and should inherit from Uber class.
        - It should have an additional private member:
            - foodType (template type)
        - It should have the following public member functions:
            - UberEats(EmployeeIdType employeeId, std::string employeeName, VehicleType newVehicleType, FoodType foodType) - Constructor to initialize employee ID, name, vehicle type, and food type.
            - FoodType getFoodType() - Method to get the food type.
            - void setFoodType(FoodType newFoodType) - Method to set the food type.

Instructions

Your task is to implement the three classes (MileageTracker, Uber, and UberEats) as described above. Follow these guidelines:

    1. Create a C++ program that defines the three classes and their member functions.

    2. Implement the constructors and methods for each class to ensure that they correctly store and retrieve the required information.

    3. Ensure that your program correctly handles different template types (e.g., string, int, double) for employeeId, vehicleType, and foodType.

    4. Implement error handling for negative mileage in the MileageTracker class by throwing an exception with an error message, "Mileage can't be negative.", when negative miles are added.

    5. Test your program using newCxxTest.h with various scenarios to ensure it functions as expected, including testing the exception handling for negative mileage.

Submission

Please submit your C++ program source code, including the three class implementations, any necessary header files, and a test program that demonstrates the functionality of your classes, including the exception handling for negative mileage.

    - Zybooks Submission (50%):
        - Log in to your Zybooks account.
        - Navigate to the assignment submission area for your course.
        - Follow the instructions provided by Zybooks for submitting your exam.

    - Web-CAT Submission (50%):
        - Log in to your Web-CAT account.
        - Access the assignment submission section for your course.
        - Follow the instructions provided by Web-CAT for submitting your exam.

Ensure that your code is well-commented to explain the purpose of each class and function.

Important Note: Do Not Alter main.cpp

    - DO NOT ALTER main.cpp: The provided main.cpp is used for testing your code in Zybooks and must not be altered in any way. Attempting to modify main.cpp to pass Zybooks tests is considered cheating, and students found doing so will receive a zero for the exam.
    - No Credits for Syntax Errors: Your program must compile without syntax errors to receive any credits for this exam. If your program contains syntax errors, it will not be evaluated, and you will receive zero credits.

Please be aware that the scores you receive on Zybooks for your programming exam are preliminary and should be considered for reference only.

The final grade for your exam will be determined after I have personally hand-graded each submission.

*/

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include "MileageTracker.h"
#include "Uber.h"
#include "UberEats.h"
//
using namespace std;

int main() {
    // Test cases for MileageTracker
    std::string employee_id_str = "EMP123";
    std::string employee_name_str = "John Doe";
    int employee_id_int = 456;
    double employee_id_double = 789.0;

    MileageTracker<std::string> mileage_tracker_str(employee_id_str, employee_name_str);
    mileage_tracker_str.addMiles(100);
    assert(mileage_tracker_str.getEmployeeId() == employee_id_str);
    assert(mileage_tracker_str.getEmployeeName() == employee_name_str);
    assert(mileage_tracker_str.getTotalMiles() == 100);

    MileageTracker<int> mileage_tracker_int(employee_id_int, employee_name_str);
    mileage_tracker_int.addMiles(150);
    assert(mileage_tracker_int.getEmployeeId() == employee_id_int);
    assert(mileage_tracker_int.getEmployeeName() == employee_name_str);
    assert(mileage_tracker_int.getTotalMiles() == 150);

    MileageTracker<double> mileage_tracker_double(employee_id_double, employee_name_str);
    mileage_tracker_double.addMiles(75.5);
    assert(mileage_tracker_double.getEmployeeId() == employee_id_double);
    assert(mileage_tracker_double.getEmployeeName() == employee_name_str);
    assert(mileage_tracker_double.getTotalMiles() == 75.5);

    // Test cases for Uber
    std::string vehicle_type_str = "Sedan";
    int vehicle_type_int = 2;
    double vehicle_type_double = 4.5;

    Uber<std::string, std::string> uber_driver_str_str(employee_id_str, employee_name_str, vehicle_type_str);
    uber_driver_str_str.addMiles(200);
    assert(uber_driver_str_str.getEmployeeId() == employee_id_str);
    assert(uber_driver_str_str.getEmployeeName() == employee_name_str);
    assert(uber_driver_str_str.getVehicleType() == vehicle_type_str);
    assert(uber_driver_str_str.getTotalMiles() == 200);

    Uber<int, int> uber_driver_int_int(employee_id_int, employee_name_str, vehicle_type_int);
    uber_driver_int_int.addMiles(300);
    assert(uber_driver_int_int.getEmployeeId() == employee_id_int);
    assert(uber_driver_int_int.getEmployeeName() == employee_name_str);
    assert(uber_driver_int_int.getVehicleType() == vehicle_type_int);
    assert(uber_driver_int_int.getTotalMiles() == 300);

    //    UberEats<std::string, std::string, std::string> uber_eats_driver(employee_id, employee_name, vehicle_type, food_type);
//    uber_eats_driver.addMiles(50);
    Uber<double, double> uber_driver_double_double(employee_id_double, employee_name_str, vehicle_type_double);
    uber_driver_double_double.addMiles(150.5);
    assert(uber_driver_double_double.getEmployeeId() == employee_id_double);
    assert(uber_driver_double_double.getEmployeeName() == employee_name_str);
    assert(uber_driver_double_double.getVehicleType() == vehicle_type_double);
    assert(uber_driver_double_double.getTotalMiles() == 150.5);

    // Test cases for UberEats
    std::string food_type_str = "Pizza";
    char food_type_char = 'B';

    UberEats<std::string, std::string, std::string> uber_eats_driver_str(employee_id_str, employee_name_str, vehicle_type_str, food_type_str);

    uber_eats_driver_str.addMiles(50);
    assert(uber_eats_driver_str.getEmployeeId() == employee_id_str);
    assert(uber_eats_driver_str.getEmployeeName() == employee_name_str);
    assert(uber_eats_driver_str.getFoodType() == food_type_str);
    assert(uber_eats_driver_str.getTotalMiles() == 50);

    //    UberEats<std::string, std::string, std::string> uber_eats_driver(employee_id, employee_name, vehicle_type, food_type);
    // template <typename EmployeeIdType, typename VehicleType, typename FoodType>
    UberEats<int, int, char> uber_eats_driver_char(employee_id_int, employee_name_str, vehicle_type_int, food_type_char);
    uber_eats_driver_char.addMiles(75);
    assert(uber_eats_driver_char.getEmployeeId() == employee_id_int);
    assert(uber_eats_driver_char.getEmployeeName() == employee_name_str);
    assert(uber_eats_driver_char.getFoodType() == food_type_char);
    assert(uber_eats_driver_char.getTotalMiles() == 75);

    std::cout << "All test cases passed." << std::endl;

    try {
        uber_eats_driver_char.addMiles(-75);
    } catch (runtime_error& e) {
        string msg = e.what();
        assert(msg == "Mileage can't be negative.");
    }
    return 0;
}
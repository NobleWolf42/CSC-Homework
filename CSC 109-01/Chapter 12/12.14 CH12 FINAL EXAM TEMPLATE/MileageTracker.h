/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef MILEAGETRACKERH
#define MILEAGETRACKERH

#include <string>
#include <stdexcept>

template <typename EmployeeIdType>
class MileageTracker {
    private:
	    EmployeeIdType employeeId;
        std::string employeeName;
        double totalMiles;

    public:

	    MileageTracker(EmployeeIdType employeeId, std::string employeeName) {
            this->employeeId = employeeId;
            this->employeeName = employeeName;
            totalMiles = 0;
        }// - Constructor to initialize the employee ID and name.

        void addMiles(double miles) {
            if (miles < 0) {
                throw(std::runtime_error("Mileage can't be negative."));
            }
            totalMiles += miles;
        }// - Method to add miles to the total mileage.

        EmployeeIdType getEmployeeId() {
            return employeeId;
        }// - Method to get the employee ID.
        
        std::string getEmployeeName() {
            return employeeName;
        }// - Method to get the employee name.
        
        double getTotalMiles() {
            return totalMiles;
        }// - Method to get the total miles.
};

#endif

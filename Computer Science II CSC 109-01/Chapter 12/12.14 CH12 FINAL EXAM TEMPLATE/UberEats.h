/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef UBEREATSH
#define UBEREATSH

#include "Uber.h"

template <typename EmployeeIdType, typename VehicleType, typename FoodType>
class UberEats : public Uber<EmployeeIdType, VehicleType> {
    private:
        
        FoodType foodType;
	
    public:
        
        UberEats(EmployeeIdType employeeId, std::string employeeName, VehicleType newVehicleType, FoodType foodType)  :  Uber<EmployeeIdType, VehicleType>(employeeId, employeeName, newVehicleType) {
            this->foodType = foodType;
        }// - Constructor to initialize employee ID, name, vehicle type, and food type.

        FoodType getFoodType() {
            return foodType;
        }// - Method to get the food type.

        void setFoodType(FoodType newFoodType) {
            this->foodType = newFoodType;
        }// - Method to set the food type.


};

#endif

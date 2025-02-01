/*
Author: Ben Carpenter
Copyright: 2024
*/

#ifndef UBERH
#define UBERH

#include "MileageTracker.h"

template <typename EmployeeIdType, typename VehicleType>
class Uber : public MileageTracker<EmployeeIdType> {
    private:
        
        VehicleType vehicleType;
	
    public:
        
        Uber(EmployeeIdType employeeId, std::string employeeName, VehicleType vehicleType)  :  MileageTracker<EmployeeIdType>(employeeId, employeeName) {
            this->vehicleType = vehicleType;            
        }// - Constructor to initialize employee ID, name, and vehicle type.

        VehicleType getVehicleType() {
            return vehicleType;
        }// - Method to get the vehicle type.

        void setVehicleType(VehicleType newVehicleType) {
            this->vehicleType = newVehicleType;
        }// - Method to set the vehicle type.
};

#endif

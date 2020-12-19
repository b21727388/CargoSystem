//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_TRUCKS_H
#define ASSIGNMENT_3_TRUCKS_H

#include "Packages.h"

class Trucks : public Packages{
public:
    const string &getTruckName() const;

    void setTruckName(const string &truckName);

    const string &getTruckInitialPosition() const;

    void setTruckInitialPosition(const string &truckInitialPosition);

    const string &getFloatNumberOfTruck() const;

    void setFloatNumberOfTruck(const string &floatNumberOfTruck);

private:
    string truckName;
    string truckInitialPosition;
    string floatNumberOfTruck;
};

const string &Trucks::getTruckName() const {
    return truckName;
}

void Trucks::setTruckName(const string &truckName) {
    Trucks::truckName = truckName;
}

const string &Trucks::getTruckInitialPosition() const {
    return truckInitialPosition;
}

void Trucks::setTruckInitialPosition(const string &truckInitialPosition) {
    Trucks::truckInitialPosition = truckInitialPosition;
}

const string &Trucks::getFloatNumberOfTruck() const {
    return floatNumberOfTruck;
}

void Trucks::setFloatNumberOfTruck(const string &floatNumberOfTruck) {
    Trucks::floatNumberOfTruck = floatNumberOfTruck;
}


#endif //ASSIGNMENT_3_TRUCKS_H

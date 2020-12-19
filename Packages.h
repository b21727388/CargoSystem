//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_PACKAGES_H
#define ASSIGNMENT_3_PACKAGES_H
#include <string>
#include <iostream>

using namespace std;

class Packages{
public:
    const string &getPackageName() const;

    void setPackageName(const string &packageName);

    const string &getPackageInitialStation() const;

    void setPackageInitialStation(const string &packageInitialStation);

private:
    string packageName;
    string packageInitialStation;
};

const string &Packages::getPackageName() const {
    return packageName;
}

void Packages::setPackageName(const string &packageName) {
    Packages::packageName = packageName;
}

const string &Packages::getPackageInitialStation() const {
    return packageInitialStation;
}

void Packages::setPackageInitialStation(const string &packageInitialStation) {
    Packages::packageInitialStation = packageInitialStation;
}

#endif //ASSIGNMENT_3_PACKAGES_H

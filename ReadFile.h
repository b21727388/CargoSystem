//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_READFILE_H
#define ASSIGNMENT_3_READFILE_H
#include <string>
#include <fstream>
#include <sstream>
#include "Dests.h"


using namespace std;

class ReadFile {
public:
    static void ReadDestsFile(string destsPath, Dests destList[]);
    static void ReadPackagesFile(string packagesPath, Dests destList[], int destSize);
    static void ReadTrucksFile(string trucksPath, Dests destList[], int destSize);
};


/*
 * ReadDestsFile function creates destList as many lines as the dest.txt file and each element of the destList is one of the Station.
 */
void ReadFile::ReadDestsFile(string destsPath, Dests destList[]) {
    int lineCounter = 0;
    ifstream file(destsPath);
    string str;
    while(getline(file, str)){
        destList[lineCounter].destName = str;
        lineCounter++;
    }
}

/*
 * ReadPackagesFile function splits every line of the package.txt and starts to create initial position of the packages.
 * If the package has a station name which is one of the destList element than package goes to that station
 */
void ReadFile::ReadPackagesFile(string packagesPath, Dests destList[], int destSize) {
    int counter = 0;
    ifstream file(packagesPath);
    string str;

    Packages packageList;

    /*
     * splitting every line of the package.txt by space character.
     */
    while (getline(file, str)) {
        std::istringstream ss(str);
        std::string token;
        std::string lineArray[2];
        while (std::getline(ss, token, ' ')) {

            lineArray[counter++] = token;
        }

        /*
         * there is a package list which is holding all packages in an order.
         */
        packageList.setPackageName(lineArray[0]);
        packageList.setPackageInitialStation(lineArray[1]);

        /*
         * pushing package to the dest for the initial position.
         */
        for(int i = 0; i < destSize; i++) {
            if(destList[i].destName == lineArray[1]){
                destList[i].packageHead.push(lineArray[0]);
            }else{ continue; }
        }

        counter = 0;
    }

}

/*
 * ReadTrucksFile function splits every line of the trucks.txt and starts to create initial position of the trucks.
 * If the truck has a station name which is one of the destList element than truck goes to that station.
 */
void ReadFile::ReadTrucksFile(string trucksPath, Dests destList[], int destSize) {
    int counter = 0;

    ifstream file(trucksPath);
    string str;

    Trucks truckList;

    /*
     * splitting every line of the trucks.txt by space character.
     */
    while (getline(file, str)){
        std::istringstream ss(str);
        std::string token;
        std::string lineArray[3];
        while(std::getline(ss, token, ' ')) {

            lineArray[counter++] = token;
        }

        /*
         * there is a truck list which is holding all trucks in an order.
         */
        truckList.setTruckName(lineArray[0]);
        truckList.setTruckInitialPosition(lineArray[1]);
        truckList.setFloatNumberOfTruck(lineArray[2]);

        /*
         * pushing package to the dest for the initial position.
         */
        for(int i = 0; i < destSize; i++) {
            if(destList[i].destName == lineArray[1]){
                destList[i].truckHead.enqueue(lineArray[0]);
            }else{ continue; }
        }

        counter = 0;
    }
}




#endif //ASSIGNMENT_3_READFILE_H

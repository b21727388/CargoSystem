//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_STARTMISSION_H
#define ASSIGNMENT_3_STARTMISSION_H
#include <string>
#include "Dests.h"

using namespace std;

class StartMission{
public:
    static int howManyStation(string destsPath);
    static int midwayPackageCount(string packageLine);
    static void MissionFunction(string missionsPath, Dests destList[], int destSize);
};

int StartMission::howManyStation(string destsPath){
    /*
     * This function returns how many line does the dests.txt file has.
     */

    int lineCounter = 0;
    ifstream file(destsPath);
    string str;
    while (getline(file, str)){
        lineCounter++;
    }
    return lineCounter;
}


int StartMission::midwayPackageCount(string packageLine){
    /*
     * This function returns how many packages will be leaving in the middle station.
     */

    int counter = 0;
    istringstream ss(packageLine);
    string token;
    while(std::getline(ss, token, ',')) {
        counter++;
    }

    return counter;
}

void StartMission::MissionFunction(string missionsPath, Dests *destList, int destSize) {

    /*
     * This struct operation for the Truck and the Packages. This will be node for our double linked-list.
     */
    struct TruckGarage{
        string packageName;
        int indice;
        TruckGarage *next = NULL;
        TruckGarage *prev = NULL;
    };

    int counter = 0; // for the list index to split mission.txt's line.

    /*
     * this variable declarations is for saving splitted words from missions' file.
     */
    string mainStation;
    string midwayStation;
    string lastStation;
    int startingPackageNum;
    int midwayPackageNum;
    string leaveThisPackageOnMidway;


    ifstream file(missionsPath);
    string str;

    while (getline(file, str)){  // This is the outer While loop and this loop is executing every line of the missions' file.

        //This while loop and the variable above the loop are for the splitting every line of the missions' file by '-' .
        istringstream ss(str);
        string token;
        string lineArray[6];
        while(std::getline(ss, token, '-')) {

            lineArray[counter++] = token;
        }


        /*
         * initializing variables with missions' file.
         */
        mainStation = lineArray[0];
        midwayStation = lineArray[1];
        lastStation = lineArray[2];
        startingPackageNum = stoi(lineArray[3]);
        midwayPackageNum = stoi(lineArray[4]);
        leaveThisPackageOnMidway = lineArray[5];



        int counter2 = 0;
        istringstream ss2(leaveThisPackageOnMidway);
        string token2;
        int leaving_packgae_num_on_mid = midwayPackageCount(leaveThisPackageOnMidway);
        int lineArray2[leaving_packgae_num_on_mid];
        int indiceCount = 0;
        bool destBulunduMu = false; //this going to use for breaking for loop.

        /*
         * this while loop is going to split 'z' variable on the mission file.
         */
        while(std::getline(ss2, token2, ',')) {

            lineArray2[counter2++] = stoi(token2);
        }

        TruckGarage *Truck = new TruckGarage();

        /*
         * First for loop is going to take packages and the truck from the starting station.
         */
        for(int i = 0; i < destSize; i++){
            if(destList[i].destName == mainStation && !destBulunduMu){
                destBulunduMu = true;
                Truck->packageName = destList[i].truckHead.takeFromFront();
                Truck->indice = -1;
                destList[i].truckHead.dequeue();

                for(int j = 0; j < startingPackageNum; j++){
                    TruckGarage *temp;
                    TruckGarage *pack = new TruckGarage();
                    pack->packageName = destList[i].packageHead.takeFromFront();
                    pack->indice = indiceCount++;
                    if(Truck->next == NULL){
                        Truck->next = pack;
                        pack->prev = Truck;
                    }else{
                        temp = Truck;
                        while(temp->next != NULL){
                            temp = temp->next;
                        }
                        temp->next = pack;
                        pack->prev = temp;
                    }

                    destList[i].packageHead.pop();

                }
            }
        }
        destBulunduMu = false;

        /*
         * Second for loop is going to take next packages from middle station and leave predetermined packages to the middle station.
         */
        for(int i = 0; i < destSize; i++){
            if(destList[i].destName == midwayStation && !destBulunduMu){

                destBulunduMu = true;
                TruckGarage *temp = Truck;
                for(int j = 0; j < midwayPackageNum; j++){
                    TruckGarage *temp;
                    TruckGarage *pack = new TruckGarage();
                    pack->packageName = destList[i].packageHead.takeFromFront();
                    pack->indice = indiceCount++;
                    if(Truck->next == NULL){
                        Truck->next = pack;
                        pack->prev = Truck;
                    }else{
                        temp = Truck;
                        while(temp->next != NULL){
                            temp = temp->next;
                        }
                        temp->next = pack;
                        pack->prev = temp;
                    }

                    destList[i].packageHead.pop();

                }
                for(int j = 0; j < leaving_packgae_num_on_mid; j++){
                    temp = Truck;
                    while(temp->indice != lineArray2[j]){
                        temp = temp->next;
                    }
                    if(temp->indice == lineArray2[j]){
                        destList[i].packageHead.push(temp->packageName);
                        if(temp->next != NULL) {
                            (temp->prev)->next = temp->next;
                            (temp->next)->prev = temp->prev;
                        }else{
                            (temp->prev)->next = NULL;
                        }
                    }else{
                        cout << "Aradiginiz package bulunamadi.";
                    }
                }
            }
        }
        destBulunduMu = false;

        /*
         * Third for loop is going to leave other packages which is remaining in the truck to the last station and puts truck to the last station's garage.
         */
        for(int i = 0; i < destSize; i++){
            if(destList[i].destName == lastStation && !destBulunduMu){
                destBulunduMu = true;
                TruckGarage *temp = Truck->next;
                while(temp != NULL){
                    destList[i].packageHead.push(temp->packageName);
                    temp = temp->next;
                }
                destList[i].truckHead.enqueue(Truck->packageName);
            }
        }
        counter = 0;
    }
}


#endif //ASSIGNMENT_3_STARTMISSION_H

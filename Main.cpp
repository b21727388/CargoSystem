#include <iostream>
#include "ReadFile.h"
#include "StartMission.h"

int main(int argc, char** argv) {
    freopen(argv[5], "w",stdout);
    int destSize = StartMission::howManyStation(argv[1]);
    Dests destList[destSize];

    ReadFile::ReadDestsFile(argv[1], destList);
    ReadFile::ReadPackagesFile(argv[2], destList, destSize);
    ReadFile::ReadTrucksFile(argv[3], destList, destSize);
    StartMission::MissionFunction(argv[4], destList, destSize);

    /*
     * creates output file with a given order.
     */
    for(Dests d: destList){
        cout<< d.destName<< endl;
        cout << "Packages:"<< endl;
        d.packageHead.displayStack();
        cout << "Trucks:" << endl;
        d.truckHead.displayQueue();
        cout << "-------------" << endl;
    }
    return 0;
}

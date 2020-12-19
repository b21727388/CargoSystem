//
// Created by Beşir Kassab on 11.12.2020.
//

#ifndef ASSIGNMENT_3_DESTS_H
#define ASSIGNMENT_3_DESTS_H
#include "Stack.h"
#include "Queue.h"
#include "Trucks.h"
#include<bits/stdc++.h>

using namespace std;

class Dests{
public:
    string destName;
    Stack<string> packageHead;
    Queue<string> truckHead;
};




#endif //ASSIGNMENT_3_DESTS_H

/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * < Danette Garrido, Joseph Nunez, Nadia Jahan, Nakayla Butler >
 * < danetteg, jsnunez, mosjah, nakaylab >
 *
 * Final Project - Elevators
 */

#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    char aChar;
    isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;

    if (commandString.size() <= 0) {
        isPass = true;
    }
    else if (commandString == "S" || commandString == "s") {        
        isSave = true;
    }
    else if (commandString == "q" || commandString == "Q") {
        isQuit = true;
    }
    else {
        stringstream ss(commandString);
        ss >> aChar >> elevatorId >> aChar;
        if (aChar == 'f') {
            ss >> targetFloor;
        }
        else if (aChar == 'p') {
            isPickup = true;
        }
    }
}
bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    bool validityCheck = false;
    // valid moves
    if ((isPass == true) || (isQuit == true) || (isSave == true)) {
        validityCheck = true;
    }
    // when elevator is not servicing request
    else if ((elevatorId < NUM_ELEVATORS) && (elevatorId >= 0)
        && (!elevators[elevatorId].isServicing())) {
        if (isPickup == true) {
            validityCheck = true;
        }
        // for servicing moves
        else if ((targetFloor >= 0) && (targetFloor < NUM_FLOORS)
            && (targetFloor != elevators[elevatorId].getCurrentFloor())) {
            validityCheck = true;
        }
    }
    return validityCheck;
}

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {
    int farDistance = 0;

    for (int i = 0; i < pickupList.size(); ++i) {
        int index = pickupList.at(i) - '0';
        peopleToPickup[numPeopleToPickup] = index;
        ++numPeopleToPickup;

        totalSatisfaction += (MAX_ANGER - pickupFloor.getPersonByIndex(index).getAngerLevel());

        int personTargetFloor =
            pickupFloor.getPersonByIndex(index).getTargetFloor();
        int diffTargetFloor = abs(currentFloor - personTargetFloor);

        if (diffTargetFloor > farDistance) {
            farDistance = abs(currentFloor - personTargetFloor);
            targetFloor = personTargetFloor;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
    return isPass;
}

bool Move::isSaveMove() const {
    return isSave;
}

bool Move::isQuitMove() const {
    return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Elevator.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * < Danette Garrido, Joseph Nunez, Nadia Jahan, Nakayla Butler >
 * < danetteg, jsnunez, mosjah, nakaylab >
 *
 * Final Project - Elevators
 */

#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime) {
    bool s = isServicing();
    if (s && (currentTime % TICKS_PER_ELEVATOR_MOVE == 0)) {
        if ((targetFloor - currentFloor) < 0) {
            setCurrentFloor(currentFloor - 1);
        }
        if ((targetFloor - currentFloor) > 0) {
            setCurrentFloor(currentFloor + 1);
        }
    }
    if (currentFloor == targetFloor) {
        servicing = false;
    }
}

void Elevator::serviceRequest(int floorNum) {
    //TODO: Implement serviceRequest
    targetFloor = floorNum;
    servicing = true;
}


//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream& outs) {
    outs << currentFloor;
    if (!servicing) {
        outs << "w";
    }
    else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
    targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
    return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
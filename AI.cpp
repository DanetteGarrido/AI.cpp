/*
 * Copyright 2022 University of Michigan EECS183
 *
 * AI.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * < Danette Garrido, Joseph Nunez, Nadia Jahan, Nakayla Butler >
 * < danetteg, jsnunez, mosjah, nakaylab >
 *
 * Final Project - Elevators
 */

#include "AI.h"
#include <cassert>


int peopleInBuilding(const BuildingState& buildingState) {
    int numPeopleInBuilding = 0;
    for (int i = 0; i < 10; i++) {
        numPeopleInBuilding += buildingState.floors[i].numPeople;
    }
    if (numPeopleInBuilding == 0) {
        return 0;
    }
    else {
        return 1;
    }
}

// if the building is empty, return empty string
string emptyBuilding(const BuildingState& buildingState){
        bool peeps = false;
        for (int j = 0; j < NUM_FLOORS; j++){
           _Floor floor = buildingState.floors[i];
            if (floor.numPeople != 0){
                peeps = true;
            }
        }
        if (peeps == false){
            return "";
        }
}
//if the elevator has people on its floor and it isn't servicing
string serviceReadyID(const BuildingState& buildingState){
    int openElevatorID = 0;

     for (int i = 0; i < NUM_ELEVATORS; i++) {
          openElevatorID = i;
         _Elevator elevator = buildingState.elevators[i];
     if (buildingState.floors[elevator.currentFloor].numPeople > 0 && !elevator.isServicing) {
          if (i == 1) {
            return "e1p";
        }
        if (i == 2){
            return "e2p";
        }
        if (i == 0) {
            return "e0p";
        }
    }
    int openElevatorID;
}
    
bool isElevatorServicing(const BuildingState& buildingState, int FID) {
    // floor ID
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        if (buildingState.elevators[i].isServicing && buildingState.elevators[i].targetFloor == FID) {
            return true;
        }
    }
    return false;
}
string getAIMoveString(const BuildingState& buildingState) {
   int available[3];
    int numElevator = 0;

    if (numElevator <= 0) {
        return "";
    }

    if (!peopleInBuilding(buildingState)) {
        return "";
    }

    // incorporate urgent function before vv
    if (!isElevatorServicing(buildingState, available[numElevator])) {
        for (int i = 0; i < 3; i++) {
            available[numElevator] = buildingState.elevators[i].elevatorId;
            numElevator += 1;
        }
    }
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    return "";
}

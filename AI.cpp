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


//if the elevator has people on its floor and it isn't servicing
int serviceReadyID(const BuildingState& buildingState){
    int openElevatorID = 0;

     for (int i = 0; i < NUM_ELEVATORS; i++) {
          openElevatorID = i;
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

string getAIMoveString(const BuildingState& buildingState) {
    if (!peopleInBuilding) {
        return "";
    }
    if (urgentFloor) {
        return 
    }
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    return "";
}

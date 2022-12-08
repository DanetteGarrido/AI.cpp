/*
 * Copyright 2022 University of Michigan EECS183
 *
 * AI.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * <#Names#>
 * <#Uniqnames#>
 *
 * Final Project - Elevators
 */

#include "AI.h"
#include <cassert>

// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core

string getAIMoveString(const BuildingState& buildingState) {
     int peopleInBuilding = 0;
    for (int i = 0; i < 10; i++) {
    }
    if (peopleInBuilding == 0) {
        return "";
    }
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    return "";
}


// have an hierarchy, first angriest, most requests, most people
//figure out possible cases, can't have elvators in the same floor
//- building is empty
// - angry
// - people per floor
// 
// have code that creates the string then worry abt changing the variables
// break it into parts
// you can have a bool

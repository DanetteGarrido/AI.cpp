/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Floor.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * < Danette Garrido, Joseph Nunez, Nadia Jahan, Nakayla Butler >
 * < danetteg, jsnunez, mosjah, nakaylab >
 *
 * Final Project - Elevators
 */


#include "Floor.h"

using namespace std;

int Floor::tick(int currentTime) {
    int x [MAX_PEOPLE_PER_FLOOR];
    int y = 0;
    int numExploded = 0;
    for (int i = 0; i < numPeople; i++) {
        if (people[i].tick(currentTime)) {
            numExploded++;
            x[y] = i;
            removePeople(x, numExploded);
            i--;
        }
    }
    //returning 0 to prevent compilation error
    return numExploded;
}

void Floor::addPerson(Person newPerson, int request) {
    //TODO: Implement addPerson
    if (numPeople < MAX_PEOPLE_PER_FLOOR) {
        people[numPeople] = newPerson;
        numPeople++;
        if (request > 0) {
            setHasUpRequest(true);

        }
        else if (request < 0) {
            setHasDownRequest(true);
        }
    }
}

void Floor::removePeople(int indicesToRemove[MAX_PEOPLE_PER_FLOOR], int numPeopleToRemove) {
    //TODO: Implement removePeople
    Person temp[MAX_PEOPLE_PER_FLOOR];
    int numCopiedPeople = 0;
    bool copyPerson;
    for (int i = 0; i < numPeople; i++) {
        copyPerson = false;
        for (int j = 0; j < numPeopleToRemove; j++) {
            if (i == indicesToRemove[j]) {
                copyPerson = true;
            }
        }
        if (copyPerson == false) {
            temp[numCopiedPeople] = people[i];
            numCopiedPeople++;
        }
    }
    for (int k = 0; k < numPeople; k++) {
        people[k] = temp[k];
    }
    numPeople -= numPeopleToRemove;
    resetRequests();
}

void Floor::resetRequests() {
    //TODO: Implement resetRequests
    hasDownRequest = false;
    hasUpRequest = false;
    for (int i = 0; i < numPeople; i++) {
        if ((people[i].getTargetFloor() - people[0].getCurrentFloor()) < 0) {
            hasUpRequest = true;
        }
        if ((people[i].getTargetFloor() - people[i].getCurrentFloor()) > 0) {
            hasDownRequest = true;
        }
    }
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Floor::Floor() {
    hasDownRequest = false;
    hasUpRequest = false;
    numPeople = 0;
}

void Floor::prettyPrintFloorLine1(ostream& outs) const {
    string up = "U";
    outs << (hasUpRequest ? up : " ") << " ";
    for (int i = 0; i < numPeople; ++i) {
        outs << people[i].getAngerLevel();
        outs << ((people[i].getAngerLevel() < MAX_ANGER) ? "   " : "  ");
    }
    outs << endl;
}

void Floor::prettyPrintFloorLine2(ostream& outs) const {
    string down = "D";
    outs << (hasDownRequest ? down : " ") << " ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "o   ";
    }
    outs << endl;
}

void Floor::printFloorPickupMenu(ostream& outs) const {
    cout << endl;
    outs << "Select People to Load by Index" << endl;
    outs << "All people must be going in same direction!";
    /*  O   O
    // -|- -|-
    //  |   |
    // / \ / \  */
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " O   ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "-|-  ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " |   ";
    }
    outs << endl << "              ";
    for (int i = 0; i < numPeople; ++i) {
        outs << "/ \\  ";
    }
    outs << endl << "INDEX:        ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << i << "   ";
    }
    outs << endl << "ANGER:        ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << people[i].getAngerLevel() << "   ";
    }
    outs << endl << "TARGET FLOOR: ";
    for (int i = 0; i < numPeople; ++i) {
        outs << " " << people[i].getTargetFloor() << "   ";
    }
}

void Floor::setHasUpRequest(bool hasRequest) {
    hasUpRequest = hasRequest;
}

bool Floor::getHasUpRequest() const {
    return hasUpRequest;
}

void Floor::setHasDownRequest(bool hasRequest) {
    hasDownRequest = hasRequest;
}

bool Floor::getHasDownRequest() const {
    return hasDownRequest;
}

int Floor::getNumPeople() const {
    return numPeople;
}

Person Floor::getPersonByIndex(int index) const {
    return people[index];
}
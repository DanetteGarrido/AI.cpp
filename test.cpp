/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

// declare your test functions here
void person_tests();
void elevator_tests();
void file_check();

void start_tests() {
    file_check();
    person_tests();
    elevator_tests();
    return;
}

void file_check() {
    // open one of the text files that are part of the starter code
    ifstream ins;
    ins.open("new.in");
    // if the file was not in the correct directory, the stream state is fail
    if (ins.fail()) {
        cout << "Could not open new.in" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    return;
}

void person_tests() {
    cout << endl << "PERSONS TESTS" << endl;

    //initialize a person with targetFloor 5, anger 5
    Person p("0f0t5a5");
    p.print(cout);
    cout << endl;
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;

    //simulate time being a multiple of TICKS_PER_ANGER_INCREASE
    bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 0" << endl;
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;

    //simulate time not being a multiple
    p.tick(TICKS_PER_ANGER_INCREASE - 1);

    //no change
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
    p.tick(TICKS_PER_ANGER_INCREASE); //7 after
    p.tick(TICKS_PER_ANGER_INCREASE); //8 after
    p.tick(TICKS_PER_ANGER_INCREASE); //9 after
    exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 1" << endl;
    cout << endl;
    
    Person p1("7f4t8a3");
    p1.print(cout);
    cout << endl;
    cout << p1.getTargetFloor() << " " << p1.getAngerLevel() << " Expected 8 3" << endl;
    cout << p1.getTurn() << " Expected 7" << endl;
    cout << p1.getTurn() << endl;
    cout << p1.getCurrentFloor() << endl;

    cout << exploded << " Expected 1" << endl;
    cout << p1.getTargetFloor() << " " << p1.getAngerLevel() << " Expected 7 10" << endl;
    p1.print(cout);
    cout << endl;

}

void elevator_tests() {
    cout << "Elevators Tests" << endl;
    // NOTE - there is an Elevator::print function!
    // this will not find any of the bugs for the lab assignment
    Elevator e1;
    e1.print(cout);
        cout << endl;

    e1.serviceRequest(4);
    e1.print(cout);
        cout << endl;
    e1.tick(1);
    e1.print(cout);
        cout << endl;
    e1.tick(2);
    e1.print(cout);
        cout << endl;
    e1.tick(3);
    e1.print(cout);
        cout << endl;
    e1.tick(4);
    e1.print(cout);
        cout << endl;
    e1.tick(5);
    e1.print(cout);
        cout << endl;
    
    e1.isServicing();
    e1.setCurrentFloor(5);
    e1.tick(5);
    e1.print(cout);
        cout << endl;
    cout << e1.getCurrentFloor() << endl;
    cout << e1.getTargetFloor() << endl;

    Elevator e2;
    cout << endl << "e2: "  << endl << e2.getCurrentFloor() << endl;
    cout << e2.getTargetFloor() << endl;
    e2.isServicing();
    e2.setCurrentFloor(6);
    e2.print(cout);
    cout << endl;
    e2.serviceRequest(6);
    e2.print(cout);
    cout << endl;

    e2.tick(1);
    e2.print(cout);
    cout << endl;

    e2.tick(2);
    e2.print(cout);
    cout << endl;

    e2.tick(3);
    e2.print(cout);
    cout << endl;

    e2.tick(4);
    e2.print(cout);
    cout << endl;

    e2.tick(5);
    e2.print(cout);
    cout << endl;

    return;
}



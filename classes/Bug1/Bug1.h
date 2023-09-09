#pragma once

#include <list>
#include <tuple>
#include "../Robot/Robot.h"
#include "../Goal/Goal.h"

class Bug1{
public:
    // Constructors and Destructors
    Bug1(Robot r);
    ~Bug1();

    // Member Functions
    void execute();

    // Member Variables
    Robot robot;
    std::list<std::tuple<int, int, float> > path;
    float dMin;

};
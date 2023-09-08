#pragma once

#include <list>
#include "../Robot/Robot.h"
#include "../Goal/Goal.h"

class Bug1{
public:
    // Constructors and Destructors
    Bug1(Robot r, Goal g);
    ~Bug1();

    // Member Functions
    void moveForwards(); // moves in body x direction
    void moveBackwards(); // moves in body -x direction
    void rotate(float radians); // ccw positive

    // Member Variables
    std::list<std::pair<int, int> > vertices;
    std::pair<int, int> iPosition;
};
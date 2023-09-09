#pragma once

#include <list>
#include <tuple>
#include "../Goal/Goal.h"

class Robot{
public:
    // Constructors and Destructors
    Robot(int w, int h, std::tuple<int, int, float> iP, Goal* g);
    ~Robot();

    // Member Functions
    void moveForwards(); // moves in body x direction
    void moveBackwards(); // moves in body -x direction
    void rotate(float radians); // ccw positive
    void sense(); // sense to see if contacting obstacle
    std::pair<float, float> smell(); // smell to see direction to goal

    // Member Variables
    int width;
    int height;
    std::tuple<int, int, float> iPos; // intertial position and orientation
    Goal* pGoal;
};
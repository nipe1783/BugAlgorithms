#pragma once

#include <list>

class Robot{
public:
    // Constructors and Destructors
    Robot(int w, int h);
    ~Robot();

    // Member Functions
    void moveForwards(); // moves in body x direction
    void moveBackwards(); // moves in body -x direction
    void rotate(float radians); // ccw positive
    void sense(); // sense to see if contacting obstacle
    void smell(); // smell to see direction to goal

    // Member Variables
    int width;
    int height;
};
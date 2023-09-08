#pragma once

#include <list>

class Obstacle{
public:
    // Constructors and Destructors
    Obstacle(std::list<std::pair<int, int> > v);
    ~Obstacle();

    // Member Functions

    // Member Variables
    std::list<std::pair<int, int> > vertices;
};
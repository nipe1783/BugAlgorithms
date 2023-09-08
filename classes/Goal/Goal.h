#pragma once

#include <list>

class Goal{
public:
    // Constructors and Destructors
    Goal(std::list<std::pair<int, int> > v);
    ~Goal();

    // Member Functions

    // Member Variables
    std::list<std::pair<int, int> > vertices;
    std::pair<int, int> iPosition;
};
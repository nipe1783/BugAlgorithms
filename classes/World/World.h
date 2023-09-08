#pragma once

#include <list>
#include <SDL.h>
#include "../Robot/Robot.h"
#include "../Goal/Goal.h"

class World {
public:
    // Constructors and Destructors
    World(int w, int h, Robot r, std::list<std::pair<int, int> > rV, Goal g);
    ~World();


    // Member Functions
    void addObstacle(std::list<std::pair<int, int> > obstacle);
    void drawObstacles();
    void drawRobot();
    void drawGoal();

    // Member Variables
    int width;
    int height;
    std::list<std::list<std::pair<int, int> > > obstacles;
    Robot robot;
    std::list<std::pair<int, int> > robotVertices; // inertial robot vertex positions
    Goal goal;
    SDL_Window* window;
    SDL_Renderer* renderer;


protected:
    // Protected member variables and functions (if any)

private:
    // Private member variables and functions (if any)
};
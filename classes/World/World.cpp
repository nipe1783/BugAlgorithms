#include "World.h"
#include <iostream>
#include <list>

World::World(int w, int h) : width(w), height(h) {
    window = SDL_CreateWindow("Dynamic Window",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              width,
                              height,
                              SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

World::~World() {
}

void World::addObstacle(std::list<std::pair<int, int> > obstacle) {
    obstacles.push_back(obstacle);
}

void World::drawObstacles(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    for(std::list<std::pair<int, int>>& obstacle : obstacles){
        for(std::list<std::pair<int, int>>::iterator it = obstacle.begin(); it != obstacle.end(); it++){
            std::pair<int, int> currentPoint = *it;

            std::list<std::pair<int, int>>::iterator nextIt = it;
            ++nextIt;

            std::pair<int, int> nextPoint;
            if (nextIt == obstacle.end()) {
                nextPoint = *obstacle.begin();
            } else {
                nextPoint = *nextIt;
            }

            SDL_RenderDrawLine(renderer, currentPoint.first, currentPoint.second, nextPoint.first, nextPoint.second);
        }
    }
}

void World::addRobot(std::list<std::pair<int, int> > robot) {
    this->robot = robot;
}

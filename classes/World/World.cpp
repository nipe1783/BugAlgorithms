#include "World.h"
#include <iostream>
#include <list>
#include "../Robot/Robot.h"
#include "../Goal/Goal.h"

World::World(int w, int h, Robot r, std::list<std::pair<int, int> > rV, Goal g) : width(w), height(h), robot(r), robotVertices(rV), goal(g){
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

void World::drawRobot(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    for(std::list<std::pair<int, int>>::iterator it = robotVertices.begin(); it != robotVertices.end(); it++){
            std::pair<int, int> currentPoint = *it;

            std::list<std::pair<int, int>>::iterator nextIt = it;
            ++nextIt;

            std::pair<int, int> nextPoint;
            if (nextIt == robotVertices.end()) {
                nextPoint = *robotVertices.begin();
            } else {
                nextPoint = *nextIt;
            }

            SDL_RenderDrawLine(renderer, currentPoint.first, currentPoint.second, nextPoint.first, nextPoint.second);
    }
}

void World::drawGoal(){
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);
    for(std::list<std::pair<int, int>>::iterator it = goal.vertices.begin(); it != goal.vertices.end(); it++){
            std::pair<int, int> currentPoint = *it;

            std::list<std::pair<int, int>>::iterator nextIt = it;
            ++nextIt;

            std::pair<int, int> nextPoint;
            if (nextIt == goal.vertices.end()) {
                nextPoint = *goal.vertices.begin();
            } else {
                nextPoint = *nextIt;
            }

            SDL_RenderDrawLine(renderer, currentPoint.first, currentPoint.second, nextPoint.first, nextPoint.second);
    }
}

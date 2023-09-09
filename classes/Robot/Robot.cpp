#include "Robot.h"
#include "../Goal/Goal.h"
#include <iostream>

Robot::Robot(int w, int h, std::tuple<int, int, float> iP, Goal* g) : width(w), height(h), iPos(iP), pGoal(g){
}

Robot::~Robot() {
}

void Robot::moveForwards() {
    std::cout << "Moving forwards" << std::endl;
}

void Robot::moveBackwards() {
    std::cout << "Moving backwards" << std::endl;
}

void Robot::rotate(float radians) {
    std::cout << "Rotating " << radians << " radians" << std::endl;
}

void Robot::sense() {
    std::cout << "Sensing" << std::endl;
}

std::pair<float, float> Robot::smell() {
    
}
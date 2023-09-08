#include "Robot.h"
#include <iostream>

Robot::Robot(int w, int h) : width(w), height(h) {
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

void Robot::smell() {
    std::cout << "Smelling" << std::endl;
}
#include <iostream>
#include <SDL.h>
#include "classes/World/World.h"
#include "classes/Robot/Robot.h"
#include "classes/Obstacle/Obstacle.h"
#include "classes/Goal/Goal.h"
#include <list>

int main(int argc, char const *argv[])
{
    int width = 1000;
    int height = 1000;
    int SQUARE_SIZE = 100;
    std::list<std::pair<int, int> > obstacle = {{100, 100}, {150, 100}, {150, 150}, {100, 150}};
    Goal goal({{900, 900}, {910, 900}, {910, 910}, {900, 910}});
    Robot robot(10,10, {550, 550, 0}, &goal);
    World world(width, height, robot, goal);
    world.addObstacle(obstacle);

    SDL_Init(SDL_INIT_VIDEO);  // Initialize the SDL2 video subsystem
    bool quit = false;
    SDL_Event e;
    while (!quit) {

        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }


        // perform movement:
        

        // Clear screen (black background)
        SDL_SetRenderDrawColor(world.renderer, 0, 0, 0, 255);
        SDL_RenderClear(world.renderer);
        // Draw the obstacles
        world.drawObstacles();
        // Draw the robot
        world.drawRobot();
        // Draw the goal
        world.drawGoal();
        // Update the screen
        SDL_RenderPresent(world.renderer);
    }

    SDL_DestroyRenderer(world.renderer);
    SDL_DestroyWindow(world.window);
    SDL_Quit();

    return 0;
}

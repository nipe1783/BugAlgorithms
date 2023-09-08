#include <iostream>
#include <SDL.h>
#include "classes/World/World.h"
#include <list>

int main(int argc, char const *argv[])
{
    int width = 1000;
    int height = 1000;
    int SQUARE_SIZE = 100;
    std::list<std::pair<int, int> > obstacle = {{100, 100}, {200, 100}, {200, 200}, {100, 200}};
    World world(width, height);
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

        // Clear screen (black background)
        SDL_SetRenderDrawColor(world.renderer, 0, 0, 0, 255);
        SDL_RenderClear(world.renderer);

        // Draw the obstacles
        world.drawObstacles();

        // Update the screen
        SDL_RenderPresent(world.renderer);
    }

    SDL_DestroyRenderer(world.renderer);
    SDL_DestroyWindow(world.window);
    SDL_Quit();

    return 0;
}

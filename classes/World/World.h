#include <list>
#include <SDL.h>

class World {
public:
    // Constructors and Destructors
    World(int w, int h);
    ~World();

    // Member Functions
    void addObstacle(std::list<std::pair<int, int> > obstacle);
    void addRobot(std::list<std::pair<int, int> > robot);
    void drawObstacles();

    // Member Variables
    int width;
    int height;
    std::list<std::list<std::pair<int, int> > > obstacles;
    std::list<std::pair<int, int> > robot;
    SDL_Window* window;
    SDL_Renderer* renderer;


protected:
    // Protected member variables and functions (if any)

private:
    // Private member variables and functions (if any)
};
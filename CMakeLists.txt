cmake_minimum_required(VERSION 3.27.4)
project(MainProject VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

# Adding Executables
add_executable(main main.cpp 
    classes/World/World.cpp 
    classes/Robot/Robot.cpp
    classes/Obstacle/Obstacle.cpp
    classes/Goal/Goal.cpp
    classes/Bug1/Bug1.cpp
)

# Adding Include Directories
target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})

# Adding Libraries
target_link_libraries(main ${SDL2_LIBRARIES})

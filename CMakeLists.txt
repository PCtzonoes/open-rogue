cmake_minimum_required(VERSION 3.23)
project(open_rogue)

set(CMAKE_CXX_STANDARD 17)

include_directories(inc)
add_subdirectory(src)

# Dependencies
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)


target_link_libraries(${PROJECT_NAME} PRIVATE
        SDL2
        SDL2_image
        SDL2_ttf
        )
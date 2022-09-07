cmake_minimum_required(VERSION 3.23)
project(open_rogue)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME} PRIVATE
        raylib
        )
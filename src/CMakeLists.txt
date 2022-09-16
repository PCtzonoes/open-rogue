add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(render)
add_subdirectory(util)

target_link_libraries(${PROJECT_NAME} PUBLIC render_lib util_lib)
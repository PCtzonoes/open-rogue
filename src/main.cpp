#include "entt.hpp"
#include "render/render.hpp"
#include "util/input_parser.hpp"
#include <SDL2/SDL.h>
#include <csignal>
#include <iostream>

typedef unsigned int uint;

struct Movement {
    int x, y;
};

struct Position {
    uint x;
    uint y;

    Position operator+(const Position &other) const { return {x + other.x, y + other.y}; }

    Position operator+(const Movement &other) const { return {x + other.x, y + other.y}; }
};

void update(entt::registry &registry)
{
    auto view = registry.view<Position, const Movement>();

    view.each([](auto &pos, const auto &move) { pos = pos + move; });
}


int main(int argc, char *argv[])
{
    InputParser input(argc, argv);

    if(input.cmdOptionExists("-h", "--help")) {
        std::cout << "Open Rogue Help" << '\n';

        std::cout << "Usage: open-rogue [options]" << '\n';
        std::cout << "Options:" << '\n';
        std::cout << "  -h, --help\t\tShow this help message and exit" << '\n';
        std::cout << "  -v, --version\t\tShow program's version number and exit" << '\n';

        return 0;
    }

    if(input.cmdOptionExists("-v", "--version")) {
        std::cout << "Open Rogue Version 0.0.1" << '\n';
        return 0;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << '\n';
        return 1;
    }

    std::cout << "Open Rogue Starting!" << '\n';
    SDL_Window *window =
            SDL_CreateWindow("Open Rogue", 100, 100, 640, 480, SDL_WINDOW_SHOWN);

    if(window == nullptr) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(
            window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == nullptr) {
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << '\n';
        SDL_Quit();
        return 1;
    }

    SDL_Event event;
    while(true) {
        signal(SIGTERM, [](int) {
            SDL_Quit();
            std::cout << "SIGTERM received" << '\n';
            exit(0);
        });

        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                SDL_Quit();
                std::cout << "SDL_QUIT received" << '\n';
                exit(0);
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 0, 0, 640, 480);

        SDL_RenderPresent(renderer);
    }

    std::cout << "Open Rogue Closing\n See ya!" << std::endl;
exit:
    return 0;
}
#pragma once

#include <SDL2/SDL_render.h>
#include <vector>

class Render
{
public:
    static SDL_Texture *LoadTexture(const char *fileName, SDL_Renderer *renderer);

    static void Draw(SDL_Texture *texture, SDL_Rect source, SDL_Rect destination,
                     SDL_RendererFlip flip, SDL_Renderer *renderer);
};

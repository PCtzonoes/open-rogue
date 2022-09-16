#include "render.hpp"

#include <SDL2/SDL_image.h>

SDL_Texture *Render::LoadTexture(const char *fileName, SDL_Renderer *renderer)
{
    SDL_Surface *surface = IMG_Load(fileName);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
void Render::Draw(SDL_Texture *texture, SDL_Rect source, SDL_Rect destination,
                  SDL_RendererFlip flip, SDL_Renderer *renderer)
{
    SDL_RenderCopyEx(renderer, texture, &source, &destination, 0.0f, nullptr, flip);
}

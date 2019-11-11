#include <SDL2/SDL.h>
#include "input.h"

void Input::handleInput()
{
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        if (Event.type == SDL_KEYDOWN)
        {
            switch (Event.key.keysym.sym)
            {
            case 'a':
                // DO SOMETHING
                break;
            case 'f':
                // renderer.toggleFullScreenMode();
                break;
            default:
                break;
            }
        }
    }
}
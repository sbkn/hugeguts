#include "game.h"

#define WinWidth 640
#define WinHeight 480

int Game::runGame()
{

    Renderer foo(SDL_WINDOW_OPENGL);
    rendering = &foo;
    Input inputHandler;
    input = &inputHandler;

    rendering->createWindow(WinWidth, WinHeight);
    gameRunning = 1;

    while (gameRunning)
    {

        handleInput();

        glViewport(0, 0, WinWidth, WinHeight);
        glClearColor(1.f, 0.f, 1.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(rendering->getWindow());
    }
    return 0;
}

void Game::handleInput()
{
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        if (Event.type == SDL_KEYDOWN)
        {
            switch (Event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                gameRunning = 0;
                break;
            case 'f':
                rendering->toggleFullScreenMode();
                break;
            default:
                break;
            }
        }
        else if (Event.type == SDL_QUIT)
        {
            gameRunning = 0;
        }
    }
    input->handleInput();
}
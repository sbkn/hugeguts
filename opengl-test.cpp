#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <OpenGL/gl.h>

#define WinWidth 640
#define WinHeight 480

struct GameObject
{
    int32_t Running;
};
class Rendering
{
public:
    Rendering(uint32_t windowFlags)
    {
        WindowFlags = windowFlags;
        FullScreen = 0;
    }
    void createWindow()
    {
        Window = SDL_CreateWindow("OpenGL Test", 100, 100, WinWidth, WinHeight, WindowFlags);
        assert(Window);
        SDL_GLContext Context = SDL_GL_CreateContext(Window);
    }
    SDL_Window* getWindow(){
        return Window;
    }
    void setFullScreenMode(){
        SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
        FullScreen = 1;
    }
    void setWindowMode(){
        SDL_SetWindowFullscreen(Window, WindowFlags);
        FullScreen = 0;
    }
    void toggleFullScreenMode(){
        if(FullScreen == 0){
            setFullScreenMode();
        } else {
            setWindowMode();
        }
    }

private:
    uint32_t WindowFlags;
    SDL_Window* Window;
    int32_t FullScreen;
};

class Input
{
public:
    Input(GameObject *game, Rendering* rendering)
    {
        gameObject = game;
        renderingObject = rendering;
    }
    void handleInput();

private:
    GameObject *gameObject;
    Rendering *renderingObject;
};

int main(int ArgCount, char **Args)
{
    Rendering rendering(SDL_WINDOW_OPENGL);
    rendering.createWindow();

    GameObject game;
    game.Running = 1;
    int32_t FullScreen = 0;

    Input inputHandler(&game, &rendering);

    while (game.Running)
    {
        inputHandler.handleInput();

        glViewport(0, 0, WinWidth, WinHeight);
        glClearColor(1.f, 0.f, 1.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(rendering.getWindow());
    }
    return 0;
}

void Input::handleInput()
{
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        if (Event.type == SDL_KEYDOWN)
        {
            switch (Event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                (*gameObject).Running = 0;
                break;
            case 'f':
                (*renderingObject).toggleFullScreenMode();
                break;
            default:
                break;
            }
        }
        else if (Event.type == SDL_QUIT)
        {
            (*gameObject).Running = 0;
        }
    }
}
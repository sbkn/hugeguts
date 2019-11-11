#include"renderer.h"

void Renderer::createWindow(int width, int height)
    {
        Window = SDL_CreateWindow("OpenGL Test", 100, 100, width, height, WindowFlags);
        assert(Window);
        SDL_GLContext Context = SDL_GL_CreateContext(Window);
    }
SDL_Window* Renderer::getWindow(){
        return Window;
    }
void Renderer::setFullScreenMode(){
        SDL_SetWindowFullscreen(Window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
        FullScreen = 1;
    }
void Renderer::setWindowMode(){
        SDL_SetWindowFullscreen(Window, WindowFlags);
        FullScreen = 0;
    }
void Renderer::toggleFullScreenMode(){
        if(FullScreen == 0){
            setFullScreenMode();
        } else {
            setWindowMode();
        }
    }
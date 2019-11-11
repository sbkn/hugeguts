#include <iostream>
#include <assert.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <OpenGL/gl.h>

class Renderer {
    
public:
    Renderer(uint32_t windowFlags)
    {
        WindowFlags = windowFlags;
        FullScreen = 0;
    }
    void createWindow(int width, int height);
    SDL_Window* getWindow();
    void setFullScreenMode();
    void setWindowMode();
    void toggleFullScreenMode();

private:
    uint32_t WindowFlags;
    SDL_Window* Window;
    int32_t FullScreen;
};
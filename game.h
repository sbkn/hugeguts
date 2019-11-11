#include <iostream>
#include"renderer.h"
#include"input.h"

class Game {
    private:
        int32_t gameRunning;
        Renderer* rendering;
        Input* input;
    public:
        int runGame();
        void handleInput();
};
#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    Window(const char* title, int width, int height);
    ~Window();
    void mainLoop();

private:
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool isRunning = true;

    void handleEvents();
    void changeBackgroundColor();
};

#endif // WINDOW_H


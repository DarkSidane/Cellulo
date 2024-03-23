#include "Window.h"
#include <stdlib.h>
#include <time.h>

Window::Window(const char* title, int width, int height) {
    srand(time(NULL));
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL could not initialize. SDL Error: %s", SDL_GetError());
    } else {
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        if (!window) {
            SDL_Log("Window could not be created. SDL Error: %s", SDL_GetError());
        } else {
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (!renderer) {
                SDL_Log("Renderer could not be created. SDL Error: %s", SDL_GetError());
            }
        }
    }
}

Window::~Window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::mainLoop() {
    while (isRunning) {
        handleEvents();
    }
}

void Window::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        } else if (event.type == SDL_MOUSEBUTTONDOWN) {
            changeBackgroundColor();
        }
    }
}

void Window::changeBackgroundColor() {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}


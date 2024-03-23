#include <SDL2/SDL.h>
#include <stdlib.h> 
#include <time.h>  

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char *argv[]) {
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("SDL cannot be initialized. Error SDL: %s", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Cellulo",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!window) {
        SDL_Log("Window cannot be initialized. Error SDL: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Renderer cannot be initialized. Error SDL: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    srand(time(NULL));

    // Main Loop 
    int running = 1;
    SDL_Event event;
    while (running) {
        // Event Manager
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Changer la couleur de fond à chaque clic de souris.
                int r = rand() % 256;
                int g = rand() % 256;
                int b = rand() % 256;
                SDL_SetRenderDrawColor(renderer, r, g, b, 255);
                SDL_RenderClear(renderer);
                SDL_RenderPresent(renderer);
            }
        }
    }

    // Cleaning
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


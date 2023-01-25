#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{

    SDL_Init (SDL_INIT_EVERYTHING);
    // Create a window for the grid

    SDL_Window* window = SDL_CreateWindow("Grid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // Create a 2D array of rectangles
    SDL_Rect grid[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            grid[i][j].x = i * 50;
            grid[i][j].y = j * 50;
            grid[i][j].w = 50;
            grid[i][j].h = 50;
        }
    }

    // Render the rectangles to the window
    for (int i = 0; i < 10; i = i + 2) {
        for (int j = 0; j < 10; j = j + 2) {
            SDL_SetRenderDrawColor(renderer, 100, 255, 100, 255);
            SDL_RenderFillRect(renderer, &grid[i][j]);
        }
    }

    // Update the window to display the grid
    SDL_RenderPresent(renderer);

    // Wait for user to close the window
    SDL_Event event;
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }
    }

    // Clean up
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
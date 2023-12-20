#include <stdio.h>
#include <SDL2/SDL.h>

int main() {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Your game code will go here
  // Create a window
  SDL_Window* window = SDL_CreateWindow("CGames", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
  if (window == NULL) {
    printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }

  // Create a renderer
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
    return 1;
  }


  SDL_Event event;
  int quit = 0;

  while (!quit) {
    while (SDL_PollEvent(&event) != 0) {
      if (event.type == SDL_QUIT) {
        quit = 1;
      }
    }

    // Your game logic will go here

    // Your rendering code will go here
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set the color to clear with (white in this case)
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(16); // Delay for 16 milliseconds (60 frames per second)
  }


  // Destroy renderer and window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  // Quit SDL
  SDL_Quit();
  return 0;
}

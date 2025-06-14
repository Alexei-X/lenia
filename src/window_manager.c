#include "window_manager.h"
#include <stdlib.h>

SDL_Window *create_window(const char* title, int width, int height) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error initializing SDL: %s\n", SDL_GetError());
  }
  
  SDL_Window* window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
  if (!window) {
    printf("Error creating window: %s\n", SDL_GetError());
    SDL_Quit();
    return NULL;
  }
  return window;
}

SDL_Surface* get_window_surface(SDL_Window* window) {
  
  SDL_Surface* surface = SDL_GetWindowSurface(window);
  if (!surface) {
    printf("Error getting window surface: %s\n", SDL_GetError());
    SDL_DestroyWindow(window);
    SDL_Quit();
    return NULL;
  }
  return surface;
}

void draw_grid(SDL_Surface* surface, int rows, int cols) {
  if (!surface) return;

  Uint32 color = SDL_MapRGB(surface->format, 255, 255, 255);
  int cell_width = surface->w / cols;
  int cell_height = surface->h / rows;

  for (int i = 0; i <= rows; i++) {
    SDL_Rect line = {0, i * cell_height, surface->w, 1};
    SDL_FillRect(surface, &line, color);
  }

  for (int j = 0; j <= cols; j++) {
    SDL_Rect line = {j * cell_width, 0, 1, surface->h};
    SDL_FillRect(surface, &line, color);
  }
}


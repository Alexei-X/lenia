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


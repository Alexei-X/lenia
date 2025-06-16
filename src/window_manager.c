#include "window_manager.h"
#include "constants.h"
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

void draw_grid(SDL_Surface* surface, Grid* grid) {
  if (!surface) return;

  Uint32 color = SDL_MapRGB(surface->format, 255, 255, 255);
  int cell_width = surface->w / grid->height;
  int cell_height = surface->h / grid->width;

  for (int i = 0; i <= N_WIDTH; i++) {
    SDL_Rect line = {0, i * cell_height, surface->w, 1};
    SDL_FillRect(surface, &line, color);
  }

  for (int j = 0; j <= N_HEIGHT; j++) {
    SDL_Rect line = {j * cell_width, 0, 1, surface->h};
    SDL_FillRect(surface, &line, color);
  }
}

void draw_cells(SDL_Surface* surface, Grid* grid) {
  for (int i = 0; i < grid->width; i++) {
    for (int j = 0; j < grid->height; j++) {
      CellState cellState = grid->cells[i][j];
      Uint32 cell_color = SDL_MapRGB(surface->format, 0.7*cellState.value*255, 0.8*cellState.value*255, 0.3*cellState.value*255);
      SDL_Rect cell = {cellState.x * CELL_WIDTH, cellState.y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT};
      SDL_FillRect(surface, &cell, cell_color);
    }
  }
}

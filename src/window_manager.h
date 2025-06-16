#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include "grid.h"

SDL_Window* create_window(const char* title, int width, int height);
SDL_Surface* get_window_surface(SDL_Window* window);
void draw_grid(SDL_Surface* surface, Grid* grid);
void draw_cells(SDL_Surface* surface, Grid* grid);

#endif // WINDOW_MANAGER_H

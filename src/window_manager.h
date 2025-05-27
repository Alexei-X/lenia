#ifndef _WINDOW_MANAGER_H
#define _WINDOW_MANAGER_H
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

SDL_Window* create_window(const char* title, int width, int height);
SDL_Surface* get_window_surface(SDL_Window* window);

#endif // _WINDOW_MANAGER_H

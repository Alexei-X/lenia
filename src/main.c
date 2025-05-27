#include <stdio.h>
#include <stdbool.h>
#include "window_manager.h"

int main(int argc, char** argv) {

  SDL_Window* window = create_window("Lenia", 800, 600);
  SDL_Surface* surface = get_window_surface(window);

  bool is_running = true;
  while (is_running) {
    SDL_Event e;
    while (SDL_PollEvent(&e) > 0) {
      switch (e.type) {
        case SDL_QUIT:
          is_running = false;
          break;
      }
      
    }
    Uint32 color = SDL_MapRGB(surface->format, 120, 70, 20);
    SDL_FillRect(surface, NULL, color);
    SDL_UpdateWindowSurface(window);
  }

  return 0;
}

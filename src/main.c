#include <stdio.h>
#include <stdbool.h>
#include "window_manager.h"

int main(int argc, char** argv) {

  SDL_Window* window = create_window("Lenia", 1200, 800);
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
    draw_grid(surface, 100, 100);
    SDL_UpdateWindowSurface(window);
  }

  return 0;
}

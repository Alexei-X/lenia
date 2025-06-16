#include <stdio.h>
#include <stdbool.h>
#include "window_manager.h"
#include "constants.h"
#include "grid.h"

int main(int argc, char** argv) {

  SDL_Window* window = create_window("Lenia", WINDOW_WIDTH, WINDOW_HEIGHT);
  SDL_Surface* surface = get_window_surface(window);
  Grid grid = {N_WIDTH, N_HEIGHT, NULL};
  if (fill_grid(&grid) == -1) return 0;

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
    //draw_grid(surface, &grid);
    draw_cells(surface, &grid);
    SDL_UpdateWindowSurface(window);
  }

  free(grid.cells);

  return 0;
}

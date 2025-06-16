#include "grid.h"
#include <stdlib.h>
#include <time.h>

int fill_grid(Grid* grid) {
    CellState** cells = (CellState**) malloc(grid->width * sizeof(CellState*));
    srand(time(NULL));
    if (cells == NULL) return -1;
    for (int i = 0; i < grid->width; i++) {
        cells[i] = (CellState*) malloc(grid->height * sizeof(CellState));
        if (cells[i] == NULL) return -1;
        for (int j = 0; j < grid->height; j++) {
            cells[i][j].x = i;
            cells[i][j].y = j;
            cells[i][j].value = rand();
        }
    }
    grid->cells = cells;
    return 0;
}


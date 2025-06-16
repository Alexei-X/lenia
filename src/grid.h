#ifndef GRID_H
#define GRID_H
#include "state.h"

typedef struct {
  int width;        // Width of the Grid
  int height;       // Height of the Grid
  CellState** cells; // 2D array of CellState objects
} Grid;

int fill_grid(Grid* grid);

#endif // GRID_H

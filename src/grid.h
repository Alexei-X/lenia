#ifnef _GRID_H
#define _GRID_H
#include "state.h"

struct Grid {
  int width;        // Width of the Grid
  int height;       // Height of the Grid
  CellState cells[width][height]; // 2D array of CellState objects
} Grid;


#endif // _GRID_H

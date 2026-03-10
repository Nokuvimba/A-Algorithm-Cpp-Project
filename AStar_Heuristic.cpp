/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Heuristic functions used by A* to estimate remaining cost
=========================================
*/

#include "AStar.h"
#include <cstdlib>

// Manhattan distance: sum of absolute row and column differences
// Admissible for 4-directional grids with uniform edge cost
int AStar::manhattan(Pos a, Pos b) const {
    return std::abs(a.r - b.r) + std::abs(a.c - b.c);
}

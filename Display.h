/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Declares printPathOnGrid – overlays the
found path onto the grid and prints it.
=========================================
*/

#ifndef DISPLAY_H
#define DISPLAY_H

#include "Grid.h"
#include "Pos.h"
#include <vector>
#include <string>

// Overlays the found path ('*') onto a copy of the grid and prints it.
// 'S' and 'G' cells are preserved and not overwritten.
void printPathOnGrid(const Grid& grid, const std::vector<Pos>& path);

#endif // DISPLAY_H

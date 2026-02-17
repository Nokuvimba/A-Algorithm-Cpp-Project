/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what’s walkable
=========================================
*/

#include "Grid.h"
#include <iostream>

Grid::Grid() {
    gridData = {
        "S....",
        ".###.",
        ".#G#.",
        ".###.",
        "....."
    };
}

void Grid::print() const {
    for (const auto& row : gridData) {
        std::cout << row << std::endl;
    }
}

// Returns the number of rows and columns in the grid (size information). This is used by bounds checking and by loops searching for the start and goal positions.
int Grid::rowCount() const {
    return static_cast<int>(gridData.size());
}

int Grid::colCount() const {
    return gridData.empty() ? 0 : static_cast<int>(gridData[0].size());
}

//ensures row/column aren't out of range.
bool Grid::withinGrid(int r, int c) const {
    return r >= 0 && c >= 0 && r < rowCount() && c < colCount();
}

//returns the character at that coordinate.
char Grid::cellAt(int r, int c) const {
    return gridData[r][c];
}

//movement is allowed only on ., S, G, not on #. So we check if the cell is a wall or not.
bool Grid::canMoveTo(int r, int c) const {
    if (!withinGrid(r, c)) return false;
    return cellAt(r, c) != '#';
}

//finds the position of the start (S) and goal (G) in the grid. It loops through the grid to find where S and G are located and returns their positions as Pos structs. If it doesn't find them, it returns {-1, -1}.
Pos Grid::findStart() const {
    for (int r = 0; r < rowCount(); r++) {
        for (int c = 0; c < colCount(); c++) {
            if (cellAt(r, c) == 'S') {
                return { r, c };
            }
        }
    }
    return { -1, -1 };
}

Pos Grid::findGoal() const {
    for (int r = 0; r < rowCount(); r++) {
        for (int c = 0; c < colCount(); c++) {
            if (cellAt(r, c) == 'G') {
                return { r, c };
            }
        }
    }
    return { -1, -1 };
}

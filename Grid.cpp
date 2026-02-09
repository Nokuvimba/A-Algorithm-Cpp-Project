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

int Grid::rowCount() const {
    return static_cast<int>(gridData.size());
}

int Grid::colCount() const {
    return gridData.empty() ? 0 : static_cast<int>(gridData[0].size());
}

bool Grid::withinGrid(int r, int c) const {
    return r >= 0 && c >= 0 && r < rowCount() && c < colCount();
}

char Grid::cellAt(int r, int c) const {
    return gridData[r][c];
}

bool Grid::canMoveTo(int r, int c) const {
    if (!withinGrid(r, c)) return false;
    return cellAt(r, c) != '#';
}

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

/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what's walkable
=========================================
*/

#include "Grid.h"
#include <iostream>
#include <utility>

Grid::Grid()
    : data_{
        "S....",
        ".###.",
        ".#G#.",
        ".###.",
        "....."
    }
{
}

Grid::Grid(std::vector<std::string> data)
    : data_(std::move(data))
{
}

void Grid::print() const {
    for (const auto& row : data_) {
        std::cout << row << '\n';
    }
}

//rowCount() / colCount() — how many rows and columns the grid has. Used everywhere bounds need checking.
int Grid::rowCount() const {
    return static_cast<int>(data_.size());
}

int Grid::colCount() const {
    return data_.empty() ? 0 : static_cast<int>(data_[0].size());
}

// returns the character at that position. Used everywhere to check for walls, start, goal, etc.
char Grid::cellAt(int r, int c) const {
    return data_[r][c];
}

//withinGrid(r, c) — is this coordinate even on the grid? Returns false if r or c would go out of bounds.
bool Grid::withinGrid(int r, int c) const {
    return r >= 0 && c >= 0 &&
        r < rowCount() && c < colCount();
}

//the only place wall-checking happens. canMoveTo(r, c) returns true if the cell is within the grid and not a wall.
bool Grid::canMoveTo(int r, int c) const {
    return withinGrid(r, c) && cellAt(r, c) != '#';
}

//both call the private findMarker() which scans every cell looking for S or G. Returns an invalid Pos if not found.
Pos Grid::findStart() const { return findMarker('S'); }
Pos Grid::findGoal()  const { return findMarker('G'); }

Pos Grid::findMarker(char marker) const {
    for (int r = 0; r < rowCount(); ++r)
        for (int c = 0; c < colCount(); ++c)
            if (cellAt(r, c) == marker)
                return { r, c };
    return {}; // invalid Pos
}
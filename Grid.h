/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what’s walkable. It basically defines what a Grid is and what it can do.
=========================================
*/

#ifndef GRID_H
#define GRID_H

#include "Pos.h"
#include <string>
#include <vector>

class Grid {
public:
    Grid();
    explicit Grid(std::vector<std::string> data);

    void print() const;

    int  rowCount() const;
    int  colCount() const;

    char cellAt(int r, int c) const;
    bool withinGrid(int r, int c) const;
    bool canMoveTo(int r, int c) const;

    Pos findStart() const;
    Pos findGoal()  const;

private:
    Pos findMarker(char marker) const;

    std::vector<std::string> data_;
};

#endif // GRID_H
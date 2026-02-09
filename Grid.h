/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what’s walkable
=========================================
*/

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

struct Pos {
    int r;
    int c;
};

class Grid {
public:
    Grid();

    void print() const;

    bool withinGrid(int r, int c) const;
    bool canMoveTo(int r, int c) const;

    char cellAt(int r, int c) const;

    Pos findStart() const;
    Pos findGoal() const;

    int rowCount() const;
    int colCount() const;

private:
    std::vector<std::string> gridData;
};

#endif // GRID_H

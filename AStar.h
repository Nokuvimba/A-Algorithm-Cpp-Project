/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date:
runs the algorithm and returns the path
=========================================
*/

#ifndef ASTAR_H
#define ASTAR_H

#include "Grid.h"
#include <vector>

class AStar {
public:
    void demoBasics() const;   // Week 1 -> Week 2 bridge demo

private:
    int manhattan(Pos a, Pos b) const;
    std::vector<Pos> getNeighbours(const Grid& grid, Pos p) const;
};

#endif // ASTAR_H

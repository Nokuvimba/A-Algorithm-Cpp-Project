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
#include "Node.h"
#include <vector>

class AStar {
public:
    void demoBasics(const Grid& grid) const;
    std::vector<Pos> findPath(const Grid& grid) const;

private:
    int manhattan(Pos a, Pos b) const;
    std::vector<Pos> neighbours(const Grid& grid, Pos p) const;

    std::vector<Pos> reconstructPath(
        Pos start,
        Pos goal,
        const std::vector<std::vector<Pos>>& parent
    ) const;
};

#endif // ASTAR_H
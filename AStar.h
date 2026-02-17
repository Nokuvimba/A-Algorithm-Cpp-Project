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

#include "Grid.h" // for Pos and Grid definitions
#include <vector>
#include "Node.h"

class AStar {
public:
	void demoBasics() const;   //prints the grid, start/goal positions, Manhattan distance.
    std::vector<Pos> findPath(const Grid& grid) const;

private:
    int manhattan(Pos a, Pos b) const; //returns estimated distance from a to b
    std::vector<Pos> getNeighbours(const Grid& grid, Pos p) const; //

    std::vector<Pos> reconstructPath(
        Pos start,
        Pos goal,
        const std::vector<std::vector<Pos>>& parent
    ) const;
};

#endif // ASTAR_H

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

class AStar {
public:
	void demoBasics() const;   //prints the grid, start/goal positions, Manhattan distance.

private:
    int manhattan(Pos a, Pos b) const; //returns estimated distance from a to b
    std::vector<Pos> getNeighbours(const Grid& grid, Pos p) const; //
};

#endif // ASTAR_H

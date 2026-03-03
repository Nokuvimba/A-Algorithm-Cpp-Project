/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Declares the AStar class: runs the algorithm and returns the path
=========================================
*/

#ifndef ASTAR_H
#define ASTAR_H

#include "Grid.h"
#include "Node.h"
#include <vector>

// Supported heuristics – easy to extend with new options
enum class Heuristic { Manhattan, Euclidean };

class AStar {
public:
    // Constructs with a chosen heuristic (default: Manhattan)
    explicit AStar(Heuristic h = Heuristic::Manhattan) : heuristic_(h) {}

    // Prints grid basics and neighbour info (useful for demos/debugging)
    void demoBasics(const Grid& grid) const;

    // Returns the shortest path as a vector of positions, or empty if none exists
    std::vector<Pos> findPath(const Grid& grid) const;

private:
    Heuristic heuristic_;

    // Heuristic estimate from a to b
    int estimate(Pos a, Pos b) const;

    int manhattan(Pos a, Pos b) const;
    int euclidean(Pos a, Pos b) const;

    // Returns walkable orthogonal neighbours of p
    std::vector<Pos> neighbours(const Grid& grid, Pos p) const;

    // Traces back through parent table to build the path
    std::vector<Pos> reconstructPath(
        Pos start,
        Pos goal,
        const std::vector<std::vector<Pos>>& parent
    ) const;
};

#endif // ASTAR_H
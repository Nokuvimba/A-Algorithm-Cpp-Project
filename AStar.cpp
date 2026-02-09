/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date:
runs the algorithm and returns the path
=========================================
*/

#include "AStar.h"
#include <iostream>
#include <cstdlib>   // std::abs

int AStar::manhattan(Pos a, Pos b) const {
    return std::abs(a.r - b.r) + std::abs(a.c - b.c);
}

std::vector<Pos> AStar::getNeighbours(const Grid& grid, Pos p) const {
    std::vector<Pos> neighbours;

    const int dr[4] = { -1, 1, 0, 0 };
    const int dc[4] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++) {
        int nr = p.r + dr[i];
        int nc = p.c + dc[i];

        if (grid.canMoveTo(nr, nc)) {
            neighbours.push_back({ nr, nc });
        }
    }

    return neighbours;
}

void AStar::demoBasics() const {
    Grid grid;
    grid.print();

    Pos start = grid.findStart();
    Pos goal = grid.findGoal();


    std::cout << "\nStart = (" << start.r << ", " << start.c << ")\n";
    std::cout << "Goal  = (" << goal.r << ", " << goal.c << ")\n";

    std::cout << "Manhattan distance (S -> G) = "
        << manhattan(start, goal) << "\n";

    std::cout << "\nNeighbours of Start:\n";
    auto neigh = getNeighbours(grid, start);
    for (const auto& n : neigh) {
        std::cout << "(" << n.r << ", " << n.c << ")\n";
    }
}

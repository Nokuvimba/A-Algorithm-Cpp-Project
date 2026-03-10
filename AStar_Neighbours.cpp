/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what's walkable
=========================================
*/
#include "AStar.h"

/*These two arrays encode the 4 directions:
- `DR[0], DC[0]` = (-1, 0) = Up
- `DR[1], DC[1]` = (+1, 0) = Down
- `DR[2], DC[2]` = (0, -1) = Left
- `DR[3], DC[3]` = (0, +1) = Right

The loop tries all four, and only keeps a neighbour if `canMoveTo()` says it's valid. The result is a list of cells A* is allowed to step into from the current position.
*/
std::vector<Pos> AStar::neighbours(const Grid& grid, Pos p) const {
    static constexpr int DR[4] = { -1, 1, 0, 0 };
    static constexpr int DC[4] = { 0, 0,-1, 1 };

    std::vector<Pos> result;

    for (int i = 0; i < 4; ++i) {
        int nr = p.r + DR[i];
        int nc = p.c + DC[i];

        if (grid.canMoveTo(nr, nc))
            result.push_back({ nr, nc });
    }

    return result;
}

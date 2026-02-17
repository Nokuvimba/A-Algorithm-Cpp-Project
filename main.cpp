/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
runs a test map
=========================================
*/

#include "AStar.h"
#include <iostream>

static void printPathOnGrid(const Grid& grid, const std::vector<Pos>& path) {
    // Make a copy to draw on (so Grid stays unchanged)
    std::vector<std::string> draw;
    draw.reserve(grid.rowCount());

    for (int r = 0; r < grid.rowCount(); r++) {
        std::string row;
        row.reserve(grid.colCount());
        for (int c = 0; c < grid.colCount(); c++) {
            row.push_back(grid.cellAt(r, c));
        }
        draw.push_back(row);
    }

    // mark path with '*', but do not overwrite S or G
    for (const auto& p : path) {
        char ch = draw[p.r][p.c];
        if (ch != 'S' && ch != 'G') {
            draw[p.r][p.c] = '*';
        }
    }

    std::cout << "\nGrid with path:\n";
    for (const auto& row : draw) {
        std::cout << row << "\n";
    }
} 

int main() {
    Grid grid;
    AStar astar;

    std::cout << "Original grid:\n";
    astar.demoBasics();

    auto path = astar.findPath(grid);

    if (path.empty()) {
        std::cout << "\nNo path found.\n";
    }
    else {
        std::cout << "\nPath found! Steps = " << (int)path.size() - 1 << "\n";
        printPathOnGrid(grid, path);
    }

    return 0;
}

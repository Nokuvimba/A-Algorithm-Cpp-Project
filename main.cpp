/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
runs a test map
=========================================
*/

#include "AStar.h"
#include "Grid.h"
#include <iostream>
#include <vector>

static void printPathOnGrid(const Grid& grid,
    const std::vector<Pos>& path) {

    std::vector<std::string> canvas(grid.rowCount());

    for (int r = 0; r < grid.rowCount(); ++r)
        for (int c = 0; c < grid.colCount(); ++c)
            canvas[r] += grid.cellAt(r, c);

    for (const Pos& p : path)
        if (canvas[p.r][p.c] != 'S' &&
            canvas[p.r][p.c] != 'G')
            canvas[p.r][p.c] = '*';

    std::cout << "\nGrid with path:\n";
    for (const auto& row : canvas)
        std::cout << row << '\n';
}

int main() {
    const Grid  grid;
    const AStar astar;

    std::cout << " A* Demo " \n";
    astar.demoBasics(grid);

    const auto path = astar.findPath(grid);

    if (path.empty())
        std::cout << "\nNo path found.\n";
    else {
        std::cout << "\nPath found! Steps = "
            << path.size() - 1 << '\n';
        printPathOnGrid(grid, path);
    }
}

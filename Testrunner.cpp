/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Implements runTest – runs a single named
test case and reports the result.
=========================================
*/

#include "TestRunner.h"
#include "AStar.h"
#include "Display.h"
#include <iostream>

void runTest(const std::string& name, const Grid& grid)
{
    const AStar astar;
    std::cout << "\n--- Test: " << name << " ---\n";
    grid.print();

    const auto path = astar.findPath(grid);

    if (path.empty())
    {
        std::cout << "No path found.\n";
    }
    else
    {
        std::cout << "Path found! Steps = " << path.size() - 1 << '\n';
        printPathOnGrid(grid, path);
    }
}
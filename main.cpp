/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Runs test maps and displays the path found by A*
=========================================
*/

#include "AStar.h"
#include "Grid.h"
#include <iostream>
#include <vector>

// Overlays the found path ('*') onto a copy of the grid and prints it
static void printPathOnGrid(const Grid& grid, const std::vector<Pos>& path)
{
    // Build a mutable copy of the grid rows as strings
    std::vector<std::string> canvas(grid.rowCount());
    for (int r = 0; r < grid.rowCount(); ++r)
        for (int c = 0; c < grid.colCount(); ++c)
            canvas[r] += grid.cellAt(r, c);

    // Mark every path cell that isn't Start or Goal
    for (const Pos& p : path)
        if (canvas[p.r][p.c] != 'S' && canvas[p.r][p.c] != 'G')
            canvas[p.r][p.c] = '*';

    std::cout << "\nGrid with path:\n";
    for (const auto& row : canvas)
        std::cout << row << '\n';
}

// Runs a single named test case and reports the result
static void runTest(const std::string& name, const Grid& grid)
{
    const AStar astar;
    std::cout << "\n--- Test: " << name << " ---\n";
    grid.print();

    const auto path = astar.findPath(grid);

    if (path.empty()) {
        std::cout << "No path found.\n";
    }
    else {
        std::cout << "Path found! Steps = " << path.size() - 1 << '\n';
        printPathOnGrid(grid, path);
    }
}

int main()
{
    std::cout << "=== A* Pathfinding Demo ===\n";

    // --- Test 1: Default grid (goal surrounded by walls – no path) ---
    const Grid defaultGrid;  // uses the no-argument constructor in Grid.cpp  — the hardcoded map with Goal surrounded by walls.
    const AStar astar;
    astar.demoBasics(defaultGrid); // prints the grid plus the Start/Goal positions and heuristic value. 
    runTest("Default grid (enclosed goal)", defaultGrid);

    // --- Test 2: Open grid – straightforward path ---
    runTest("Open grid", Grid({
        "S....",
        ".....",
        "..G..",
        ".....",
        "....."
        }));

    // --- Test 3: Maze-style grid ---
    runTest("Maze grid", Grid({
        "S#..G",
        ".#.#.",
        "...#.",
        ".###.",
        "....."
        }));

    // --- Test 4: Edge case – start equals goal ---
    runTest("Start == Goal", Grid({
        "SG"
        }));

    // --- Test 5: Edge case – completely blocked ---
    runTest("No path (fully blocked)", Grid({
        "S#G"
        }));

    return 0;
}
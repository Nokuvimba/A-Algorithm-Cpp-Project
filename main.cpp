/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Entry point – runs demo and test cases.
=========================================
*/

#include "AStar.h"
#include "Grid.h"
#include "TestRunner.h"
#include <iostream>

int main()
{
    std::cout << "=== A* Pathfinding Demo ===\n";

    // Show basics: grid layout, start/goal positions, heuristic value
    const Grid defaultGrid;
    const AStar astar;
    astar.demoBasics(defaultGrid);

    // --- Test 1: Default grid (goal surrounded by walls – no path) ---
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

    // --- Test 4: Edge case – start and goal are adjacent (1 step) ---
    runTest("Adjacent Start and Goal", Grid({
        "SG"
        }));

    // --- Test 5: Edge case – completely blocked ---
    runTest("No path (fully blocked)", Grid({
        "S#G"
        }));

    return 0;
}
/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Implements printPathOnGrid – overlays the
found path onto the grid and prints it.
=========================================
*/

#include "Display.h"
#include <iostream>

void printPathOnGrid(const Grid& grid, const std::vector<Pos>& path)
{
    // Build a mutable copy of each row as a string
    std::vector<std::string> canvas(grid.rowCount());
    for (int r = 0; r < grid.rowCount(); ++r)
    {
        for (int c = 0; c < grid.colCount(); ++c)
        {
            canvas[r] += grid.cellAt(r, c);
        }
    }

    // Mark every path cell that is not Start or Goal with '*'
    for (const Pos& p : path)
    {
        if (canvas[p.r][p.c] != 'S' && canvas[p.r][p.c] != 'G')
        {
            canvas[p.r][p.c] = '*';
        }
    }

    std::cout << "\nGrid with path:\n";
    for (const auto& row : canvas)
    {
        std::cout << row << '\n';
    }
}
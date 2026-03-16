/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Core A* search: findPath() and reconstructPath()
=========================================
*/

#include "AStar.h"
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>

// Traces back through the parent table from goal to start, then reverses
std::vector<Pos> AStar::reconstructPath(
    Pos start,
    Pos goal,
    const std::vector<std::vector<Pos>>& parent
) const {
    // If goal has no valid parent and isn't the start itself, no path exists
    if (!parent[goal.r][goal.c].isValid() && goal != start)
        return {};

    std::vector<Pos> path;

    for (Pos cur = goal; cur.isValid(); cur = parent[cur.r][cur.c]) {
        path.push_back(cur);
        if (cur == start) break;
    }

    std::reverse(path.begin(), path.end());
    return path;
}

// Main A* search: returns shortest path from grid's S to G, or empty vector
std::vector<Pos> AStar::findPath(const Grid& grid) const {
    const Pos start = grid.findStart();
    const Pos goal = grid.findGoal();

    // Cannot search without valid start and goal markers
    if (!start.isValid() || !goal.isValid())
        return {};

    const int rows = grid.rowCount();
    const int cols = grid.colCount();

    constexpr int INF = std::numeric_limits<int>::max();

    // g[r][c]      = best known cost from start to (r,c)
    // parent[r][c] = which cell we came from to reach (r,c)
    // closed[r][c] = true once a cell's optimal cost is finalised
    std::vector<std::vector<int>>  g(rows, std::vector<int>(cols, INF));
    std::vector<std::vector<Pos>>  parent(rows, std::vector<Pos>(cols));
    std::vector<std::vector<bool>> closed(rows, std::vector<bool>(cols, false));

    // Min-heap ordered by f = g + h
    std::priority_queue<Node, std::vector<Node>, NodeCompare> open;

    g[start.r][start.c] = 0;
    const int h0 = estimate(start, goal);
    open.push({ start, 0, h0, h0 });

    while (!open.empty()) {
        const Node cur = open.top();
        open.pop();

        const Pos p = cur.pos;

        // Lazy deletion: skip if already processed with a lower cost
        if (closed[p.r][p.c]) continue;
        closed[p.r][p.c] = true;

        // Early exit: path to goal found
        if (p == goal)
            return reconstructPath(start, goal, parent);

        // Expand each walkable neighbour
        for (const Pos& n : neighbours(grid, p)) {
            if (closed[n.r][n.c]) continue;

            const int tentativeG = g[p.r][p.c] + 1; // uniform edge cost

            if (tentativeG < g[n.r][n.c]) {
                g[n.r][n.c] = tentativeG;
                parent[n.r][n.c] = p;

                const int h = estimate(n, goal);
                open.push({ n, tentativeG, h, tentativeG + h });
            }
        }
    }

    return {}; // No path found
}

// Prints grid state plus heuristic and neighbour info from the start cell
void AStar::demoBasics(const Grid& grid) const {
    grid.print();

    const Pos start = grid.findStart();
    const Pos goal = grid.findGoal();

    std::cout << "\nStart = (" << start.r << ", " << start.c << ")\n"
        << "Goal  = (" << goal.r << ", " << goal.c << ")\n"
        << "Heuristic estimate (start -> goal) = "
        << estimate(start, goal) << "\n"
        << "\nNeighbours of Start:\n";

    for (const Pos& n : neighbours(grid, start))
        std::cout << "  (" << n.r << ", " << n.c << ")\n";
}
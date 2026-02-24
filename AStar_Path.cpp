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
#include <algorithm>
#include <iostream>
#include <limits>
#include <queue>

std::vector<Pos> AStar::reconstructPath(
    Pos start,
    Pos goal,
    const std::vector<std::vector<Pos>>& parent
) const {
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

std::vector<Pos> AStar::findPath(const Grid& grid) const {
    const Pos start = grid.findStart();
    const Pos goal = grid.findGoal();

    if (!start.isValid() || !goal.isValid())
        return {};

    const int rows = grid.rowCount();
    const int cols = grid.colCount();

    constexpr int INF = std::numeric_limits<int>::max();

    std::vector<std::vector<int>>  g(rows, std::vector<int>(cols, INF));
    std::vector<std::vector<Pos>>  parent(rows, std::vector<Pos>(cols));
    std::vector<std::vector<bool>> closed(rows, std::vector<bool>(cols, false));

    std::priority_queue<Node, std::vector<Node>, NodeCompare> open;

    g[start.r][start.c] = 0;
    int h0 = manhattan(start, goal);
    open.push({ start, 0, h0, h0 });

    while (!open.empty()) {
        Node cur = open.top();
        open.pop();

        Pos p = cur.pos;

        if (closed[p.r][p.c]) continue;
        closed[p.r][p.c] = true;

        if (p == goal)
            return reconstructPath(start, goal, parent);

        for (const Pos& n : neighbours(grid, p)) {
            if (closed[n.r][n.c]) continue;

            int tentativeG = g[p.r][p.c] + 1;

            if (tentativeG < g[n.r][n.c]) {
                g[n.r][n.c] = tentativeG;
                parent[n.r][n.c] = p;

                int h = manhattan(n, goal);
                open.push({ n, tentativeG, h, tentativeG + h });
            }
        }
    }

    return {};
}

void AStar::demoBasics(const Grid& grid) const {
    grid.print();

    const Pos start = grid.findStart();
    const Pos goal = grid.findGoal();

    std::cout << "\nStart = (" << start.r << ", " << start.c << ")\n"
        << "Goal  = (" << goal.r << ", " << goal.c << ")\n"
        << "Manhattan distance = " << manhattan(start, goal) << "\n"
        << "\nNeighbours of Start:\n";

    for (const Pos& n : neighbours(grid, start))
        std::cout << "  (" << n.r << ", " << n.c << ")\n";
}
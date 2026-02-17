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
#include <queue>
#include <limits>
#include <algorithm>


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

std::vector<Pos> AStar::reconstructPath(
    Pos start,
    Pos goal,
    const std::vector<std::vector<Pos>>& parent
) const {
    std::vector<Pos> path;

    // if goal has no parent, no path
    if (parent[goal.r][goal.c].r == -1 && !(goal.r == start.r && goal.c == start.c)) {
        return {};
    }

    Pos current = goal;
    while (!(current.r == -1 && current.c == -1)) {
        path.push_back(current);
        if (current.r == start.r && current.c == start.c) break;
        current = parent[current.r][current.c];
    }

    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Pos> AStar::findPath(const Grid& grid) const {
    Pos start = grid.findStart();
    Pos goal = grid.findGoal();

    // Safety check
    if (start.r == -1 || goal.r == -1) {
        return {};
    }

    const int INF = std::numeric_limits<int>::max();

    std::vector<std::vector<int>> gScore(
        grid.rowCount(),
        std::vector<int>(grid.colCount(), INF)
    );

    std::vector<std::vector<Pos>> parent(
        grid.rowCount(),
        std::vector<Pos>(grid.colCount(), { -1, -1 })
    );

    std::vector<std::vector<bool>> closedSet(
        grid.rowCount(),
        std::vector<bool>(grid.colCount(), false)
    );

    std::priority_queue<Node, std::vector<Node>, NodeCompare> openSet;

    gScore[start.r][start.c] = 0;

    Node startNode;
    startNode.pos = start;
    startNode.g = 0;
    startNode.h = manhattan(start, goal);
    startNode.f = startNode.g + startNode.h;

    openSet.push(startNode);

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        Pos p = current.pos;

        if (closedSet[p.r][p.c]) continue;

        closedSet[p.r][p.c] = true;

        if (p.r == goal.r && p.c == goal.c) {
            return reconstructPath(start, goal, parent);
        }

        auto neighbours = getNeighbours(grid, p);

        for (const auto& n : neighbours) {
            if (closedSet[n.r][n.c]) continue;

            int tentativeG = gScore[p.r][p.c] + 1; // cost per move = 1

            if (tentativeG < gScore[n.r][n.c]) {
                gScore[n.r][n.c] = tentativeG;
                parent[n.r][n.c] = p;

                Node next;
                next.pos = n;
                next.g = tentativeG;
                next.h = manhattan(n, goal);
                next.f = next.g + next.h;

                openSet.push(next);
            }
        }
    }

    // no path
    return {};
}

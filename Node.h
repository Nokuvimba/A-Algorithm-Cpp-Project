/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what’s walkable. It basically defines what a Grid is and what it can do.
=========================================
*/
#ifndef NODE_H
#define NODE_H

#include "Pos.h"

struct Node {
    Pos pos;
    int g{ 0 };
    int h{ 0 };
    int f{ 0 };
};

// Min-heap (smallest f first)
struct NodeCompare {
    bool operator()(const Node& a, const Node& b) const {
        return a.f == b.f ? a.h > b.h : a.f > b.f;
    }
};

#endif // NODE_H
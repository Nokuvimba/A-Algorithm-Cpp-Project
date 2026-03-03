/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Represents a single entry in the A* open list
=========================================
*/

#ifndef NODE_H
#define NODE_H

#include "Pos.h"

// A node in the open list: stores position plus A* cost values
struct Node {
    Pos pos;
    int g{ 0 };  // Cost from start to this node
    int h{ 0 };  // Heuristic estimate from this node to goal
    int f{ 0 };  // Total estimated cost: f = g + h
};

// Comparator for the min-heap (priority_queue): smallest f first;
// ties broken by smallest h (node closest to goal wins)
struct NodeCompare {
    bool operator()(const Node& a, const Node& b) const {
        return a.f == b.f ? a.h > b.h : a.f > b.f;
    }
};

#endif // NODE_H
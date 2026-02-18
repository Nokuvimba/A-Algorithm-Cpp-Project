/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
a node in the grid, stores its position, g cost, h cost, f cost, and parent node
=========================================
*/

#ifndef NODE_H
#define NODE_H

#include "Grid.h" //to get Pos

// A* works with nodes (a position + costs)
struct Node {
    Pos pos;  //current grid position
    int g;   //how many steps from Start to here (real cost so far)
    int h;   // estimated steps from here to Goal (Manhattan)
    int f;   // total score used to choose what to explore next = g + h
};

//give the node with the smallest f first
struct NodeCompare {
    bool operator()(const Node& a, const Node& b) const {
        if (a.f == b.f) { //if two nodes have the same f, break the tie by prferring h
            
            return a.h > b.h;
        }
        return a.f > b.f;
    }
};

#endif // NODE_H

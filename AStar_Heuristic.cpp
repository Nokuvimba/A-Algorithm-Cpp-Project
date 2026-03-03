/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Heuristic functions used by A* to estimate remaining cost
=========================================
*/

#include "AStar.h"
#include <cmath>
#include <cstdlib>

// Manhattan distance: sum of absolute row and column differences
// Admissible for 4-directional grids with uniform edge cost
int AStar::manhattan(Pos a, Pos b) const {
    return std::abs(a.r - b.r) + std::abs(a.c - b.c);
}

// Euclidean distance: straight-line distance, scaled to int
// Admissible but less tight than Manhattan for 4-directional movement
int AStar::euclidean(Pos a, Pos b) const {
    const double dr = static_cast<double>(a.r - b.r);
    const double dc = static_cast<double>(a.c - b.c);
    return static_cast<int>(std::sqrt(dr * dr + dc * dc));
}

// Dispatches to the correct heuristic based on the current setting
int AStar::estimate(Pos a, Pos b) const {
    switch (heuristic_) {
    case Heuristic::Euclidean: return euclidean(a, b);
    case Heuristic::Manhattan: // fall-through to default
    default:                   return manhattan(a, b);
    }
}
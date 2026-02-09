/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date:
=========================================
*/

#ifndef ASTAR_H
#define ASTAR_H

#include <vector>
#include <string>

class AStar {
private:
    std::vector<std::string> grid;

public:
    AStar();           // Constructor
    void print() const;
};

class NumberMatrix {
public:
    NumberMatrix();
    void print() const;

private:
    std::vector<std::vector<int>> matrix;
};

#endif // ASTAR_H

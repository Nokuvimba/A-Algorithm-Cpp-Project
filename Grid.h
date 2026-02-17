/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what’s walkable. It basically defines what a Grid is and what it can do.
=========================================
*/

#ifndef GRID_H
#define GRID_H

#include <vector>
#include <string>

struct Pos {
    int r; //row index
    int c; //column index
};

class Grid {
public:
    Grid();

	void print() const; // prints the grid to the console

	bool withinGrid(int r, int c) const; // checks if (r, c) is a valid position in the grid
	bool canMoveTo(int r, int c) const; // checks if you can move to (r, c) (i.e., if a cell isn't a wall)

	char cellAt(int r, int c) const; // returns the character at (r, c) (e.g., '.', '#', 'S', 'G')

	// Finds the position of the start (S) and goal (G) in the grid
    Pos findStart() const;
    Pos findGoal() const;

	// Returns the number of rows and columns in the grid (dimensions)
    int rowCount() const;
    int colCount() const;

private:
    std::vector<std::string> gridData; //This is the actual map stored inside the Grid object. It’s private so only Grid controls how it’s accessed.
};

#endif // GRID_H

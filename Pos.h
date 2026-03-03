/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Lightweight 2-D grid coordinate
=========================================
*/

#ifndef POS_H
#define POS_H

// Represents a row/column position on the grid.
// Default-constructed Pos is invalid (r = c = -1).
struct Pos {
    int r{ -1 };
    int c{ -1 };

    bool isValid() const { return r >= 0 && c >= 0; }

    bool operator==(const Pos& o) const { return r == o.r && c == o.c; }
    bool operator!=(const Pos& o) const { return !(*this == o); }
};

#endif // POS_H
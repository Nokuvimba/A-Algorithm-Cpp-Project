/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
stores the grid, prints it, knows what’s walkable. It basically defines what a Grid is and what it can do.
=========================================
*/
#ifndef POS_H
#define POS_H

struct Pos {
    int r{ -1 };
    int c{ -1 };

    bool isValid() const { return r >= 0 && c >= 0; }

    bool operator==(const Pos& o) const {
        return r == o.r && c == o.c;
    }

    bool operator!=(const Pos& o) const {
        return !(*this == o);
    }
};

#endif // POS_H

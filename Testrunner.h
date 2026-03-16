/*
=========================================
A* Algorithm Project
Author: Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 26/02/2026
Declares runTest – runs a single named
test case and reports the result.
=========================================
*/

#ifndef TESTRUNNER_H
#define TESTRUNNER_H

#include "Grid.h"
#include <string>

// Runs A* on the given grid, prints the result,
// and overlays the path if one is found.
void runTest(const std::string& name, const Grid& grid);

#endif // TESTRUNNER_H

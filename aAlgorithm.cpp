/*
=========================================
A* Algorithm Project
Author:Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date:
=========================================
*/

#include "aAlgorithm.h"
#include <iostream>

AAlgorithm::AAlgorithm() {
	// A simple grid for demonstration purposes
	grid = {
		"S....",
		".###.",
		".#G#.",
		".###.",
		"....."
	};
}
void AAlgorithm::print() const {
	for (const auto& row : grid) {
		std::cout << row << std::endl;
	}
}

NumberMatrix::NumberMatrix() {
	// A simple 3x3 matrix for demonstration purposes
	matrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
}
void NumberMatrix::print() const {
	for (const auto& row : matrix) {
		for (const auto& num : row) {
			std::cout << num << " ";
		}
		std::cout << std::endl;
	}
}


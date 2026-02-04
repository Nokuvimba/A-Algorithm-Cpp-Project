/*
=========================================
A* Algorithm Project
Author:Nokuvimba Natalie Chiyaka
Start Date: 04/02/2026
Last Modified Date: 
=========================================
*/

#ifndef AALGORITHM_H
#define AALGORITHM_H
#include <vector>
#include <string>

class AAlgorithm {

private:
	std::vector<std::string> grid;

public:
	AAlgorithm(); //Constructor
	void print() const;

};

class NumberMatrix
{
public:
	NumberMatrix();
	void print() const;

private:
	std::vector<std::vector<int>> matrix;

};

#endif// AALGORITHM_H


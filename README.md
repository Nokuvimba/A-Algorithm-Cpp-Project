# C++ Programming Project (A* Pathfinding)
**Name:** Nokuvimba Natalie Chiyaka  
**Language:** C++17  
**Project Title:** A* Algorithm (Console Grid Pathfinding)

## Project Overview
A console-based A* pathfinding program that finds the shortest path from **S** (start) to **G** (goal)
on a grid containing obstacles **#**. The shortest path is displayed using **\*** characters.

## Why C++17?
I chose C++17 because it supports modern C++ features (clean STL usage, safer patterns, easier code organisation)
while still meeting the requirement of C++11 or higher.  https://www.geeksforgeeks.org/cpp/c-11-vs-c-14-vs-c-17/ 

## Current File Structure
- `main.cpp` – runs the demo map and calls the algorithm
- `Grid.h/.cpp` – grid storage + printing + helper functions (bounds, walkable, etc.)
- `AStar.h/.cpp` – A* algorithm implementation

## **What is A-Star Algorithm**
Read to understand the concept of the A*algorithm and looked and sample code :https://www.geeksforgeeks.org/dsa/a-search-algorithm/ , https://github.com/JDSherbert/A-Star-Pathfinding

### **Project Idea**

## Weekly Progress Log
### Week 1 (04/02/2026)
**Goal:** Understand A* and print a character-based grid.
- Researched A* concept + reviewed sample implementations.
- Created repo + Visual Studio project.
- Implemented basic grid printing using `vector<string>`.
- Implemented simple matrix printing as a warm-up exercise.
**SetUp**
created 3 files aAlgorithm.h, aAlgorithm.c, main.cpp
<img width= 75% height="300" alt="image" src="https://github.com/user-attachments/assets/8a529583-17cc-4040-b146-ffbe8491a1fb" /> 

In lab 1 I worked on printing out a matrix in interger and string form:
<img width="1111" height="332" alt="image" src="https://github.com/user-attachments/assets/7d03e057-2ed8-4f9f-982a-4a7574b22ed2" />
<img width=33.3% height="435" alt="image" src="https://github.com/user-attachments/assets/fcd3eb61-c300-42c4-9531-197daab18a4a" />
<img width=33.3% height="435" alt="image" src="https://github.com/user-attachments/assets/037e21b2-037c-42a9-80fe-35b53e15ac80" />
<img width=30.3% height="435" alt="image" src="https://github.com/user-attachments/assets/253150f2-7f39-4d22-9b51-d8a173c5e686" />

## Week 1 → Week 2 Bridge (Grid + Basics for A*)

### What I implemented
This week I moved from a simple “print a grid” demo to a proper foundation that A* can use.

#### Grid (map handling)
I created a `Grid` class to own the map (stored as `std::vector<std::string>`).  
The Grid is responsible for:
- Printing the map to the console
- Finding the Start `S` and Goal `G` automatically
- Checking if a coordinate is valid using `withinGrid(r, c)`
- Checking if movement is allowed using `canMoveTo(r, c)` (walls are `#`)

I also added a `cellAt(r, c)` helper so the rest of the program doesn’t directly index the grid everywhere.

#### Pos (coordinates)
I added: `
struct Pos { int r; int c; };` : This keeps row/column together as one variable and makes the code easier to read.
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/4e431d84-81a5-4da9-8e37-b7ecf75c2c05" />

#### Manhattan heuristic
I implemented Manhattan distance: `abs(a.r - b.r) + abs(a.c - b.c)`
This is the correct heuristic when movement is only up/down/left/right and there are no diagonal moves. this value is an estimate (guidance for A*), not the final path length.
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/7665217c-cb55-46a9-8d0a-d53a519e9afc" />
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/438bbd6a-2015-4c6c-9eac-8d2dbf892a9f" />
#### Neighbour generation (4 directions)
I added neighbour generation using 4-direction movement:
	•	Up, Down, Left, Right
Each neighbour is checked using canMoveTo() so we never go out of bounds or into walls.

####Output 
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/107c3daf-d955-4e4d-8f79-92330630d395" />
Detected positions:
	•	Start = (0,0) because S is at row 0, col 0
	•	Goal  = (2,2) because G is at row 2, col 2

Manhattan distance:
	•	|0 - 2| + |0 - 2| = 2 + 2 = 4

Neighbours of Start (0,0):
	•	Up (-1,0) is out of bounds 
	•	Left (0,-1) is out of bounds 
	•	Down (1,0) is valid and walkable 
	•	Right (0,1) is valid and walkable 

The goal G is fully surrounded by #, so there is no valid path in this test map.
This is a useful edge-case because when A* is implemented fully, the program should correctly report “No path found”.

##### This is my main.cpp and Grid.cpp
<img width="405" height="400" alt="image" src="https://github.com/user-attachments/assets/fdfe22c0-7305-4e60-8cf7-6630a2fe4cbe" />

<img width="405" height="400" alt="image" src="https://github.com/user-attachments/assets/3ead13d7-b0b7-4b9a-b8fa-014a69a29336" />







# C++ Programming Project (A* Pathfinding)
**Name:** Nokuvimba Natalie Chiyaka  
**Language:** C++17  
**Project Title:** A* Algorithm (Console Grid Pathfinding)

## Project Overview
A console-based A* pathfinding program that finds the shortest path from **S** (start) to **G** (goal)
on a grid containing obstacles **#**. The shortest path is displayed using **\*** characters.



## **What is A-Star Algorithm**
It is a technique used in path-finding and graph traversals.
I read to understand the concept of the A*algorithm and looked at sample code :https://www.geeksforgeeks.org/dsa/a-search-algorithm/ , https://github.com/JDSherbert/A-Star-Pathfinding

### **Project Idea**

## Weekly Progress Log
### Week 1 (04/02/2026)
**Goal:** To understand A* and print a character-based grid.
- Researched A* concept + reviewed sample implementations.
- Created repo + Visual Studio project.
- Implemented basic grid printing using `vector<string>`.
- Implemented simple matrix printing as a warm-up exercise.
  
**SetUp**
  
created 3 files aAlgorithm.h, aAlgorithm.c, main.cpp
<img width= 75% height="300" alt="image" src="https://github.com/user-attachments/assets/8a529583-17cc-4040-b146-ffbe8491a1fb" />

## Why C++17?
I chose C++17 because it supports modern C++ features (clean STL usage, safer patterns, easier code organisation)
while still meeting the requirement of C++11 or higher.  https://www.geeksforgeeks.org/cpp/c-11-vs-c-14-vs-c-17/ 

## Current File Structure
- `main.cpp` – runs the demo map and calls the algorithm
- `Grid.h/.cpp` – grid storage + printing + helper functions (bounds, walkable, etc.)
- `AStar.h/.cpp` – A* algorithm implementation
  
In lab 1 I worked on printing out a matrix in interger and string form:
<img width="1111" height="332" alt="image" src="https://github.com/user-attachments/assets/7d03e057-2ed8-4f9f-982a-4a7574b22ed2" />
<img width=33.3% height="435" alt="image" src="https://github.com/user-attachments/assets/fcd3eb61-c300-42c4-9531-197daab18a4a" />
<img width=33.3% height="435" alt="image" src="https://github.com/user-attachments/assets/037e21b2-037c-42a9-80fe-35b53e15ac80" />
<img width=30.3% height="435" alt="image" src="https://github.com/user-attachments/assets/253150f2-7f39-4d22-9b51-d8a173c5e686" />

## Week 1 → Week 2 Bridge (Grid + Basics for A*) 11/02/2026

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

#### Output 
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

 ###### In Summary
Grid is responsible for storing and validating the map. It finds S and G, checks bounds and movement rules, and prints the grid. AStar currently contains the two main building blocks needed for the full algorithm: Manhattan heuristic and neighbour generation. main.cpp just runs the demo to verify everything before implementing the full open/closed sets next.

## Week 2 (17/02/2026)

**Goal:** To implement the core A* search algorithm using the Grid and heuristic foundations built in Week 1.

---

### Node Structure

To support A*, I created a separate `Node.h` file containing a `Node` structure:
<img width="989" height="677" alt="image" src="https://github.com/user-attachments/assets/c5dbc17c-26bc-4bbd-bb88-e3596b7c9a4d" />

```cpp
struct Node {
    Pos pos;
    int g;  // real cost from Start to current node
    int h;  // heuristic estimate from current node to Goal
    int f;  // total cost (f = g + h)
};
```

#### My Understanding

- `g` represents how many steps have been taken from Start to the current node.
- `h` uses the Manhattan heuristic to estimate the remaining distance to the Goal.
- `f = g + h` determines which node should be explored next — the lower the `f`, the more promising the path.
- Separating position data (`Pos`) from cost data (`Node`) keeps the code modular and easier to reason about.

---

### Priority Queue (Open Set)

To implement the A* open set, I used `std::priority_queue` with a custom comparator:

```cpp
std::priority_queue<Node, std::vector<Node>, NodeCompare>

struct NodeCompare {
    bool operator()(const Node& a, const Node& b) const {
        if (a.f == b.f)
            return a.h > b.h;
        return a.f > b.f;
    }
};
```

#### Understanding

- The open set holds all candidate nodes waiting to be explored.
- The node with the smallest `f` is always explored first (min-heap behaviour).
- When two nodes share the same `f`, the one with the smaller `h` is preferred — this breaks ties in favour of nodes that are closer to the Goal.
- This keeps the algorithm optimal while reducing unnecessary exploration.

---

### Closed Set

```cpp
std::vector<std::vector<bool>> closedSet;
```

#### Understanding

- Once a node is fully explored, it is added to the closed set.
- This prevents the algorithm from revisiting the same position with a worse cost.
- Without this, the algorithm could loop indefinitely on open grids.

---

### A* Core Algorithm (`findPath`)

The `findPath()` function brings all the pieces together:

1. Retrieves Start `S` and Goal `G` from the Grid.
2. Pushes the Start node (with `g = 0`) into the open set.
3. Repeatedly:
   - Selects the node with the lowest `f`.
   - If it is the Goal → path found, stop.
   - Marks it as closed (visited).
   - Expands each valid neighbour.
   - Calculates new `g`, `h`, and `f` for each neighbour.
   - Pushes neighbours into the open set.
4. Stops when the Goal is reached **or** the open set is empty (no path exists).

---

### Edge Case: Blocked Goal
<img width="1112" height="624" alt="image" src="https://github.com/user-attachments/assets/80e1a2c7-8ba6-4f47-b2c8-7e4bde5136fb" />
Test grid used:

```
S....
.###.
.#G#.
.###.
.....
```

The Goal `G` is completely surrounded by walls `#`, so no valid path exists.

**Console output:**
```
No path found.
```

#### Understanding

- This confirms that neighbour validation (`canMoveTo`) works correctly.
- The closed set correctly prevents the algorithm from revisiting cells.
- The algorithm terminates safely rather than looping forever.
- Testing a "no path" case before implementing path reconstruction is important — it verifies the core loop is correct before adding more complexity.

---

### Path Reconstruction (Prepared, Not Yet Complete)

In `main.cpp` I added a `printPathOnGrid()` helper that:
- Takes a copy of the grid (so the original is not modified).
- Overlays `*` characters onto path cells between Start and Goal.
<img width="1325" height="870" alt="image" src="https://github.com/user-attachments/assets/06357436-a5fd-4a14-aa93-4d399d3de1f2" />
**Next step:** implement parent tracking inside `findPath()` so the path can be traced back from Goal to Start, then passed to `printPathOnGrid()` for display.

---
## Week 3 (24/02/2026)

**Goal:** To refactor the existing code using the C++ Core Guidelines without changing what the algorithm does. I also added sme tests.

---

### What are the C++ Core Guidelines?
<img width="1902" height="1018" alt="image" src="https://github.com/user-attachments/assets/1b32a5ef-6a8b-4ba3-831b-2e7034ed3cea" />
Key rules I applied:

| Guideline | Rule |
|---|---|
| `F.3` | Keep functions short and focused on one task |
| `F.17` | Use `[[nodiscard]]` when ignoring a return value is almost certainly a bug |
| `C.45` | Don't define a default constructor that only initialises data members |
| `Enum.3` | Prefer `enum class` over plain `enum` |
| `Con.1` | By default, make variables `const` |
| `ES.20` | Always initialise variables at the point of declaration |
| `I.3` | Avoid singletons — pass dependencies explicitly |

---
### Why l separated the files per module(function)
So that it would be easy to edit and add new things accordingly.

### Change 1 — `[[nodiscard]]` on `findPath()`

```cpp
// Before
std::vector<Pos> findPath(const Grid& grid) const;

// After
[[nodiscard]] std::vector<Pos> findPath(const Grid& grid) const;
```

#### Understanding

`[[nodiscard]]` is a C++17 attribute that tells the compiler: *"warn if the caller throws this return value away."*

Without it, a developer could accidentally write:

```cpp
astar.findPath(grid);   // result silently discarded — no warning
```

With `[[nodiscard]]`, the compiler produces a warning immediately and makes the function **harder to misuse**.

---

### Change 2 — `enum class Heuristic` (adding Euclidean)

```cpp
// Before — no choice of heuristic existed at all

// After
enum class Heuristic { Manhattan, Euclidean };
```

And a new dispatch function:

```cpp
int AStar::estimate(Pos a, Pos b) const {
    switch (heuristic_) {
        case Heuristic::Euclidean: return euclidean(a, b);
        default:                   return manhattan(a, b);
    }
}
```

#### Understanding

**Why `enum class` and not plain `enum`?**

A plain `enum` leaks its values into the surrounding scope, which can cause name collisions:

```cpp
enum Heuristic { Manhattan, Euclidean };
int Manhattan = 5;   //  name clash — won't compile
```

An `enum class` keeps its values scoped:

```cpp
enum class Heuristic { Manhattan, Euclidean };
int Manhattan = 5;   //  no clash — they are different things
```

**Why a dispatch function `estimate()`?**

Previously, `findPath()` called `manhattan()` directly — hardcoded. Now `estimate()` reads the `heuristic_` member and picks the right function. This means l can change heuristic at construction time and the rest of the algorithm doesn't change at all:

```cpp
AStar defaultSearch;                           // Manhattan
AStar euclideanSearch(Heuristic::Euclidean);   // Euclidean
```

---

### Change 3 — `const` by default

```cpp
// Before
Pos start = grid.findStart();
AStar astar;

// After
const Pos  start = grid.findStart();
const AStar astar;
```

#### Understanding

The Core Guidelines say: **make everything `const` unless you know you need to mutate it.**

If `start` is `const` and something accidentally tries to change it later, the compiler stops it immediately. Without `const`, that bug could go unnoticed.

---

### Change 4 — `[[nodiscard]]` tie-breaking in `NodeCompare`

```cpp
struct NodeCompare {
    bool operator()(const Node& a, const Node& b) const {
        return a.f == b.f ? a.h > b.h : a.f > b.f;
    }
};
```

#### Understanding

The comparator now uses a single-line ternary expression instead of a nested `if`. This keeps the function short (Core Guideline `F.3`) and makes the logic easier to read at a glance: *"if f values tie, prefer smaller h; otherwise prefer smaller f."*

---

### Change 5 — Removed magic numbers

```cpp
// Before — what does 1 mean here?
const int tentativeG = g[p.r][p.c] + 1;

// After — named constant, meaning is clear
constexpr int MOVE_COST = 1;   // uniform cost — will become terrain cost later
const int tentativeG = g[p.r][p.c] + MOVE_COST;
```

#### Understanding

A "magic number" is a raw value in code with no explanation. `+ 1` could mean anything. `+ MOVE_COST` makes the intent clear, and it marks exactly where the code needs to change when weighted terrain is added — which is next.

---

### Change 6 — `runTest()` helper in `main.cpp`

```cpp
static void runTest(const std::string& name, const Grid& grid) {
    const AStar astar;
    std::cout << "\n--- Test: " << name << " ---\n";
    grid.print();
    const auto path = astar.findPath(grid);
    if (path.empty()) {
        std::cout << "No path found.\n";
    } else {
        std::cout << "Path found! Steps = " << path.size() - 1 << '\n';
        printPathOnGrid(grid, path);
    }
}
```

#### Understanding

Before this, `main()` repeated the same print/run/check logic for every test. The Core Guideline `F.3` says functions should do **one thing**. Extracting `runTest()` means:

- `main()` is now just a list of test cases — easy to read
- The test logic lives in one place — easy to change
- Adding a new test is one line instead of five

---

### Test Cases Added

| Test | Grid | Expected |
|---|---|---|
| Default (enclosed goal) | `S` blocked by `#` ring | No path |
| Open grid | Clear path to `G` | Path found |
| Maze | Winding route through walls | Path found |
| Start adjacent to Goal | `SG` | 1 step |
| Fully blocked | `S#G` | No path |

---







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

## Week 1 (04/02/2026)
**Goal:** The goal is to understand the A* and learn to print a character-based grid.

### Why C++17?
I chose to use C++17 because it supports the modern C++ features while still meeting the requirements of C++11 or higher.  https://www.geeksforgeeks.org/cpp/c-11-vs-c-14-vs-c-17/ 

### What I did
- I researched the A* concept and also reviewed some sample code from the github. :https://www.geeksforgeeks.org/dsa/a-search-algorithm/ , https://github.com/JDSherbert/A-Star-Pathfinding
- I created a repository and set up the project in the Visual Studio IDE.
- I implemented basic grid printing using `vector<string>` and a simple matrix printing.
  
**The Project SetUp**
  
I created 3 files: the aAlgorithm.h, aAlgorithm.c, main.cpp
<img width= 75% height="300" alt="image" src="https://github.com/user-attachments/assets/8a529583-17cc-4040-b146-ffbe8491a1fb" />

### The Current File Structure
- The `main.cpp`  runs the demo map and calls the algorithm
- The `Grid.h/.cpp` is for storing and printing the grid, and will later include helper functions that include finding out whether a path is walkable or not.
- The `AStar.h/.cpp` is where the A* algorithm will be implementation
  
In lab 1 I worked on printing out a matrix in interger and string form:
<img width="1111" height="332" alt="image" src="https://github.com/user-attachments/assets/7d03e057-2ed8-4f9f-982a-4a7574b22ed2" />
<img width=33.3% height="435" alt="image" src="https://github.com/user-attachments/assets/fcd3eb61-c300-42c4-9531-197daab18a4a" />
<img width=33.3% height="435" alt="image" src="https://github.com/user-attachments/assets/037e21b2-037c-42a9-80fe-35b53e15ac80" />
<img width=30.3% height="435" alt="image" src="https://github.com/user-attachments/assets/253150f2-7f39-4d22-9b51-d8a173c5e686" />

---
## Week 1 - Week 2 (Grid + Basics for A*) 11/02/2026

### What I implemented
This week I moved from a simply printing a grid to having a proper foundation that A* can use.

#### The Grid (map)
I created a `Grid` class to own the grid map and it is stored as `std::vector<std::string>`.  
The Grid is responsible for:
- Printing the map to the console.
- Finding the Start `S` and Goal `G` automatically.
- Checking if a coordinate is valid using `withinGrid(r, c)`.
- Checking if movement is allowed using `canMoveTo(r, c)`. The walls are represented by the `#`.

I also added a `cellAt(r, c)` helper so that the rest of the program doesn’t directly index the grid everywhere.

#### The Pos (coordinates)
I added: `struct Pos { int r; int c; };` which keeps the row/column together as one variable.
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/4e431d84-81a5-4da9-8e37-b7ecf75c2c05" />

#### The Manhattan heuristic
I implemented the Manhattan distance: `abs(a.r - b.r) + abs(a.c - b.c)`. 
This fomular gives an estimate value to guide the A*, but it is not the final length of the path. 
The movement is only up/down/left/right and there are no diagonal moves. 
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/7665217c-cb55-46a9-8d0a-d53a519e9afc" />
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/438bbd6a-2015-4c6c-9eac-8d2dbf892a9f" />

#### Neighbour generation (4 directions)
I added neighbour generation using 4-direction movement:
	•	Up, Down, Left, Right
Each neighbour is checked using canMoveTo() so we never go out of bounds or into walls.

#### Output 
<img width="905" height="400" alt="image" src="https://github.com/user-attachments/assets/107c3daf-d955-4e4d-8f79-92330630d395" />
The detected positions from the output are :
	•	Start = (0,0) because S is at row 0, col 0
	•	Goal  = (2,2) because G is at row 2, col 2

The calculated Manhattan distance:
	•	|0 - 2| + |0 - 2| = 2 + 2 = 4

The Neighbours of Start (0,0):
	•	Up (-1,0) is out of bounds 
	•	Left (0,-1) is out of bounds 
	•	Down (1,0) is valid and walkable 
	•	Right (0,1) is valid and walkable 

The goal G is fully surrounded by #, so there is no valid path in this grid map.

##### This is my main.cpp and Grid.cpp
<img width="405" height="400" alt="image" src="https://github.com/user-attachments/assets/fdfe22c0-7305-4e60-8cf7-6630a2fe4cbe" />

<img width="405" height="400" alt="image" src="https://github.com/user-attachments/assets/3ead13d7-b0b7-4b9a-b8fa-014a69a29336" />

 ###### In Summary
Grid is responsible for storing and validating the map. It finds S (Start) and G (Goal), while checking bounds and following the movement rules, and prints the grid. AStar currently contains the two main building blocks needed for the full algorithm: Manhattan heuristic and neighbour generation. For now the main.cpp just runs the demo to verify that everything works do far before implementing the full open/closed sets.

---

## Week 2 (17/02/2026)

**Goal:** The goal is to implement the core A* search algorithm using the Grid and heuristic foundations built in Week 1.

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

#### My Understanding of the code

- `g` represents how many steps have been taken from Start to the current node.
- `h` uses the Manhattan heuristic to estimate the remaining distance to the Goal.
- `f = g + h` determines which node should be explored next. The lower the `f`, the more promising the path.
- I separated the position data (`Pos`) from cost data (`Node`) to keep the code modular and easier to follow through.
---

### Priority Queue (Open Set)

To implement the A* open set,the `std::priority_queue` was used with a custom comparator:

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

#### My Understanding

- The open set holds all the nodes that are still to be explored and the node with the smallest `f` is always explored first.
- When two nodes share the same `f`, the one with the smaller `h` is preferred. This breaks ties in favour of nodes that are closer to the Goal, while reducing unnecessary exploration of the path.

### The Closed Set

```cpp
std::vector<std::vector<bool>> closedSet;
```

#### My Understanding

- Once a node is fully explored, it is added to the closed set and this prevents the algorithm from revisiting the same position with a worse cost.
- Without this, the algorithm could loop indefinitely on open grids.

### The A* Core Algorithm (`findPath`)

The `findPath()` function searches for a path from Start (S) to Goal (G). It first finds their positions, then adds the Start to a list of nodes to explore (open set) with zero cost. In a loop, it picks the most promising position based on its cost (f value). If it reaches the Goal, it returns the path. Otherwise, it marks the position as visited and checks its neighbours. Walkable neighbours are given updated costs and added to the list. This continues until the Goal is found or no path exists.


### The Blocked Goal
**The Console output:**
<img width="1112" height="624" alt="image" src="https://github.com/user-attachments/assets/80e1a2c7-8ba6-4f47-b2c8-7e4bde5136fb" />

The Goal `G` is completely surrounded by walls `#`, hence no valid path exists.
I tested the "no path" case before implementing path reconstruction because it is easy to detect if the code fuctions are working properly when l already know the output.Now l can add more complexity. 

### Path Reconstruction (Prepared, Not Yet Complete)

In `main.cpp` I added a `printPathOnGrid()` helper that copies the grid and marks the path from Start to Goal using *, without changing the original grid.
The next step is to track parent nodes in findPath() so the path can be traced 
<img width="1325" height="870" alt="image" src="https://github.com/user-attachments/assets/06357436-a5fd-4a14-aa93-4d399d3de1f2" />

---
## Week 3 (24/02/2026)

**Goal:** The goal is to refactor the existing code following the C++ Core Guidelines without changing what the algorithm does and to add some tests.

### The C++ Core Guidelines
<img width="1902" height="1018" alt="image" src="https://github.com/user-attachments/assets/1b32a5ef-6a8b-4ba3-831b-2e7034ed3cea" />
These are the rules I applied:

| Guideline | Rule |
|---|---|
| `F.3` | Keep functions short and focused on one task |
| `F.17` | Use `[[nodiscard]]` when ignoring a return value is almost certainly a bug |
| `C.45` | Don't define a default constructor that only initialises data members |
| `Enum.3` | Prefer `enum class` over plain `enum` |
| `Con.1` | By default, make variables `const` |
| `ES.20` | Always initialise variables at the point of declaration |
| `I.3` | Avoid singletons — pass dependencies explicitly |

The other reason why l separated the files per module was to make it easy for myself when l need to edit the functions respectively. 

### Change 1 


I added `[[nodiscard]]` on `findPath()` so that the compiler warns if the returned path is ignored. This would help prevent mistakes.

```cpp
// Before
std::vector<Pos> findPath(const Grid& grid) const;

// After
[[nodiscard]] std::vector<Pos> findPath(const Grid& grid) const;
```

### Change 2 

I added an `enum class Heuristic` to allow choosing between Manhattan and Euclidean distance. Before there was no option of having to choose.
```cpp
enum class Heuristic { Manhattan, Euclidean };
```

And a new estimate() function that selects the correct heuristic, making the algorithm more flexible without changing the main logic.

```cpp
int AStar::estimate(Pos a, Pos b) const {
    switch (heuristic_) {
        case Heuristic::Euclidean: return euclidean(a, b);
        default:                   return manhattan(a, b);
    }
}
```
Now l can change heuristic at construction time without having to change the rest of the algorithm. 

```cpp
AStar defaultSearch;                           // Manhattan
AStar euclideanSearch(Heuristic::Euclidean);   // Euclidean
```

### Change 3

I made variables l was not going to be changing `const` to avoid accidental changes. 


### Change 4 — `[[nodiscard]]` tie-breaking in `NodeCompare`

I simplified the comparator using a ternary operator, instead of a nested `if`. This keeps the function short (Core Guideline `F.3`) and makes the logic easier to read and understand.

```cpp
struct NodeCompare {
    bool operator()(const Node& a, const Node& b) const {
        return a.f == b.f ? a.h > b.h : a.f > b.f;
    }
};
```

### Change 5 

I replaced the raw value `+1` with a named constant `MOVE_COST` to make the code clearer. This makes the intent obvious.

```cpp
// Before — the meaning of 1 was not clear
const int tentativeG = g[p.r][p.c] + 1;

// After —now there's a named constant
constexpr int MOVE_COST = 1;  
const int tentativeG = g[p.r][p.c] + MOVE_COST;
```



### Change 6 — `runTest()` helper in `main.cpp`

The Core Guideline `F.3` says functions should do **one thing** so I moved the repeated test logic into a `runTest()` function to stop code repetition. 
Before this, the `main()` repeated the same print/run/check logic for every test. The `main()` is now just a list of test cases and I now find easy to follow through and edit. This s because the is now in one place and dding a new test is now one line instead of five

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

#### Test Cases Added

| Test | Grid | Expected |
|---|---|---|
| Default (enclosed goal) | `S` blocked by `#` ring | No path |
| Open grid | Clear path to `G` | Path found |
| Maze | Winding route through walls | Path found |
| Start adjacent to Goal | `SG` | 1 step |
| Fully blocked | `S#G` | No path |

---
## Week 4 (03/03/2026)

**Goal:** Claude suggested three improvements to improve my code, this is my review on them and my decisions on which ones fit the scope of my project. I also cleaned the code accordingly.

### Improvements
After completing the Week 3 refactor, I looked at a few suggested improvements from Claude and decided which ones were worth adding to this project.

#### 1. Weighted Terrain Cells
**What it is:**  
Weighted terrain means some cells cost more to move through than others. For example, a `W` tile could cost 3 instead of 1, so A* would choose the cheapest path overall and not just the shortest.

**Why I am not implementing it:**  
The project's requirement is meant to show how A* works in a simple grid. Adding weighted terrain would make it more complex without adding much value to the core idea. But this would be good to add in things like the google maps.

#### 2. Load Grid From a File
**What it is:**  
Instead of hardcoding grids, the program would read them from a `.txt` file. This would make it easier to test different maps without changing the code.

**Why I am not implementing it:**  
For this project, the test grids are fixed and already cover the main cases. Adding file handling would add extra complexity without improving the demonstration of A*.


#### 3. Node Expansion Counter
**What it is:**  
This counts how many nodes A* processes during the search. So it basically shows how much work the algorithm is doing.

**Why I am implementing it:**  
This addition helps show how well the heuristic guides the algorithm.

### Cleaning the Code by Removing Euclidean

#### Why I removed Euclidean  

In Week 3, I added a `Heuristic` enum and a Euclidean function to show that the algorithm could support different heuristics. However, after reviewing the project, I realised this was not needed.

#### My Understanding  

Manhattan distance matches how movement works on this grid — only up, down, left, and right. It gives a good estimate of the real cost and guides the search efficiently.

Euclidean distance assumes diagonal movement, which is not allowed here. Because of this, it is less accurate for this problem and does not improve the result.

#### After cleanup  

I removed the `Heuristic` enum, the `euclidean()` function, and the `estimate()` dispatcher. The algorithm now uses Manhattan distance directly.

The output stayed the same, since Manhattan was already the default, but the code is now simpler and more focused on the actual problem.
<img width="641" height="1017" alt="image" src="https://github.com/user-attachments/assets/34dcc6f2-1e7f-482d-a8af-cec098d4267c" />

---
## Week 5 (10/03/2026)

**Goal:** Implementing the node expansion counter inside `findPath()` so the algorithm's effort is visible for each test case.

---

### What I Added

A counter variable to `AStar_Path.cpp` inside `findPath()`:


#### Before — no visibility into how much work A* is doing
<img width="481" height="442" alt="image" src="https://github.com/user-attachments/assets/dcfb6c07-f65f-4a61-b1fe-b6f18c999b26" />

 ####After — counter declared before the loop, incremented and printed inside it
<img width="458" height="486" alt="image" src="https://github.com/user-attachments/assets/81a97386-b83b-4d2d-9f9d-1be3d8512a03" />


#### My Understanding

The counter sits **after** the lazy deletion check (`if (closed[p.r][p.c]) continue`). This is deliberate as it only counts nodes that are actually processed, not ones that are skipped because they were already visited. Counting skipped nodes would give a misleading number.

The counter is printed in two places:
1. when the Goal is reached 
2. when no path exists
-so that every test always reports a count.

---







### A Bug l Encountered

During implementation the `if (p == goal)` block, it was written without curly braces:

<img width="453" height="82" alt="image" src="https://github.com/user-attachments/assets/0c7cd0ab-bc38-46ce-9336-0254a45d7c60" />


Without braces, only the `cout` line belongs to the `if`. The `return` line ran unconditionally on every loop iteration — meaning A* returned on the very first node (Start), which had no valid parent, so every test returned an empty path and printed "No path found." This is because without braces, adding a second line to an if body silently breaks logic. I should have followed the ES.85 guideline regardless of having an inline fuction even befoe having to change code. I wouldn't have had the bug then. This made me realise how important it is to follow the coding rules even when it doesn't cost doing otherwise because it always will at some point. Just like it did with the crowd strike we've learnt  from the C++ module.

### ES.85 c++ Core Guidelines
https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#es85-make-empty-statements-visible
<img width="924" height="433" alt="image" src="https://github.com/user-attachments/assets/d45a51c0-5490-419e-9bdf-503c3f064aba" />


### Console Output before fixing the bug
<img width="1659" height="961" alt="image" src="https://github.com/user-attachments/assets/974e7456-c4ec-4680-80d6-559a3687543f" />


I had to follow the c++ guidelines, that say we have to put braces when using if statements. Even though the code was wrongly written, the compiler does not warn about it because the code is technically still valid. This is because indentation does not define scope, but braces do.
<img width="638" height="82" alt="image" src="https://github.com/user-attachments/assets/f8a072fc-2416-4d1b-915d-99a3c2e60deb" />

---

### Console Output after fixing the code

<img width="573" height="986" alt="image" src="https://github.com/user-attachments/assets/6d91cade-35ed-462e-b3b4-c8d903f580b5" />

After this bug l ended up going through my code to see if there's anywhere l don't have braces and applying the guideline
In my main.cpp in my printPathOnGrid

<img width="529" height="353" alt="image" src="https://github.com/user-attachments/assets/f65f56e0-5f91-452b-8334-74795e898252" />

 And in the Grid.cpp, the findMarker() had some missing braces.
 
 <img width="336" height="99" alt="image" src="https://github.com/user-attachments/assets/d4c8eccb-e96b-4269-8a8c-9ed5a0ec29fc" />
 
In AStar_Path.cpp the lazy detection was missing braces 

<img width="456" height="60" alt="image" src="https://github.com/user-attachments/assets/96217044-5eb4-4a7e-b29b-225f62089070" />

And in the AStar_Neighbours.cpp

<img width="485" height="234" alt="image" src="https://github.com/user-attachments/assets/5dfee718-0225-4006-ac51-d9147afffb36" />


---

### Understanding the Results

| Test | Nodes expanded | What it shows |
|---|---|---|
| Enclosed goal | 16 | A* explored the entire reachable area before confirming no path existed |
| Open grid | 5 | Manhattan guided A* almost directly to the Goal — very efficient |
| Maze grid | 9 | More exploration needed but still focused, not exhaustive |
| Start adjacent to Goal | 2 | Start processed, Goal found on the first neighbour — trivial case |
| Fully blocked | 1 | Only Start was processed, no walkable neighbours existed |

The open grid result is the clearest demonstration of why Manhattan works well. A* found a 4-step path on a 5×5 grid (25 cells total) while only processing 5 nodes. The heuristic directed the search efficiently rather than exploring the grid blindly.

---

# Week 6 (17/03/2026)

The goal was to refactor `main.cpp` by separating helper functions into their own files, improving modularity and applying the Single Responsibility Principle.

---

## Why I Refactored `main.cpp`

By Week 5, `main.cpp` contained three distinct responsibilities in one file:

- **Visualisation** — `printPathOnGrid()` built a copy of the grid and stamped `*` on the path
- **Testing** — `runTest()` ran the algorithm on a named grid and reported the result
- **Orchestration** — `main()` set up the grids and called the tests

 This principle is also reflected in **C++ Core Guideline:**

-  *C++ Core Guidelines — F.3: Keep functions short and focused*. Available at: [https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f3-keep-functions-short-and-focused](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rf-single)
-  *C++ Core Guidelines — F.1: Package meaningful operations as carefully named functions*. Available at:[ https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f1-package-meaningful-operations-as-carefully-named-functions](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rf-package)
Having all three functions in one file makes the code harder to maintain and follow up.

---

## What I Created

### `Display.h` / `Display.cpp`

`printPathOnGrid()` was extracted into its own file pair.

```cpp
// Display.h
void printPathOnGrid(const Grid& grid, const std::vector<Pos>& path);
```

**Why:** Displaying a result on screen is a *presentation* concern and has nothing to do with running a test or coordinating the program. Isolating it means if the display format ever needs to change only the `Display.cpp` would need to be touched.

---

### `TestRunner.h` / `TestRunner.cpp`

`runTest()` was extracted into its own file pair.

```cpp
// TestRunner.h
void runTest(const std::string& name, const Grid& grid);
```

**Why:** Running a test — calling `findPath()`, checking whether a path was returned, printing the result — is a *testing* concern and separating it means `main()` is now just a list of test cases. The logic for what a test *does* lives in one place and only needs to be written once. This also applies the **DRY principle**, now the same if/else logic no longer needs to be repeated for every test case.

---

### `main.cpp` (after refactor)

`main()` now only does one thing: construct grids and call `runTest()` and contains no logic of its own.

`main.cpp` does not need to know about `Display` at all — `TestRunner` handles that internally. This is called **loose coupling** where each file depends only on what it directly needs.

---

## File Structure After Week 6
<img width="356" height="490" alt="image" src="https://github.com/user-attachments/assets/05413934-6cd3-4a47-bf7b-182b6f8caa3d" />

## Adding Exception Handling
I added a `try/catch` exception just to demonstrate what we learnt in the lab.
### Where I Added It and Why

#### `Grid.cpp` (throw the error)
<img width="785" height="380" alt="image" src="https://github.com/user-attachments/assets/6da50cb6-b91a-48b3-9f86-6b2eb110d99f" />

###### Why here?
An empty grid cannot have a Start or Goal position. If one reached `findPath()`, it would silently create zero-sized 2D vectors and produce a wrong result with no error message. Throwing at construction time enforces the rule that a `Grid` object must always be in a valid state. The error is raised as close to its cause as possible, rather than surfacing silently later.

#### `TestRunner.cpp` (catch the error)
<img width="706" height="646" alt="image" src="https://github.com/user-attachments/assets/8552a5e6-234a-4f96-81b4-77b8c83b5f71" />

###### Why here?
`runTest()` handles one test case from start to finish. Catching here means one bad test does not crash the entire program. The error is printed to `std::cerr` (the error output stream, separate from `std::cout`) and the next test continues normally.
 
`const std::exception& e` catches the base class of all standard exceptions, including `std::invalid_argument`. Catching the base class rather than the specific type means this handler would also cover any other standard exception thrown during the test, not just the one from `Grid`.
 
`e.what()` returns the message string that was passed when the exception was constructed — in this case `"Grid cannot be constructed from an empty map."`.

# Code Review and Analysis
 ## Some of the module concepts l adapted in this project

### Abstraction
`canMoveTo(r, c)` hides the rule for what counts as walkable. The caller simply asks a yes/no question. Whether walkability is determined by a character check, a flag array, or a database lookup is irrelevant to the caller.
 
### Composition
`Node` contains a `Pos`. `Grid` contains a `vector<string>`. This is composition — classes owning objects of other classes — rather than inheritance, which is the appropriate relationship here since a `Node` is not a kind of `Pos`, it simply uses one.
 
### Operator Overloading
`Pos` defines `operator==` and `operator!=`. This makes `if (p == goal)` readable and natural in the algorithm, rather than writing `if (p.r == goal.r && p.c == goal.c)` repeatedly.
 
### Constructors and the `explicit` keyword
`Grid` has two constructors — a default one (hardcoded map) and one taking a `vector<string>`. The second is marked `explicit`, which prevents the compiler from silently constructing a `Grid` from a vector passed to a function expecting a `Grid`.
 
### Exception Handling
`Grid`'s constructor throws `std::invalid_argument` if given an empty vector. `TestRunner::runTest()` wraps each test in `try/catch(const std::exception& e)`. This demonstrates that errors should be thrown where they are detected and caught where they can be meaningfully handled.

 ### Encapsulation
`Grid` stores its map in a `private` member `data_`. External code cannot index it directly — it must use `cellAt()`, `canMoveTo()`, or `withinGrid()`. This means if the internal representation ever changed (e.g. from `vector<string>` to a flat array), nothing outside `Grid.cpp` would need to change.
 
### RAII
No `new` or `delete` appears anywhere in the project. All memory is managed through `std::vector`, which allocates on construction and frees on destruction. When `findPath()` returns, all its local vectors  : `g`, `parent`, `closed`, the priority queue — are destroyed automatically. This prevents memory leaks without requiring to manually cleanup the code.
 
### Modular File Structure
Header guards (`#ifndef / #define / #endif`) appear in every `.h` file. These prevent the contents of a header from being pasted into a translation unit more than once, which would cause duplicate definition errors at link time.
 
### Standard Libraries I Used
| Component | Where used | Purpose |
|---|---|---|
| `std::vector` | Throughout | Primary container for all dynamic data |
| `std::priority_queue` | `AStar_Path.cpp` | Open set — always extracts cheapest node |
| `std::reverse` | `reconstructPath()` | Flips the path from goal→start to start→goal |
| `std::numeric_limits` | `AStar_Path.cpp` | Provides `INF` without a magic number |
| `std::invalid_argument` | `Grid.cpp` | Standard exception type for bad input |


##  Memory Layout
 
### Stack vs Heap
Local variables in `findPath()` — `start`, `goal`, `rows`, `cols`, `cur`, loop counters — live on the stack and are freed automatically when the function returns. The headers of each `vector` also live on the stack. The actual contents of those vectors live on the heap and is managed by `vector`'s internal allocator.
 
### Heap usage during a 5×5 search
```
g[5][5]       — 25 integers        (100 bytes at 4 bytes/int)
parent[5][5]  — 25 Pos objects     (200 bytes at 8 bytes/Pos)
closed[5][5]  — 25 bools           (25 bytes minimum)
open          — up to 25 Nodes     (up to ~500 bytes)
```

## UML Class Diagram
<img width="424" height="476" alt="image" src="https://github.com/user-attachments/assets/038a4470-5db1-44b1-8879-5e04a2212e46" />

## Memory Diagram
<img width="413" height="447" alt="image" src="https://github.com/user-attachments/assets/a7e6bb30-4de6-4265-be51-e6e5babdbb90" />

## Compilation Process
The project moves through four stages:
 
**Preprocessor:** Each `.cpp` file is expanded independently. `#include` directives are replaced with the full text of the named header. Header guards ensure no header is pasted twice into the same translation unit. After this stage there are no `#include` directives remaining but only pure C++.
 
**Compiler:** Each expanded file is compiled to assembly (`.s`). The compiler type checks every expression, verifies function signatures against their declarations, and applies optimisations. It trusts declarations in headers — it does not need to see `neighbours()` defined to compile `AStar_Path.cpp`, only declared.
 
**Assembler:** Each `.s` file is converted to a machine-code object file (`.o`). At this point the project consists of seven independent object files: `Grid.o`, `AStar_Path.o`, `AStar_Heuristic.o`, `AStar_Neighbours.o`, `Display.o`, `TestRunner.o`, `main.o`.
 
**Linker:** All `.o` files are combined into one executable. The linker resolves every function call to its definition — `main.o`'s call to `runTest` is matched to `TestRunner.o`, `TestRunner.o`'s call to `findPath` is matched to `AStar_Path.o`. An "undefined reference" error at this stage means a function was declared but never defined.
 
The benefit of the modular split l did in relation to the compilation process is that if only `Display.cpp` changes, only `Display.o` needs recompiling. The linker then stitches the new `Display.o` with the unchanged object files. This incremental compilation becomes significant as a project grows.
 

#References
A*Algotithm explained - https://www.geeksforgeeks.org/dsa/a-search-algorithm/ , https://github.com/JDSherbert/A-Star-Pathfinding
The C++ version choice - https://www.geeksforgeeks.org/cpp/c-11-vs-c-14-vs-c-17/ 

*C++ Core Guidelines — F.3: Keep functions short and focused*. Available at: [https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f3-keep-functions-short-and-focused](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rf-single)
*C++ Core Guidelines — F.1: Package meaningful operations as carefully named functions*. Available at:[ https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#f1-package-meaningful-operations-as-carefully-named-functions
](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#rf-package)

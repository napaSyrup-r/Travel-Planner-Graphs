# Travel Planner Using Graphs

A console-based travel route optimization system implemented in C. Given a set of locations and the weights between them (distance, time, or cost), the program computes the most efficient path using three classical graph algorithms.

This was built as a university project for CSE246 to demonstrate practical application of graph data structures and shortest-path algorithms.

---

## What It Does

The program models a travel network as a weighted directed graph, where:

- **Nodes** represent locations
- **Edges** represent routes between locations
- **Weights** represent distance, travel time, or cost (user's choice)

The user inputs the graph manually and then selects an algorithm to compute optimal routes.

---

## Algorithms Implemented

### 1. Dijkstra's Algorithm
- **Type:** Single-source shortest path
- **Best for:** Non-negative weights
- **Time Complexity:** O(V^2) with adjacency matrix
- **Use case:** Finding the shortest path from one specific location to another

### 2. Floyd-Warshall Algorithm
- **Type:** All-pairs shortest path
- **Best for:** Dense graphs where you need routes between every pair of locations
- **Time Complexity:** O(V^3)
- **Use case:** Precomputing shortest paths between all location pairs

### 3. Bellman-Ford Algorithm
- **Type:** Single-source shortest path
- **Best for:** Graphs that may contain negative weight edges
- **Time Complexity:** O(V * E)
- **Use case:** More flexible alternative to Dijkstra when edge weights can be negative

---

## How to Compile and Run

**Requirements:** GCC or any standard C compiler

**Compile:**
```bash
gcc travel_planner.c -o travel_planner
```

**Run:**
```bash
./travel_planner
```

---

## Usage Walkthrough

1. Enter the number of locations (nodes).
2. Choose the weight type: `Distance`, `Time`, or `Cost`.
3. Enter the weight for every directed route between locations. Enter `0` if no direct route exists.
4. From the menu, select an algorithm:
   - **Option 1** (Dijkstra): Enter source and destination to get the shortest path.
   - **Option 2** (Floyd-Warshall): Computes all-pairs shortest paths.
   - **Option 3** (Bellman-Ford): Enter source to compute distances to all other locations.
5. Select option `4` to exit.

---

## Example

```
Enter number of locations: 4

Choose weight type for travel:
1. Distance
2. Time
3. Cost
Enter your choice: 1

Enter weights for every route between locations:
Enter weight from location 0 to location 1: 10
Enter weight from location 0 to location 2: 0
...

Choose an algorithm to compute the shortest path:
1. Dijkstra's Algorithm (Single Source Shortest Path)
2. Floyd-Warshall Algorithm (All Pairs Shortest Paths)
3. Bellman-Ford Algorithm (Single Source Shortest Path)
4. Exit
Enter your choice: 1

Enter source location (index 0 to 3): 0
Enter destination location (index 0 to 3): 3

Shortest distance from location 0 to location 3: 25
```

## Known Limitations

- **No negative cycle detection:** Bellman-Ford does not check for or report negative cycles, which can produce incorrect results silently.
- **Manual graph input only:** No file import support despite being listed in the original project specification.
- **Minimal output:** Dijkstra prints the shortest distance but not the actual path sequence. Floyd-Warshall and Bellman-Ford only confirm computation without printing results.
- **No input validation:** Out-of-range indices or non-integer inputs will cause undefined behavior.
- **Fixed graph size:** Maximum of 100 nodes, hardcoded via `#define MAX 100`.

---

## Potential Improvements

- Print the full node path, not just the total cost, for Dijkstra
- Add negative cycle detection to Bellman-Ford
- Support graph input from a file (.txt or .csv)
- Replace index-based references with named locations
- Implement a priority queue for Dijkstra to improve time complexity to O((V + E) log V)

---

## Academic Context

- **Course:** CSE246 - Data Structures and Algorithms
- **Language:** C
- **Concepts Covered:** Graph representation (adjacency matrix), shortest path algorithms, dynamic programming (Floyd-Warshall), greedy algorithms (Dijkstra), edge relaxation (Bellman-Ford)

---

## License

This project is submitted for academic purposes. Reuse or submission of this code as your own work in any academic setting is a violation of academic integrity policies.

# 🚀 Undirected Graph Cycle

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1) |

---

### 📝 Problem Statement

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not. 
Note: The graph can have multiple component.
Examples:


### Input:
 V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]


### Output:
 true


### Explanation:
 
 1 -> 2 -> 0 -> 1 is a cycle.



### Input:
 V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]


### Output:
 false


### Explanation:
 
 No cycle in the graph.



### Constraints:
1 ≤ V, E ≤ 1050 ≤ edges[i][0], edges[i][1] < V

---

### 🏢 Topic Tags

> `DFS` `Graph` `union-find`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>
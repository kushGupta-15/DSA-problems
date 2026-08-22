# 🚀 Minimum Spanning Tree

---

### 📊 Quick Overview

| Metadata | Details |
| :--- | :--- |
| **Difficulty** | 🟡 ![Medium](https://img.shields.io/badge/Medium-important?style=for-the-badge&logoColor=white) |
| **Language** | `C++ (17)` |
| **Problem Link** | [🔗 Challenge Link](https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1) |

---

### 📝 Problem Statement

Given a weighted, undirected, and connected graph with V vertices and a 2D array edges[][], where each element edges[i] = [u, v, w] represents an edge between vertices u and v with weight w, return the sum of the weights of all edges in the graph's Minimum Spanning Tree (MST).


### Input:
 V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
 

### Output:
 4


### Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.


### Input:
 V = 2, E = 1, Edges = [[0 1 5]] 

### Output:
 5 

### Explanation:
 Only one Spanning Tree is possible which has a weight of 5.


### Constraints:
2 ≤ V ≤ 1000V-1 ≤ E ≤ (V*(V-1))/21 ≤ w ≤ 1000The graph is connected and doesn't contain self-loops & multiple edges.

---

### 🏢 Topic Tags

> `Greedy` `Graph`

---

### 💡 Solution Approach

The complete execution code can be found in the solution file. It uses an optimized approach to solve the problem efficiently.

👉 **View Solution:** [`solution.cpp`](./solution.cpp)

---
<sub>*Automated repository update.*</sub>
# DFS / BFS

## Breadth-First Search (BFS)

BFS is an algorithm for traversing or searching tree or graph data structures. It starts at a selected node (the "source") and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

### 🤔 How it works
*   It uses a **queue** (First-In, First-Out) data structure.
*   Start by adding the source node to the queue and marking it as visited.
*   While the queue is not empty, remove the first node from the queue.
*   Visit all of its unvisited neighbors, mark them as visited, and add them to the queue.
*   This process continues until the queue is empty, ensuring that nodes are explored level by level.

### ✨ Key Characteristics
*   **Finds the shortest path** in an unweighted graph.
*   It is a **complete** algorithm, meaning if a solution exists, BFS is guaranteed to find it.
*   Can be more memory-intensive, especially for wide graphs.

### 📖 Applications
*   **Shortest Path Finding:** Used in GPS navigation to find the shortest route.
*   **Web Crawlers:** Search engine crawlers use BFS to discover and index web pages.
*   **Social Networks:** Finding all friends of a person at a specific distance or level.

---

## Depth-First Search (DFS)

DFS is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node and explores as far as possible along each branch before backtracking.

### 🤔 How it works
*   It uses a **stack** (Last-In, First-Out) data structure, which can be implemented with recursion.
*   Start from a source node, mark it as visited, and push it onto the stack.
*   Take the top item from the stack and explore one of its unvisited neighbors.
*   Mark the neighbor as visited and push it onto the stack.
*   This process continues until it reaches a "dead end" (a node with no unvisited neighbors).
*   It then backtracks by popping from the stack to the previous node and explores another unvisited branch.

### ✨ Key Characteristics
*   **Less memory-intensive** than BFS.
*   May not find the shortest path.
*   Can get stuck in infinite loops in graphs with cycles if not implemented carefully (by keeping track of visited nodes).

### 📖 Applications
*   **Cycle Detection:** Detecting cycles in a graph.
*   **Solving Puzzles:** Such as mazes and Sudoku puzzles.
*   **Topological Sorting:** Used for scheduling tasks with dependencies.

---

## 🔥 LeetCode Problems

### BFS
- [Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) (Medium)
- [Rotting Oranges](https://leetcode.com/problems/rotting-oranges/) (Medium)
- [01 Matrix](https://leetcode.com/problems/01-matrix/) (Medium)
- [Word Ladder](https://leetcode.com/problems/word-ladder/) (Hard)

### DFS
- [Number of Islands](https://leetcode.com/problems/number-of-islands/) (Medium)
- [Flood Fill](https://leetcode.com/problems/flood-fill/) (Easy)
- [Clone Graph](https://leetcode.com/problems/clone-graph/) (Medium)
- [Course Schedule](https://leetcode.com/problems/course-schedule/) (Medium)
- [Keys and Rooms](https://leetcode.com/problems/keys-and-rooms/) (Medium)
- [Alien Dictionary](https://leetcode.com/problems/alien-dictionary/) (Hard)
- [Word Ladder II](https://leetcode.com/problems/word-ladder-ii/) (Hard)


💬 **Discussion**: [LeetCode DFS/BFS Guide](https://leetcode.com/discuss/general-discussion/657507/)
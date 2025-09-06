# Greedy Algorithm

A greedy algorithm is a problem-solving strategy that makes the most optimal choice at each step, without considering the overall problem. It focuses on the immediate, or local, best option with the hope that these choices will lead to a globally optimal solution.

### ⭐ Key Properties

For a greedy algorithm to guarantee a globally optimal solution, the problem must have two specific properties:

1.  **Greedy Choice Property:** A globally optimal solution can be achieved by making a locally optimal choice at each step.
2.  **Optimal Substructure:** The optimal solution to the entire problem contains the optimal solutions of its subproblems.

---

### 👍 Advantages
*   **Simplicity:** They are often easier to describe and implement than other algorithms.
*   **Speed:** Their lower time complexity makes them efficient for certain problems.

### 👎 Disadvantages
*   **Not Always Optimal:** The main drawback is that they do not guarantee a globally optimal solution for all problems.
*   **Hard to Prove Correctness:** It can be challenging to prove that a greedy algorithm will be optimal for a given problem.

---

### 📖 Common Applications
*   **Making Change:** Using the largest denominations first.
*   **Dijkstra's Algorithm:** Finding the shortest path in a graph.
*   **Kruskal's and Prim's Algorithms:** Finding the minimum spanning tree in a graph.
*   **Huffman Coding:** For lossless data compression.

---

## 🔥 LeetCode Problems

### Easy
- [Assign Cookies](https://leetcode.com/problems/assign-cookies/)
- [Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/)
- [Lemonade Change](https://leetcode.com/problems/lemonade-change/)
- [Is Subsequence](https://leetcode.com/problems/is-subsequence/)
- [Can Place Flowers](https://leetcode.com/problems/can-place-flowers/)

### Medium
- [Jump Game](https://leetcode.com/problems/jump-game/)
- [Jump Game II](https://leetcode.com/problems/jump-game-ii/)
- [Gas Station](https://leetcode.com/problems/gas-station/)
- [Partition Labels](https://leetcode.com/problems/partition-labels/)
- [Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/)
- [Task Scheduler](https://leetcode.com/problems/task-scheduler/)
- [Two City Scheduling](https://leetcode.com/problems/two-city-scheduling/)

### Hard
- [Candy](https://leetcode.com/problems/candy/)
- [Minimum Number of Refueling Stops](https://leetcode.com/problems/minimum-number-of-refueling-stops/)
- [Race Car](https://leetcode.com/problems/race-car/)
- [Split Array Largest Sum](https://leetcode.com/problems/split-array-largest-sum/)

💬 **Discussion**: [LeetCode Greedy Guide](https://leetcode.com/discuss/general-discussion/657507/)
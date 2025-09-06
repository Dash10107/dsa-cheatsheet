# Dynamic Programming (DP)

Dynamic programming (DP) is an algorithmic paradigm for solving complex problems by breaking them down into a collection of simpler, overlapping subproblems. The core idea is to solve each subproblem only once and store its result, avoiding redundant computations.

### ⭐ Key Characteristics

1.  **Optimal Substructure:** A problem has optimal substructure if the optimal solution to the overall problem can be constructed from the optimal solutions of its subproblems.
2.  **Overlapping Subproblems:** This property means that a recursive algorithm for the problem solves the same subproblems multiple times. DP stores the solutions to these subproblems to be reused.

---

### 🚀 Approaches

1.  **Memoization (Top-Down):** This is a recursive approach. You write a standard recursive function, but before computing a result, you check if the solution for the specific subproblem has already been calculated and stored in a lookup table.
2.  **Tabulation (Bottom-Up):** This is an iterative approach. It solves the problem by starting from the smallest possible subproblems and building up to the final solution. The results are stored in a table (typically an array).

---

### 📖 Common Applications
*   Shortest path algorithms in a graph (e.g., Bellman-Ford, Floyd-Warshall).
*   The Knapsack problem.
*   Sequence alignment in bioinformatics.
*   Matrix chain multiplication.
*   Coin change problems.

---

## 🔥 LeetCode Problems

### Easy
- [Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
- [House Robber](https://leetcode.com/problems/house-robber/)
- [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
- [Counting Bits](https://leetcode.com/problems/counting-bits/)

### Medium
- [Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
- [Coin Change](https://leetcode.com/problems/coin-change/)
- [Word Break](https://leetcode.com/problems/word-break/)
- [Unique Paths](https://leetcode.com/problems/unique-paths/)
- [Minimum Path Sum](https://leetcode.com/problems/minimum-path-sum/)
- [Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)

### Hard
- [Word Break II](https://leetcode.com/problems/word-break-ii/)
- [Edit Distance](https://leetcode.com/problems/edit-distance/)

💬 **Discussion**: [LeetCode Dynamic Programming Guide](https://leetcode.com/discuss/post/662866/DP-for-Beginners-Problems-or-Patterns-or-Sample-Solutions/)
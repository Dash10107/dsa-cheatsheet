# Backtracking

Backtracking is a problem-solving algorithm that finds solutions by incrementally building a candidate solution and abandoning it as soon as it determines that the candidate cannot possibly be completed to a valid solution. It uses a brute-force, exhaustive search approach by trying all possible solutions to find the desired output.

### 🤔 How it Works

The backtracking algorithm can be visualized as a depth-first search (DFS) of a state-space tree, which represents all possible states of a problem. The process generally follows these steps:

1.  **Start** at the root of the tree.
2.  **Explore** a path by making a choice.
3.  **Check** if the current choice leads to a valid solution.
    *   If it does, you have found a solution.
    *   If it's not a solution but is still viable, continue to the next level.
    *   If the choice leads to a "dead end" or violates a constraint, "backtrack" to the previous decision point.
4.  **Repeat** the process by trying a new, unexplored choice.
5.  The algorithm **ends** when all paths have been explored.

A key feature of backtracking is **pruning**. By abandoning paths that violate constraints, the algorithm can avoid exploring large portions of the state-space tree, making it more efficient than a simple brute-force search.

### 📖 When to Use
For generating all possible solutions and constraint satisfaction problems. Common examples include:

*   **Puzzles:** Such as Sudoku, N-Queens Problem, and crossword puzzles.
*   **Pathfinding:** Finding a path in a maze.
*   **Combinatorial Problems:** Generating all possible permutations, combinations, or subsets of a set.
*   **Scheduling and Resource Allocation:** Solving problems where specific constraints must be met.

### ⏱ Complexity
- Time: O(b^d) where b is branching factor, d is depth
- Space: O(d)

---

## 🔥 LeetCode Problems

### Subsets
- [Subsets](https://leetcode.com/problems/subsets/) (Easy)
- [Subsets II](https://leetcode.com/problems/subsets-ii/) (Medium)

### Combinations
- [Combinations](https://leetcode.com/problems/combinations/) (Medium)
- [Combination Sum](https://leetcode.com/problems/combination-sum/) (Medium)
- [Combination Sum II](https://leetcode.com/problems/combination-sum-ii/) (Medium)

### Permutations
- [Permutations](https://leetcode.com/problems/permutations/) (Medium)
- [Permutations II](https://leetcode.com/problems/permutations-ii/) (Medium)

### Other
- [Generate Parentheses](https://leetcode.com/problems/generate-parentheses/) (Easy)
- [Letter Combinations of a Phone Number](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) (Medium)
- [Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/) (Medium)
- [Word Search](https://leetcode.com/problems/word-search/) (Medium)
- [N-Queens](https://leetcode.com/problems/n-queens/) (Hard)
- [Word Search II](https://leetcode.com/problems/word-search-ii/) (Hard)
- [Sudoku Solver](https://leetcode.com/problems/sudoku-solver/) (Hard)


💬 **Discussion**: [LeetCode Backtracking Guide](https://leetcode.com/discuss/general-discussion/657507/)
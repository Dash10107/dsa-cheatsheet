"""
Backtracking Pattern Template
============================

This template provides common backtracking implementations for various problem types.
"""

def generate_permutations(nums):
    """
    Generate all permutations of array.
    
    Args:
        nums: Array of integers
    
    Returns:
        List of all permutations
    """
    result = []
    
    def backtrack(path):
        if len(path) == len(nums):
            result.append(path[:])
            return
        
        for num in nums:
            if num not in path:
                path.append(num)
                backtrack(path)
                path.pop()
    
    backtrack([])
    return result


def generate_combinations(n, k):
    """
    Generate all combinations of k numbers from 1 to n.
    
    Args:
        n: Upper bound
        k: Number of elements in combination
    
    Returns:
        List of all combinations
    """
    result = []
    
    def backtrack(start, path):
        if len(path) == k:
            result.append(path[:])
            return
        
        for i in range(start, n + 1):
            path.append(i)
            backtrack(i + 1, path)
            path.pop()
    
    backtrack(1, [])
    return result


def combination_sum(candidates, target):
    """
    Find all unique combinations that sum to target.
    
    Args:
        candidates: Array of candidate numbers
        target: Target sum
    
    Returns:
        List of all unique combinations
    """
    result = []
    candidates.sort()
    
    def backtrack(start, path, remaining):
        if remaining == 0:
            result.append(path[:])
            return
        
        for i in range(start, len(candidates)):
            if candidates[i] > remaining:
                break
            
            path.append(candidates[i])
            backtrack(i, path, remaining - candidates[i])
            path.pop()
    
    backtrack(0, [], target)
    return result


def solve_n_queens(n):
    """
    Solve N-Queens problem.
    
    Args:
        n: Size of chessboard
    
    Returns:
        List of all valid solutions
    """
    result = []
    
    def is_safe(board, row, col):
        # Check column
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        
        # Check diagonal (top-left to bottom-right)
        i, j = row - 1, col - 1
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j -= 1
        
        # Check diagonal (top-right to bottom-left)
        i, j = row - 1, col + 1
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i -= 1
            j += 1
        
        return True
    
    def backtrack(row, board):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        
        for col in range(n):
            if is_safe(board, row, col):
                board[row][col] = 'Q'
                backtrack(row + 1, board)
                board[row][col] = '.'
    
    board = [['.' for _ in range(n)] for _ in range(n)]
    backtrack(0, board)
    return result


def solve_sudoku(board):
    """
    Solve Sudoku puzzle.
    
    Args:
        board: 9x9 Sudoku board
    
    Returns:
        True if solvable, False otherwise
    """
    def is_valid(board, row, col, num):
        # Check row
        for j in range(9):
            if board[row][j] == num:
                return False
        
        # Check column
        for i in range(9):
            if board[i][col] == num:
                return False
        
        # Check 3x3 box
        start_row, start_col = 3 * (row // 3), 3 * (col // 3)
        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if board[i][j] == num:
                    return False
        
        return True
    
    def backtrack():
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for num in '123456789':
                        if is_valid(board, i, j, num):
                            board[i][j] = num
                            if backtrack():
                                return True
                            board[i][j] = '.'
                    return False
        return True
    
    return backtrack()


def generate_parentheses(n):
    """
    Generate all valid parentheses combinations.
    
    Args:
        n: Number of pairs of parentheses
    
    Returns:
        List of all valid combinations
    """
    result = []
    
    def backtrack(path, open_count, close_count):
        if len(path) == 2 * n:
            result.append(''.join(path))
            return
        
        if open_count < n:
            path.append('(')
            backtrack(path, open_count + 1, close_count)
            path.pop()
        
        if close_count < open_count:
            path.append(')')
            backtrack(path, open_count, close_count + 1)
            path.pop()
    
    backtrack([], 0, 0)
    return result


def word_search_ii(board, words):
    """
    Find all words from dictionary in the board.
    
    Args:
        board: 2D board of characters
        words: List of words to search for
    
    Returns:
        List of found words
    """
    # Build trie
    trie = {}
    for word in words:
        node = trie
        for char in word:
            node = node.setdefault(char, {})
        node['$'] = word
    
    result = []
    rows, cols = len(board), len(board[0])
    
    def backtrack(row, col, node, path):
        if '$' in node:
            result.append(node['$'])
            del node['$']  # Avoid duplicates
        
        if (row < 0 or row >= rows or col < 0 or col >= cols or 
            board[row][col] not in node):
            return
        
        char = board[row][col]
        board[row][col] = '#'  # Mark as visited
        
        # Explore all 4 directions
        for dr, dc in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            backtrack(row + dr, col + dc, node[char], path + char)
        
        board[row][col] = char  # Restore
    
    for i in range(rows):
        for j in range(cols):
            backtrack(i, j, trie, '')
    
    return result


def palindrome_partitioning(s):
    """
    Partition string into palindromic substrings.
    
    Args:
        s: Input string
    
    Returns:
        List of all possible partitions
    """
    result = []
    
    def is_palindrome(string):
        return string == string[::-1]
    
    def backtrack(start, path):
        if start == len(s):
            result.append(path[:])
            return
        
        for end in range(start + 1, len(s) + 1):
            substring = s[start:end]
            if is_palindrome(substring):
                path.append(substring)
                backtrack(end, path)
                path.pop()
    
    backtrack(0, [])
    return result


def subset_sum(nums, target):
    """
    Find all subsets that sum to target.
    
    Args:
        nums: Array of integers
        target: Target sum
    
    Returns:
        List of all subsets that sum to target
    """
    result = []
    nums.sort()
    
    def backtrack(start, path, remaining):
        if remaining == 0:
            result.append(path[:])
            return
        
        for i in range(start, len(nums)):
            if nums[i] > remaining:
                break
            
            path.append(nums[i])
            backtrack(i + 1, path, remaining - nums[i])
            path.pop()
    
    backtrack(0, [], target)
    return result


# Test cases
if __name__ == "__main__":
    # Test permutations
    nums = [1, 2, 3]
    print(f"Permutations of {nums}: {generate_permutations(nums)}")
    
    # Test combinations
    n, k = 4, 2
    print(f"Combinations of {k} from 1 to {n}: {generate_combinations(n, k)}")
    
    # Test combination sum
    candidates = [2, 3, 6, 7]
    target = 7
    print(f"Combinations that sum to {target}: {combination_sum(candidates, target)}")
    
    # Test N-Queens
    n = 4
    solutions = solve_n_queens(n)
    print(f"N-Queens solutions for n={n}: {len(solutions)} solutions")
    for i, solution in enumerate(solutions):
        print(f"Solution {i+1}:")
        for row in solution:
            print(row)
        print()
    
    # Test Sudoku
    board = [
        ["5","3",".",".","7",".",".",".","."],
        ["6",".",".","1","9","5",".",".","."],
        [".","9","8",".",".",".",".","6","."],
        ["8",".",".",".","6",".",".",".","3"],
        ["4",".",".","8",".","3",".",".","1"],
        ["7",".",".",".","2",".",".",".","6"],
        [".","6",".",".",".",".","2","8","."],
        [".",".",".","4","1","9",".",".","5"],
        [".",".",".",".","8",".",".","7","9"]
    ]
    print(f"Sudoku solvable: {solve_sudoku(board)}")
    
    # Test generate parentheses
    n = 3
    print(f"Valid parentheses for n={n}: {generate_parentheses(n)}")
    
    # Test palindrome partitioning
    s = "aab"
    print(f"Palindrome partitions of '{s}': {palindrome_partitioning(s)}")
    
    # Test subset sum
    nums = [1, 2, 3, 4, 5]
    target = 5
    print(f"Subsets that sum to {target}: {subset_sum(nums, target)}")

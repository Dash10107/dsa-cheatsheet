"""
DFS & BFS Pattern Template
=========================

This template provides common DFS and BFS implementations for various problem types.
"""

from collections import deque
from typing import List, Optional


class TreeNode:
    """Binary tree node definition."""
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def dfs_recursive(graph, node, visited):
    """
    DFS recursive template.
    
    Args:
        graph: Adjacency list representation
        node: Current node
        visited: Set of visited nodes
    """
    if node in visited:
        return
    
    visited.add(node)
    # Process node here
    
    for neighbor in graph[node]:
        dfs_recursive(graph, neighbor, visited)


def dfs_iterative(graph, start):
    """
    DFS iterative template using stack.
    
    Args:
        graph: Adjacency list representation
        start: Starting node
    
    Returns:
        Set of visited nodes
    """
    stack = [start]
    visited = set()
    
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            # Process node here
            
            for neighbor in graph[node]:
                if neighbor not in visited:
                    stack.append(neighbor)
    
    return visited


def bfs(graph, start):
    """
    BFS template using queue.
    
    Args:
        graph: Adjacency list representation
        start: Starting node
    
    Returns:
        Set of visited nodes
    """
    queue = deque([start])
    visited = set([start])
    
    while queue:
        node = queue.popleft()
        # Process node here
        
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                queue.append(neighbor)
    
    return visited


def bfs_level_order(root):
    """
    BFS level order traversal for binary tree.
    
    Args:
        root: Root of binary tree
    
    Returns:
        List of levels
    """
    if not root:
        return []
    
    result = []
    queue = deque([root])
    
    while queue:
        level_size = len(queue)
        level = []
        
        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(level)
    
    return result


def number_of_islands(grid):
    """
    Count number of islands using DFS.
    
    Args:
        grid: 2D grid with '1' (land) and '0' (water)
    
    Returns:
        Number of islands
    """
    if not grid or not grid[0]:
        return 0
    
    rows, cols = len(grid), len(grid[0])
    islands = 0
    
    def dfs(r, c):
        if (r < 0 or r >= rows or c < 0 or c >= cols or 
            grid[r][c] != '1'):
            return
        
        grid[r][c] = '0'  # Mark as visited
        
        # Visit all 4 directions
        dfs(r + 1, c)
        dfs(r - 1, c)
        dfs(r, c + 1)
        dfs(r, c - 1)
    
    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == '1':
                islands += 1
                dfs(r, c)
    
    return islands


def word_search(board, word):
    """
    Check if word exists in board using DFS.
    
    Args:
        board: 2D board of characters
        word: Word to search for
    
    Returns:
        True if word exists, False otherwise
    """
    if not board or not board[0]:
        return False
    
    rows, cols = len(board), len(board[0])
    
    def dfs(r, c, index):
        if index == len(word):
            return True
        
        if (r < 0 or r >= rows or c < 0 or c >= cols or 
            board[r][c] != word[index]):
            return False
        
        # Mark as visited
        temp = board[r][c]
        board[r][c] = '#'
        
        # Check all 4 directions
        found = (dfs(r + 1, c, index + 1) or
                dfs(r - 1, c, index + 1) or
                dfs(r, c + 1, index + 1) or
                dfs(r, c - 1, index + 1))
        
        # Restore
        board[r][c] = temp
        return found
    
    for r in range(rows):
        for c in range(cols):
            if dfs(r, c, 0):
                return True
    
    return False


def course_schedule(num_courses, prerequisites):
    """
    Check if all courses can be finished using DFS cycle detection.
    
    Args:
        num_courses: Number of courses
        prerequisites: List of prerequisite pairs
    
    Returns:
        True if all courses can be finished, False otherwise
    """
    # Build adjacency list
    graph = [[] for _ in range(num_courses)]
    for course, prereq in prerequisites:
        graph[prereq].append(course)
    
    # 0: unvisited, 1: visiting, 2: visited
    state = [0] * num_courses
    
    def has_cycle(course):
        if state[course] == 1:  # Currently visiting
            return True
        if state[course] == 2:  # Already visited
            return False
        
        state[course] = 1  # Mark as visiting
        
        for neighbor in graph[course]:
            if has_cycle(neighbor):
                return True
        
        state[course] = 2  # Mark as visited
        return False
    
    for course in range(num_courses):
        if has_cycle(course):
            return False
    
    return True


def binary_tree_zigzag_level_order(root):
    """
    Zigzag level order traversal using BFS.
    
    Args:
        root: Root of binary tree
    
    Returns:
        List of levels in zigzag order
    """
    if not root:
        return []
    
    result = []
    queue = deque([root])
    left_to_right = True
    
    while queue:
        level_size = len(queue)
        level = []
        
        for _ in range(level_size):
            node = queue.popleft()
            level.append(node.val)
            
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        if not left_to_right:
            level.reverse()
        
        result.append(level)
        left_to_right = not left_to_right
    
    return result


def minimum_depth_binary_tree(root):
    """
    Find minimum depth of binary tree using BFS.
    
    Args:
        root: Root of binary tree
    
    Returns:
        Minimum depth
    """
    if not root:
        return 0
    
    queue = deque([(root, 1)])
    
    while queue:
        node, depth = queue.popleft()
        
        # If leaf node, return depth
        if not node.left and not node.right:
            return depth
        
        if node.left:
            queue.append((node.left, depth + 1))
        if node.right:
            queue.append((node.right, depth + 1))
    
    return 0


# Test cases
if __name__ == "__main__":
    # Test DFS and BFS on graph
    graph = {
        0: [1, 2],
        1: [0, 3, 4],
        2: [0, 5],
        3: [1],
        4: [1],
        5: [2]
    }
    
    print("DFS Recursive:", end=" ")
    visited = set()
    dfs_recursive(graph, 0, visited)
    print(visited)
    
    print("DFS Iterative:", dfs_iterative(graph, 0))
    print("BFS:", bfs(graph, 0))
    
    # Test number of islands
    grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    print(f"Number of islands: {number_of_islands(grid)}")
    
    # Test word search
    board = [
        ["A","B","C","E"],
        ["S","F","C","S"],
        ["A","D","E","E"]
    ]
    word = "ABCCED"
    print(f"Word '{word}' exists: {word_search(board, word)}")
    
    # Test course schedule
    num_courses = 2
    prerequisites = [[1, 0]]
    print(f"Can finish all courses: {course_schedule(num_courses, prerequisites)}")
    
    # Test binary tree operations
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    
    print(f"Level order traversal: {bfs_level_order(root)}")
    print(f"Zigzag traversal: {binary_tree_zigzag_level_order(root)}")
    print(f"Minimum depth: {minimum_depth_binary_tree(root)}")

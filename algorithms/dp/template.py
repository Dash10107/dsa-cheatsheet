"""
Dynamic Programming Pattern Template
===================================

This template provides common DP implementations for various problem types.
"""

def fibonacci_dp(n):
    """
    Fibonacci using DP (bottom-up).
    
    Args:
        n: nth Fibonacci number
    
    Returns:
        nth Fibonacci number
    """
    if n <= 1:
        return n
    
    dp = [0] * (n + 1)
    dp[1] = 1
    
    for i in range(2, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    return dp[n]


def fibonacci_optimized(n):
    """
    Fibonacci with space optimization.
    
    Args:
        n: nth Fibonacci number
    
    Returns:
        nth Fibonacci number
    """
    if n <= 1:
        return n
    
    prev2, prev1 = 0, 1
    
    for i in range(2, n + 1):
        current = prev1 + prev2
        prev2 = prev1
        prev1 = current
    
    return prev1


def climbing_stairs(n):
    """
    Number of ways to climb n stairs (1 or 2 steps at a time).
    
    Args:
        n: Number of stairs
    
    Returns:
        Number of ways to climb
    """
    if n <= 2:
        return n
    
    dp = [0] * (n + 1)
    dp[1] = 1
    dp[2] = 2
    
    for i in range(3, n + 1):
        dp[i] = dp[i - 1] + dp[i - 2]
    
    return dp[n]


def house_robber(nums):
    """
    Maximum money that can be robbed from houses.
    
    Args:
        nums: Array of money in each house
    
    Returns:
        Maximum money that can be robbed
    """
    if not nums:
        return 0
    if len(nums) == 1:
        return nums[0]
    
    dp = [0] * len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    
    for i in range(2, len(nums)):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
    
    return dp[-1]


def coin_change(coins, amount):
    """
    Minimum number of coins to make amount.
    
    Args:
        coins: Array of coin denominations
        amount: Target amount
    
    Returns:
        Minimum number of coins, -1 if impossible
    """
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    for i in range(1, amount + 1):
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)
    
    return dp[amount] if dp[amount] != float('inf') else -1


def longest_increasing_subsequence(nums):
    """
    Length of longest increasing subsequence.
    
    Args:
        nums: Array of integers
    
    Returns:
        Length of LIS
    """
    if not nums:
        return 0
    
    dp = [1] * len(nums)
    
    for i in range(1, len(nums)):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    
    return max(dp)


def unique_paths(m, n):
    """
    Number of unique paths from top-left to bottom-right.
    
    Args:
        m: Number of rows
        n: Number of columns
    
    Returns:
        Number of unique paths
    """
    dp = [[1] * n for _ in range(m)]
    
    for i in range(1, m):
        for j in range(1, n):
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
    
    return dp[m - 1][n - 1]


def unique_paths_optimized(m, n):
    """
    Unique paths with space optimization.
    
    Args:
        m: Number of rows
        n: Number of columns
    
    Returns:
        Number of unique paths
    """
    dp = [1] * n
    
    for i in range(1, m):
        for j in range(1, n):
            dp[j] += dp[j - 1]
    
    return dp[n - 1]


def edit_distance(word1, word2):
    """
    Minimum edit distance between two strings.
    
    Args:
        word1: First string
        word2: Second string
    
    Returns:
        Minimum edit distance
    """
    m, n = len(word1), len(word2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Initialize base cases
    for i in range(m + 1):
        dp[i][0] = i
    for j in range(n + 1):
        dp[0][j] = j
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if word1[i - 1] == word2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1]
            else:
                dp[i][j] = 1 + min(
                    dp[i - 1][j],      # Delete
                    dp[i][j - 1],      # Insert
                    dp[i - 1][j - 1]   # Replace
                )
    
    return dp[m][n]


def longest_common_subsequence(text1, text2):
    """
    Length of longest common subsequence.
    
    Args:
        text1: First string
        text2: Second string
    
    Returns:
        Length of LCS
    """
    m, n = len(text1), len(text2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]
    
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if text1[i - 1] == text2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])
    
    return dp[m][n]


def knapsack_01(weights, values, capacity):
    """
    0/1 Knapsack problem.
    
    Args:
        weights: Array of item weights
        values: Array of item values
        capacity: Knapsack capacity
    
    Returns:
        Maximum value that can be obtained
    """
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        for w in range(capacity + 1):
            if weights[i - 1] <= w:
                dp[i][w] = max(
                    dp[i - 1][w],  # Don't take item
                    dp[i - 1][w - weights[i - 1]] + values[i - 1]  # Take item
                )
            else:
                dp[i][w] = dp[i - 1][w]
    
    return dp[n][capacity]


def word_break(s, word_dict):
    """
    Check if string can be segmented into dictionary words.
    
    Args:
        s: Input string
        word_dict: Set of valid words
    
    Returns:
        True if string can be segmented, False otherwise
    """
    n = len(s)
    dp = [False] * (n + 1)
    dp[0] = True
    
    for i in range(1, n + 1):
        for j in range(i):
            if dp[j] and s[j:i] in word_dict:
                dp[i] = True
                break
    
    return dp[n]


def max_subarray_sum(nums):
    """
    Maximum sum of contiguous subarray (Kadane's algorithm).
    
    Args:
        nums: Array of integers
    
    Returns:
        Maximum subarray sum
    """
    max_so_far = max_ending_here = nums[0]
    
    for i in range(1, len(nums)):
        max_ending_here = max(nums[i], max_ending_here + nums[i])
        max_so_far = max(max_so_far, max_ending_here)
    
    return max_so_far


# Test cases
if __name__ == "__main__":
    # Test Fibonacci
    print(f"Fibonacci(10): {fibonacci_dp(10)}")
    print(f"Fibonacci optimized(10): {fibonacci_optimized(10)}")
    
    # Test climbing stairs
    print(f"Ways to climb 5 stairs: {climbing_stairs(5)}")
    
    # Test house robber
    houses = [2, 7, 9, 3, 1]
    print(f"Maximum money from houses: {house_robber(houses)}")
    
    # Test coin change
    coins = [1, 3, 4]
    amount = 6
    print(f"Minimum coins for {amount}: {coin_change(coins, amount)}")
    
    # Test LIS
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    print(f"Longest increasing subsequence: {longest_increasing_subsequence(nums)}")
    
    # Test unique paths
    print(f"Unique paths (3x7): {unique_paths(3, 7)}")
    print(f"Unique paths optimized (3x7): {unique_paths_optimized(3, 7)}")
    
    # Test edit distance
    word1, word2 = "horse", "ros"
    print(f"Edit distance '{word1}' -> '{word2}': {edit_distance(word1, word2)}")
    
    # Test LCS
    text1, text2 = "abcde", "ace"
    print(f"LCS of '{text1}' and '{text2}': {longest_common_subsequence(text1, text2)}")
    
    # Test knapsack
    weights, values = [1, 3, 4, 5], [1, 4, 5, 7]
    capacity = 7
    print(f"Knapsack max value: {knapsack_01(weights, values, capacity)}")
    
    # Test word break
    s = "leetcode"
    word_dict = {"leet", "code"}
    print(f"Word break '{s}': {word_break(s, word_dict)}")
    
    # Test max subarray sum
    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
    print(f"Maximum subarray sum: {max_subarray_sum(nums)}")

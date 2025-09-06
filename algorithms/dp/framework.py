def dp_template(params):
    """
    Generic DP template with memoization
    
    This template follows the standard DP pattern:
    1. Pruning - Handle invalid/edge cases early
    2. Base case - Define stopping conditions
    3. Cache check - Return cached result if available
    4. Transition - Recursive calls with state changes
    5. Save & return - Cache and return the result
    """
    
    # Initialize memoization cache (can be dict, 2D array, etc.)
    memo = {}
    
    def dp(state_variables):
        """
        Inner DP function with memoization
        
        Args:
            state_variables: Parameters that define the current state
                           (e.g., index, remaining_sum, etc.)
        
        Returns:
            The optimal result for the current state
        """
        
        # 1. PRUNING - Handle invalid cases early
        # Check for invalid inputs or impossible states
        # if invalid_condition:
        #     return invalid_result  # e.g., float('inf'), -1, False
        
        # 2. BASE CASE - Define stopping conditions
        # Handle the simplest cases that don't need recursion
        # if base_condition:
        #     return base_result
        
        # 3. CACHE CHECK - Return cached result if available
        # Convert state to a hashable key for memoization
        # key = (state_variable1, state_variable2, ...)
        # if key in memo:
        #     return memo[key]
        
        # 4. TRANSITION - Make recursive calls with state changes
        # Explore all possible choices/transitions from current state
        # result = best_value  # Initialize with worst case
        # for choice in possible_choices:
        #     # Make recursive call with updated state
        #     subproblem_result = dp(updated_state_variables)
        #     # Update result based on problem type (min, max, count, etc.)
        #     result = update_result(result, subproblem_result)
        
        # 5. SAVE & RETURN - Cache the result and return
        # memo[key] = result
        # return result
        
        pass  # Remove this when implementing actual logic
    
    # Call the DP function with initial state
    # return dp(initial_state_variables)


# Example 1: Fibonacci (Simple DP)
def fibonacci(n):
    """Calculate nth Fibonacci number using DP template"""
    memo = {}
    
    def dp(i):
        # 1. PRUNING - Handle invalid cases
        if i < 0:
            return 0
        
        # 2. BASE CASE - Define stopping conditions
        if i == 0 or i == 1:
            return i
        
        # 3. CACHE CHECK - Return cached result if available
        if i in memo:
            return memo[i]
        
        # 4. TRANSITION - Make recursive calls
        result = dp(i - 1) + dp(i - 2)
        
        # 5. SAVE & RETURN - Cache and return
        memo[i] = result
        return result
    
    return dp(n)


# Example 2: Coin Change (Choice DP)
def coin_change(coins, amount):
    """Find minimum coins needed to make amount"""
    memo = {}
    
    def dp(remaining):
        # 1. PRUNING - Handle invalid cases
        if remaining < 0:
            return float('inf')  # Impossible
        
        # 2. BASE CASE - Define stopping conditions
        if remaining == 0:
            return 0  # No coins needed
        
        # 3. CACHE CHECK - Return cached result if available
        if remaining in memo:
            return memo[remaining]
        
        # 4. TRANSITION - Try each coin choice
        result = float('inf')
        for coin in coins:
            subproblem = dp(remaining - coin)
            if subproblem != float('inf'):
                result = min(result, 1 + subproblem)
        
        # 5. SAVE & RETURN - Cache and return
        memo[remaining] = result
        return result
    
    ans = dp(amount)
    return ans if ans != float('inf') else -1


# Example 3: 0/1 Knapsack (2D DP)
def knapsack_01(weights, values, capacity):
    """0/1 Knapsack using DP template"""
    n = len(weights)
    memo = {}
    
    def dp(i, remaining_capacity):
        # 1. PRUNING - Handle invalid cases
        if remaining_capacity < 0:
            return float('-inf')  # Invalid state
        
        # 2. BASE CASE - Define stopping conditions
        if i == n or remaining_capacity == 0:
            return 0
        
        # 3. CACHE CHECK - Return cached result if available
        key = (i, remaining_capacity)
        if key in memo:
            return memo[key]
        
        # 4. TRANSITION - Try both choices (take/skip)
        # Choice 1: Skip current item
        skip = dp(i + 1, remaining_capacity)
        
        # Choice 2: Take current item (if possible)
        take = 0
        if weights[i] <= remaining_capacity:
            take = values[i] + dp(i + 1, remaining_capacity - weights[i])
        
        result = max(skip, take)
        
        # 5. SAVE & RETURN - Cache and return
        memo[key] = result
        return result
    
    return dp(0, capacity)


# Quick Reference for Common DP Patterns:
"""
1. Linear DP: dp(i) depends on dp(i-1), dp(i-2), etc.
   - Fibonacci, House Robber, Climbing Stairs

2. Grid/2D DP: dp(i, j) depends on neighbors
   - Unique Paths, Minimum Path Sum

3. Interval DP: dp(i, j) for range [i, j]
   - Palindromic Substrings, Matrix Chain Multiplication

4. Knapsack DP: dp(i, w) for items and weight
   - 0/1 Knapsack, Coin Change, Target Sum

5. LIS DP: Longest Increasing Subsequence patterns
   - LIS, Russian Doll Envelopes

6. Substring/Subarray DP: dp(i, j) for substrings
   - Longest Common Subsequence, Edit Distance

7. Tree DP: Recurse on tree nodes
   - House Robber III, Binary Tree Maximum Path Sum

8. Bitmask DP: Use bits to represent states
   - Traveling Salesman, Assignment Problem

Common state variables:
- Index (i, j, k)
- Remaining capacity/sum/count
- Boolean flags (used/unused, ascending/descending)
- Previous choice/value
- Length/size constraints

Tips:
- Always handle edge cases in pruning
- Base cases should cover the simplest scenarios
- State variables should uniquely identify subproblems
- Choose the right data structure for memoization
- Consider bottom-up (iterative) conversion for optimization
"""
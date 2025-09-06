"""
Monotonic Stack Pattern Template
===============================

This template provides common monotonic stack implementations for various problem types.
"""

def next_greater_element(nums):
    """
    Find next greater element for each element in array.
    
    Args:
        nums: Array of integers
    
    Returns:
        Array where result[i] is next greater element of nums[i]
    """
    stack = []
    result = [-1] * len(nums)
    
    for i in range(len(nums)):
        while stack and nums[stack[-1]] < nums[i]:
            result[stack.pop()] = nums[i]
        stack.append(i)
    
    return result


def next_smaller_element(nums):
    """
    Find next smaller element for each element in array.
    
    Args:
        nums: Array of integers
    
    Returns:
        Array where result[i] is next smaller element of nums[i]
    """
    stack = []
    result = [-1] * len(nums)
    
    for i in range(len(nums)):
        while stack and nums[stack[-1]] > nums[i]:
            result[stack.pop()] = nums[i]
        stack.append(i)
    
    return result


def previous_greater_element(nums):
    """
    Find previous greater element for each element in array.
    
    Args:
        nums: Array of integers
    
    Returns:
        Array where result[i] is previous greater element of nums[i]
    """
    stack = []
    result = [-1] * len(nums)
    
    for i in range(len(nums)):
        while stack and nums[stack[-1]] <= nums[i]:
            stack.pop()
        if stack:
            result[i] = nums[stack[-1]]
        stack.append(i)
    
    return result


def daily_temperatures(temperatures):
    """
    Find number of days until warmer temperature.
    
    Args:
        temperatures: Array of daily temperatures
    
    Returns:
        Array where result[i] is days until warmer temperature
    """
    stack = []
    result = [0] * len(temperatures)
    
    for i in range(len(temperatures)):
        while stack and temperatures[stack[-1]] < temperatures[i]:
            prev_index = stack.pop()
            result[prev_index] = i - prev_index
        stack.append(i)
    
    return result


def largest_rectangle_histogram(heights):
    """
    Find largest rectangle area in histogram.
    
    Args:
        heights: Array of histogram heights
    
    Returns:
        Maximum rectangle area
    """
    stack = []
    max_area = 0
    
    for i in range(len(heights)):
        while stack and heights[stack[-1]] > heights[i]:
            height = heights[stack.pop()]
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, height * width)
        stack.append(i)
    
    # Process remaining elements in stack
    while stack:
        height = heights[stack.pop()]
        width = len(heights) if not stack else len(heights) - stack[-1] - 1
        max_area = max(max_area, height * width)
    
    return max_area


def trapping_rain_water_stack(height):
    """
    Calculate trapped rainwater using stack.
    
    Args:
        height: Array of heights
    
    Returns:
        Amount of trapped water
    """
    stack = []
    water = 0
    
    for i in range(len(height)):
        while stack and height[stack[-1]] < height[i]:
            bottom = stack.pop()
            if not stack:
                break
            
            width = i - stack[-1] - 1
            trapped_height = min(height[i], height[stack[-1]]) - height[bottom]
            water += width * trapped_height
        
        stack.append(i)
    
    return water


def stock_span(prices):
    """
    Calculate stock span for each day.
    
    Args:
        prices: Array of stock prices
    
    Returns:
        Array where result[i] is span for day i
    """
    stack = []
    span = [1] * len(prices)
    
    for i in range(len(prices)):
        while stack and prices[stack[-1]] <= prices[i]:
            stack.pop()
        
        span[i] = i - stack[-1] if stack else i + 1
        stack.append(i)
    
    return span


def sum_of_subarray_minimums(arr):
    """
    Calculate sum of minimum elements in all subarrays.
    
    Args:
        arr: Array of integers
    
    Returns:
        Sum of all subarray minimums
    """
    MOD = 10**9 + 7
    stack = []
    result = 0
    
    for i in range(len(arr) + 1):
        while stack and (i == len(arr) or arr[stack[-1]] > arr[i]):
            mid = stack.pop()
            left = stack[-1] if stack else -1
            right = i
            
            count = (mid - left) * (right - mid)
            result = (result + arr[mid] * count) % MOD
        
        stack.append(i)
    
    return result


def next_greater_element_circular(nums):
    """
    Find next greater element in circular array.
    
    Args:
        nums: Circular array of integers
    
    Returns:
        Array where result[i] is next greater element of nums[i]
    """
    n = len(nums)
    result = [-1] * n
    stack = []
    
    # Process array twice to handle circular nature
    for i in range(2 * n):
        while stack and nums[stack[-1]] < nums[i % n]:
            result[stack.pop()] = nums[i % n]
        stack.append(i % n)
    
    return result


# Test cases
if __name__ == "__main__":
    # Test next greater element
    nums = [2, 1, 2, 4, 3, 1]
    print(f"Next greater elements: {next_greater_element(nums)}")
    
    # Test next smaller element
    print(f"Next smaller elements: {next_smaller_element(nums)}")
    
    # Test previous greater element
    print(f"Previous greater elements: {previous_greater_element(nums)}")
    
    # Test daily temperatures
    temperatures = [73, 74, 75, 71, 69, 72, 76, 73]
    print(f"Days until warmer: {daily_temperatures(temperatures)}")
    
    # Test largest rectangle in histogram
    heights = [2, 1, 5, 6, 2, 3]
    print(f"Largest rectangle area: {largest_rectangle_histogram(heights)}")
    
    # Test trapping rain water
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    print(f"Trapped water: {trapping_rain_water_stack(height)}")
    
    # Test stock span
    prices = [100, 80, 60, 70, 60, 75, 85]
    print(f"Stock spans: {stock_span(prices)}")
    
    # Test sum of subarray minimums
    arr = [3, 1, 2, 4]
    print(f"Sum of subarray minimums: {sum_of_subarray_minimums(arr)}")
    
    # Test circular next greater element
    nums = [1, 2, 1]
    print(f"Circular next greater elements: {next_greater_element_circular(nums)}")

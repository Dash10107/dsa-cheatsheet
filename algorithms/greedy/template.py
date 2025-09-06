"""
Greedy Pattern Template
======================

This template provides common greedy algorithm implementations for various problem types.
"""

def activity_selection(activities):
    """
    Select maximum number of non-overlapping activities.
    
    Args:
        activities: List of (start_time, end_time) tuples
    
    Returns:
        List of selected activities
    """
    if not activities:
        return []
    
    # Sort by finish time
    activities.sort(key=lambda x: x[1])
    
    selected = [activities[0]]
    last_finish = activities[0][1]
    
    for start, finish in activities[1:]:
        if start >= last_finish:
            selected.append((start, finish))
            last_finish = finish
    
    return selected


def fractional_knapsack(items, capacity):
    """
    Fractional knapsack problem - can take fractions of items.
    
    Args:
        items: List of (weight, value) tuples
        capacity: Knapsack capacity
    
    Returns:
        Maximum value that can be obtained
    """
    # Sort by value/weight ratio in descending order
    items.sort(key=lambda x: x[1]/x[0], reverse=True)
    
    total_value = 0
    remaining_capacity = capacity
    
    for weight, value in items:
        if remaining_capacity >= weight:
            # Take the entire item
            total_value += value
            remaining_capacity -= weight
        else:
            # Take fraction of the item
            fraction = remaining_capacity / weight
            total_value += value * fraction
            break
    
    return total_value


def minimum_arrows_to_burst_balloons(points):
    """
    Minimum number of arrows to burst all balloons.
    
    Args:
        points: List of [start, end] balloon positions
    
    Returns:
        Minimum number of arrows needed
    """
    if not points:
        return 0
    
    # Sort by end position
    points.sort(key=lambda x: x[1])
    
    arrows = 1
    end = points[0][1]
    
    for start, finish in points[1:]:
        if start > end:
            arrows += 1
            end = finish
    
    return arrows


def jump_game(nums):
    """
    Check if can reach the last index.
    
    Args:
        nums: Array where nums[i] is max jump length at position i
    
    Returns:
        True if can reach last index, False otherwise
    """
    max_reach = 0
    
    for i in range(len(nums)):
        if i > max_reach:
            return False
        
        max_reach = max(max_reach, i + nums[i])
        
        if max_reach >= len(nums) - 1:
            return True
    
    return True


def jump_game_ii(nums):
    """
    Minimum number of jumps to reach the last index.
    
    Args:
        nums: Array where nums[i] is max jump length at position i
    
    Returns:
        Minimum number of jumps
    """
    if len(nums) <= 1:
        return 0
    
    jumps = 0
    current_end = 0
    farthest = 0
    
    for i in range(len(nums) - 1):
        farthest = max(farthest, i + nums[i])
        
        if i == current_end:
            jumps += 1
            current_end = farthest
            
            if current_end >= len(nums) - 1:
                break
    
    return jumps


def gas_station(gas, cost):
    """
    Find starting gas station to complete the circuit.
    
    Args:
        gas: Amount of gas at each station
        cost: Cost to travel from each station
    
    Returns:
        Starting station index, -1 if impossible
    """
    total_tank = 0
    current_tank = 0
    start_station = 0
    
    for i in range(len(gas)):
        total_tank += gas[i] - cost[i]
        current_tank += gas[i] - cost[i]
        
        if current_tank < 0:
            start_station = i + 1
            current_tank = 0
    
    return start_station if total_tank >= 0 else -1


def minimum_cost_to_connect_sticks(sticks):
    """
    Minimum cost to connect all sticks (always connect two smallest).
    
    Args:
        sticks: Array of stick lengths
    
    Returns:
        Minimum cost to connect all sticks
    """
    import heapq
    
    if len(sticks) <= 1:
        return 0
    
    # Convert to min heap
    heapq.heapify(sticks)
    total_cost = 0
    
    while len(sticks) > 1:
        # Connect two smallest sticks
        first = heapq.heappop(sticks)
        second = heapq.heappop(sticks)
        
        cost = first + second
        total_cost += cost
        
        # Add the new stick back to heap
        heapq.heappush(sticks, cost)
    
    return total_cost


def reorganize_string(s):
    """
    Reorganize string so no two adjacent characters are the same.
    
    Args:
        s: Input string
    
    Returns:
        Reorganized string, empty string if impossible
    """
    from collections import Counter
    import heapq
    
    # Count character frequencies
    char_count = Counter(s)
    
    # Create max heap (use negative values for max heap)
    heap = [(-count, char) for char, count in char_count.items()]
    heapq.heapify(heap)
    
    result = []
    prev_count, prev_char = 0, ''
    
    while heap:
        # Get most frequent character
        count, char = heapq.heappop(heap)
        
        # Add to result
        result.append(char)
        
        # Add previous character back if it has remaining count
        if prev_count < 0:
            heapq.heappush(heap, (prev_count, prev_char))
        
        # Update previous character
        prev_count, prev_char = count + 1, char
    
    # Check if reorganization is possible
    return ''.join(result) if len(result) == len(s) else ""


def partition_labels(s):
    """
    Partition string into as many parts as possible with unique characters.
    
    Args:
        s: Input string
    
    Returns:
        List of partition sizes
    """
    # Find last occurrence of each character
    last_occurrence = {}
    for i, char in enumerate(s):
        last_occurrence[char] = i
    
    result = []
    start = 0
    end = 0
    
    for i, char in enumerate(s):
        end = max(end, last_occurrence[char])
        
        if i == end:
            result.append(end - start + 1)
            start = i + 1
    
    return result


def minimum_platforms(arrival, departure):
    """
    Minimum number of platforms required for trains.
    
    Args:
        arrival: List of arrival times
        departure: List of departure times
    
    Returns:
        Minimum number of platforms needed
    """
    # Sort both arrays
    arrival.sort()
    departure.sort()
    
    platforms = 1
    max_platforms = 1
    i = 1  # arrival index
    j = 0  # departure index
    
    while i < len(arrival) and j < len(departure):
        if arrival[i] <= departure[j]:
            platforms += 1
            i += 1
        else:
            platforms -= 1
            j += 1
        
        max_platforms = max(max_platforms, platforms)
    
    return max_platforms


# Test cases
if __name__ == "__main__":
    # Test activity selection
    activities = [(1, 3), (2, 5), (0, 6), (5, 7), (8, 9), (5, 9)]
    print(f"Selected activities: {activity_selection(activities)}")
    
    # Test fractional knapsack
    items = [(10, 60), (20, 100), (30, 120)]
    capacity = 50
    print(f"Fractional knapsack max value: {fractional_knapsack(items, capacity)}")
    
    # Test minimum arrows
    points = [[10, 16], [2, 8], [1, 6], [7, 12]]
    print(f"Minimum arrows needed: {minimum_arrows_to_burst_balloons(points)}")
    
    # Test jump game
    nums = [2, 3, 1, 1, 4]
    print(f"Can reach end: {jump_game(nums)}")
    print(f"Minimum jumps: {jump_game_ii(nums)}")
    
    # Test gas station
    gas = [1, 2, 3, 4, 5]
    cost = [3, 4, 5, 1, 2]
    print(f"Starting gas station: {gas_station(gas, cost)}")
    
    # Test minimum cost to connect sticks
    sticks = [2, 4, 3]
    print(f"Minimum cost to connect sticks: {minimum_cost_to_connect_sticks(sticks)}")
    
    # Test reorganize string
    s = "aab"
    print(f"Reorganized string: '{reorganize_string(s)}'")
    
    # Test partition labels
    s = "ababcbacadefegdehijhklij"
    print(f"Partition sizes: {partition_labels(s)}")
    
    # Test minimum platforms
    arrival = [900, 940, 950, 1100, 1500, 1800]
    departure = [910, 1200, 1120, 1130, 1900, 2000]
    print(f"Minimum platforms needed: {minimum_platforms(arrival, departure)}")

class Array:
    def __init__(self, data=None):
        self.data = data or []
    
    def get(self, index):
        return self.data[index] if 0 <= index < len(self.data) else None
    
    def set(self, index, value):
        if 0 <= index < len(self.data):
            self.data[index] = value
    
    def append(self, value):
        self.data.append(value)
    
    def insert(self, index, value):
        self.data.insert(index, value)
    
    def remove(self, value):
        if value in self.data:
            self.data.remove(value)
    
    def pop(self, index=-1):
        return self.data.pop(index)
    
    def size(self):
        return len(self.data)
    
    def __str__(self):
        return str(self.data)

# Common array operations

def two_sum(nums, target):
    """Return indices of the two numbers such that they add up to target."""
    lookup = {}
    for i, num in enumerate(nums):
        if target - num in lookup:
            return [lookup[target - num], i]
        lookup[num] = i
    return []

def max_subarray(nums):
    """Find the contiguous subarray with the largest sum (Kadane's Algorithm)."""
    max_sum = float('-inf')
    curr_sum = 0
    for num in nums:
        curr_sum = max(num, curr_sum + num)
        max_sum = max(max_sum, curr_sum)
    return max_sum

def product_except_self(nums):
    """Return an array output such that output[i] is equal to the product of all the elements of nums except nums[i]."""
    n = len(nums)
    output = [1] * n
    left = 1
    for i in range(n):
        output[i] = left
        left *= nums[i]
    right = 1
    for i in range(n - 1, -1, -1):
        output[i] *= right
        right *= nums[i]
    return output

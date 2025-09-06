from collections import deque

class MonotonicQueue:
    def __init__(self):
        self.deque = deque()
    
    def push(self, val):
        while self.deque and self.deque[-1] < val:
            self.deque.pop()
        self.deque.append(val)
    
    def pop(self, val):
        if self.deque and self.deque[0] == val:
            self.deque.popleft()
    
    def max(self):
        return self.deque[0] if self.deque else None

class MonotonicDecreasingQueue:
    def __init__(self):
        self.deque = deque()
    
    def push(self, val):
        while self.deque and self.deque[-1] < val:
            self.deque.pop()
        self.deque.append(val)
    
    def pop(self, val):
        if self.deque and self.deque[0] == val:
            self.deque.popleft()
    
    def max(self):
        return self.deque[0] if self.deque else None

class MonotonicIncreasingQueue:
    def __init__(self):
        self.deque = deque()
    
    def push(self, val):
        while self.deque and self.deque[-1] > val:
            self.deque.pop()
        self.deque.append(val)
    
    def pop(self, val):
        if self.deque and self.deque[0] == val:
            self.deque.popleft()
    
    def min(self):
        return self.deque[0] if self.deque else None

# Common monotonic queue operations
def sliding_window_maximum(nums, k):
    pass

def first_unique_character(s):
    pass

def max_consecutive_ones_ii(nums):
    pass

def sliding_window_median(nums, k):
    pass

class Queue:
    def __init__(self):
        self.items = []
    
    def enqueue(self, item):
        self.items.append(item)
    
    def dequeue(self):
        if self.is_empty():
            return None
        return self.items.pop(0)
    
    def front(self):
        if self.is_empty():
            return None
        return self.items[0]
    
    def is_empty(self):
        return len(self.items) == 0
    
    def size(self):
        return len(self.items)
    
    def __str__(self):
        return str(self.items)

class MyQueue:
    def __init__(self):
        self.stack1 = []
        self.stack2 = []
    
    def push(self, x):
        self.stack1.append(x)
    
    def pop(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2.pop() if self.stack2 else None
    
    def peek(self):
        if not self.stack2:
            while self.stack1:
                self.stack2.append(self.stack1.pop())
        return self.stack2[-1] if self.stack2 else None
    
    def empty(self):
        return not self.stack1 and not self.stack2

# Common queue operations
def sliding_window_maximum(nums, k):
    """Find the max in each sliding window of size k (LeetCode 239)."""
    from collections import deque
    dq = deque()
    res = []
    for i, num in enumerate(nums):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and nums[dq[-1]] < num:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            res.append(nums[dq[0]])
    return res

def design_hit_counter():
    """Design a hit counter (LeetCode 362). Returns a class definition."""
    from collections import deque
    class HitCounter:
        def __init__(self):
            self.q = deque()
        def hit(self, timestamp):
            self.q.append(timestamp)
        def get_hits(self, timestamp):
            while self.q and self.q[0] <= timestamp - 300:
                self.q.popleft()
            return len(self.q)
    return HitCounter

def task_scheduler(tasks, n):
    """Find the least number of units of time to finish all tasks (LeetCode 621)."""
    from collections import Counter
    freq = Counter(tasks)
    max_freq = max(freq.values())
    max_count = sum(1 for v in freq.values() if v == max_freq)
    part_count = max_freq - 1
    part_length = n - (max_count - 1)
    empty_slots = part_count * part_length
    available_tasks = len(tasks) - max_freq * max_count
    idles = max(0, empty_slots - available_tasks)
    return len(tasks) + idles

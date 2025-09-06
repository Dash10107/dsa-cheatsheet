import heapq

class MinHeap:
    def __init__(self):
        self.heap = []
    
    def push(self, val):
        heapq.heappush(self.heap, val)
    
    def pop(self):
        return heapq.heappop(self.heap) if self.heap else None
    
    def peek(self):
        return self.heap[0] if self.heap else None
    
    def size(self):
        return len(self.heap)
    
    def is_empty(self):
        return len(self.heap) == 0

class MaxHeap:
    def __init__(self):
        self.heap = []
    
    def push(self, val):
        heapq.heappush(self.heap, -val)
    
    def pop(self):
        return -heapq.heappop(self.heap) if self.heap else None
    
    def peek(self):
        return -self.heap[0] if self.heap else None
    
    def size(self):
        return len(self.heap)
    
    def is_empty(self):
        return len(self.heap) == 0

class MedianFinder:
    def __init__(self):
        self.small = []  # max heap
        self.large = []  # min heap
    
    def add_num(self, num):
        if len(self.small) == len(self.large):
            heapq.heappush(self.large, -heapq.heappushpop(self.small, -num))
        else:
            heapq.heappush(self.small, -heapq.heappushpop(self.large, num))
    
    def find_median(self):
        if len(self.small) == len(self.large):
            return (-self.small[0] + self.large[0]) / 2
        else:
            return self.large[0]

# Common heap operations
def find_kth_largest(nums, k):
    pass

def merge_sorted_arrays(arrays):
    pass

def top_k_frequent(nums, k):
    pass

def kth_smallest_in_matrix(matrix, k):
    pass

def sliding_window_maximum(nums, k):
    pass

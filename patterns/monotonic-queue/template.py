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
    """
    Find the maximum in each sliding window of size k.
    """
    from collections import deque
    if not nums or k == 0:
        return []
    dq = deque()
    result = []
    for i, num in enumerate(nums):
        while dq and dq[0] <= i - k:
            dq.popleft()
        while dq and nums[dq[-1]] < num:
            dq.pop()
        dq.append(i)
        if i >= k - 1:
            result.append(nums[dq[0]])
    return result


def first_unique_character(s):
    """
    Return the index of the first non-repeating character in a string.
    """
    from collections import Counter
    count = Counter(s)
    for i, c in enumerate(s):
        if count[c] == 1:
            return i
    return -1


def max_consecutive_ones_ii(nums):
    """
    Find the maximum number of consecutive 1s in the array if you can flip at most one 0.
    """
    left = 0
    zeros = 0
    max_len = 0
    for right in range(len(nums)):
        if nums[right] == 0:
            zeros += 1
        while zeros > 1:
            if nums[left] == 0:
                zeros -= 1
            left += 1
        max_len = max(max_len, right - left + 1)
    return max_len


def sliding_window_median(nums, k):
    """
    Find the median in each sliding window of size k.
    """
    import bisect
    window = sorted(nums[:k])
    medians = []
    for i in range(k, len(nums) + 1):
        if k % 2 == 1:
            medians.append(window[k // 2])
        else:
            medians.append((window[k // 2 - 1] + window[k // 2]) / 2)
        if i == len(nums):
            break
        # Remove the element going out of the window
        out_elem = nums[i - k]
        idx = bisect.bisect_left(window, out_elem)
        window.pop(idx)
        # Insert the new element
        bisect.insort_left(window, nums[i])
    return medians

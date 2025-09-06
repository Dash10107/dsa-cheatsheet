class HashMap:
    def __init__(self, capacity=16):
        self.capacity = capacity
        self.size = 0
        self.buckets = [[] for _ in range(capacity)]
    
    def _hash(self, key):
        return hash(key) % self.capacity
    
    def put(self, key, value):
        bucket_index = self._hash(key)
        bucket = self.buckets[bucket_index]
        
        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (key, value)
                return
        
        bucket.append((key, value))
        self.size += 1
    
    def get(self, key):
        bucket_index = self._hash(key)
        bucket = self.buckets[bucket_index]
        
        for k, v in bucket:
            if k == key:
                return v
        return None
    
    def remove(self, key):
        bucket_index = self._hash(key)
        bucket = self.buckets[bucket_index]
        
        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i]
                self.size -= 1
                return v
        return None
    
    def contains(self, key):
        return self.get(key) is not None

# Common hashmap operations
def two_sum(nums, target):
    """Return indices of the two numbers such that they add up to target."""
    lookup = {}
    for i, num in enumerate(nums):
        if target - num in lookup:
            return [lookup[target - num], i]
        lookup[num] = i
    return []

def contains_duplicate(nums):
    """Check if any value appears at least twice in the array."""
    return len(set(nums)) < len(nums)

def group_anagrams(strs):
    """Group anagrams together."""
    from collections import defaultdict
    groups = defaultdict(list)
    for s in strs:
        key = tuple(sorted(s))
        groups[key].append(s)
    return list(groups.values())

def top_k_frequent(nums, k):
    """Return the k most frequent elements."""
    from collections import Counter
    return [item for item, _ in Counter(nums).most_common(k)]

def subarray_sum_equals_k(nums, k):
    """Count the number of subarrays whose sum equals k."""
    from collections import defaultdict
    count = 0
    curr_sum = 0
    prefix = defaultdict(int)
    prefix[0] = 1
    for num in nums:
        curr_sum += num
        count += prefix[curr_sum - k]
        prefix[curr_sum] += 1
    return count

def longest_consecutive(nums):
    """Find the length of the longest consecutive elements sequence."""
    num_set = set(nums)
    longest = 0
    for num in num_set:
        if num - 1 not in num_set:
            current = num
            streak = 1
            while current + 1 in num_set:
                current += 1
                streak += 1
            longest = max(longest, streak)
    return longest

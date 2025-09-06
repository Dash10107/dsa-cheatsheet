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
    pass

def contains_duplicate(nums):
    pass

def group_anagrams(strs):
    pass

def top_k_frequent(nums, k):
    pass

def subarray_sum_equals_k(nums, k):
    pass

def longest_consecutive(nums):
    pass

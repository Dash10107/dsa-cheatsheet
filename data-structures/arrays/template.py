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
    pass

def max_subarray(nums):
    pass

def product_except_self(nums):
    pass

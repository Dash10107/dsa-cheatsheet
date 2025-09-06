class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, val):
        self.root = self._insert(self.root, val)
    
    def _insert(self, root, val):
        if not root:
            return TreeNode(val)
        
        if val < root.val:
            root.left = self._insert(root.left, val)
        elif val > root.val:
            root.right = self._insert(root.right, val)
        
        return root
    
    def search(self, val):
        return self._search(self.root, val)
    
    def _search(self, root, val):
        if not root or root.val == val:
            return root
        
        if val < root.val:
            return self._search(root.left, val)
        return self._search(root.right, val)
    
    def delete(self, val):
        self.root = self._delete(self.root, val)
    
    def _delete(self, root, val):
        if not root:
            return root
        
        if val < root.val:
            root.left = self._delete(root.left, val)
        elif val > root.val:
            root.right = self._delete(root.right, val)
        else:
            if not root.left:
                return root.right
            elif not root.right:
                return root.left
            
            min_node = self._find_min(root.right)
            root.val = min_node.val
            root.right = self._delete(root.right, min_node.val)
        
        return root
    
    def _find_min(self, root):
        while root.left:
            root = root.left
        return root

# Common BST operations

def search_bst(root, val):
    """Search for a value in BST and return the node."""
    if not root or root.val == val:
        return root
    if val < root.val:
        return search_bst(root.left, val)
    return search_bst(root.right, val)

def insert_into_bst(root, val):
    """Insert a value into BST and return the root."""
    if not root:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_into_bst(root.left, val)
    else:
        root.right = insert_into_bst(root.right, val)
    return root

def validate_bst(root):
    """Validate if a binary tree is a BST."""
    def helper(node, low, high):
        if not node:
            return True
        if not (low < node.val < high):
            return False
        return helper(node.left, low, node.val) and helper(node.right, node.val, high)
    return helper(root, float('-inf'), float('inf'))

def lowest_common_ancestor(root, p, q):
    """Find the lowest common ancestor of two nodes in BST."""
    if not root:
        return None
    if p.val < root.val and q.val < root.val:
        return lowest_common_ancestor(root.left, p, q)
    if p.val > root.val and q.val > root.val:
        return lowest_common_ancestor(root.right, p, q)
    return root

def kth_smallest(root, k):
    """Find the kth smallest element in BST."""
    stack = []
    curr = root
    while True:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        k -= 1
        if k == 0:
            return curr.val
        curr = curr.right

def recover_bst(root):
    """Recover a BST where two nodes are swapped by mistake."""
    x = y = prev = None
    stack = []
    curr = root
    while stack or curr:
        while curr:
            stack.append(curr)
            curr = curr.left
        curr = stack.pop()
        if prev and curr.val < prev.val:
            y = curr
            if not x:
                x = prev
        prev = curr
        curr = curr.right
    if x and y:
        x.val, y.val = y.val, x.val

def sorted_array_to_bst(nums):
    """Convert sorted array to height-balanced BST."""
    if not nums:
        return None
    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left = sorted_array_to_bst(nums[:mid])
    root.right = sorted_array_to_bst(nums[mid+1:])
    return root

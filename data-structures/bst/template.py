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
    pass

def insert_into_bst(root, val):
    pass

def validate_bst(root):
    pass

def lowest_common_ancestor(root, p, q):
    pass

def kth_smallest(root, k):
    pass

def recover_bst(root):
    pass

def sorted_array_to_bst(nums):
    pass

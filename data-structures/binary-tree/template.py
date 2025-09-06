class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class BinaryTree:
    def __init__(self, root=None):
        self.root = root
    
    def insert(self, val):
        if not self.root:
            self.root = TreeNode(val)
            return
        
        queue = [self.root]
        while queue:
            node = queue.pop(0)
            if not node.left:
                node.left = TreeNode(val)
                return
            elif not node.right:
                node.right = TreeNode(val)
                return
            else:
                queue.append(node.left)
                queue.append(node.right)
    
    def inorder_traversal(self, root):
        result = []
        if root:
            result.extend(self.inorder_traversal(root.left))
            result.append(root.val)
            result.extend(self.inorder_traversal(root.right))
        return result
    
    def preorder_traversal(self, root):
        result = []
        if root:
            result.append(root.val)
            result.extend(self.preorder_traversal(root.left))
            result.extend(self.preorder_traversal(root.right))
        return result
    
    def postorder_traversal(self, root):
        result = []
        if root:
            result.extend(self.postorder_traversal(root.left))
            result.extend(self.postorder_traversal(root.right))
            result.append(root.val)
        return result

# Common binary tree operations
def max_depth(root):
    """Return the maximum depth of the binary tree."""
    if not root:
        return 0
    return 1 + max(max_depth(root.left), max_depth(root.right))

def is_symmetric(root):
    """Check if a tree is symmetric around its center."""
    def is_mirror(left, right):
        if not left and not right:
            return True
        if not left or not right:
            return False
        return left.val == right.val and is_mirror(left.left, right.right) and is_mirror(left.right, right.left)
    return is_mirror(root.left, root.right) if root else True

def level_order(root):
    """Return the level order traversal of a binary tree."""
    if not root:
        return []
    result = []
    queue = [root]
    while queue:
        level = []
        for _ in range(len(queue)):
            node = queue.pop(0)
            level.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        result.append(level)
    return result

def build_tree(preorder, inorder):
    """Build binary tree from preorder and inorder traversal lists."""
    if not preorder or not inorder:
        return None
    root_val = preorder[0]
    root = TreeNode(root_val)
    idx = inorder.index(root_val)
    root.left = build_tree(preorder[1:1+idx], inorder[:idx])
    root.right = build_tree(preorder[1+idx:], inorder[idx+1:])
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

def max_path_sum(root):
    """Find the maximum path sum in a binary tree."""
    max_sum = float('-inf')
    def helper(node):
        nonlocal max_sum
        if not node:
            return 0
        left = max(helper(node.left), 0)
        right = max(helper(node.right), 0)
        max_sum = max(max_sum, node.val + left + right)
        return node.val + max(left, right)
    helper(root)
    return max_sum

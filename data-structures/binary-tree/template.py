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
    pass

def is_symmetric(root):
    pass

def level_order(root):
    pass

def build_tree(preorder, inorder):
    pass

def validate_bst(root):
    pass

def max_path_sum(root):
    pass

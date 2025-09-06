import java.util.*;

public class Template {
    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        
        TreeNode(int x) {
            val = x;
        }
    }
    
    static class BST {
        private TreeNode root;
        
        public BST() {
            root = null;
        }
        
        public void insert(int val) {
            root = insertHelper(root, val);
        }
        
        private TreeNode insertHelper(TreeNode node, int val) {
            if (node == null) return new TreeNode(val);
            if (val < node.val) {
                node.left = insertHelper(node.left, val);
            } else if (val > node.val) {
                node.right = insertHelper(node.right, val);
            }
            return node;
        }
        
        public boolean search(int val) {
            return searchHelper(root, val);
        }
        
        private boolean searchHelper(TreeNode node, int val) {
            if (node == null) return false;
            if (val == node.val) return true;
            if (val < node.val) return searchHelper(node.left, val);
            return searchHelper(node.right, val);
        }
        
        public void deleteNode(int val) {
            root = deleteHelper(root, val);
        }
        
        private TreeNode deleteHelper(TreeNode node, int val) {
            if (node == null) return null;
            
            if (val < node.val) {
                node.left = deleteHelper(node.left, val);
            } else if (val > node.val) {
                node.right = deleteHelper(node.right, val);
            } else {
                if (node.left == null) return node.right;
                if (node.right == null) return node.left;
                
                TreeNode minNode = findMin(node.right);
                node.val = minNode.val;
                node.right = deleteHelper(node.right, minNode.val);
            }
            return node;
        }
        
        private TreeNode findMin(TreeNode node) {
            while (node.left != null) node = node.left;
            return node;
        }
        
        public List<Integer> inorderTraversal() {
            List<Integer> result = new ArrayList<>();
            inorderHelper(root, result);
            return result;
        }
        
        private void inorderHelper(TreeNode node, List<Integer> result) {
            if (node == null) return;
            inorderHelper(node.left, result);
            result.add(node.val);
            inorderHelper(node.right, result);
        }
        
        public boolean isValidBST() {
            return isValidHelper(root, Long.MIN_VALUE, Long.MAX_VALUE);
        }
        
        private boolean isValidHelper(TreeNode node, long min, long max) {
            if (node == null) return true;
            if (node.val <= min || node.val >= max) return false;
            return isValidHelper(node.left, min, node.val) && 
                   isValidHelper(node.right, node.val, max);
        }
        
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            if (root == null) return null;
            if (root.val > p.val && root.val > q.val) {
                return lowestCommonAncestor(root.left, p, q);
            }
            if (root.val < p.val && root.val < q.val) {
                return lowestCommonAncestor(root.right, p, q);
            }
            return root;
        }
        
        public int kthSmallest(int k) {
            Stack<TreeNode> stack = new Stack<>();
            TreeNode curr = root;
            int count = 0;
            
            while (curr != null || !stack.isEmpty()) {
                while (curr != null) {
                    stack.push(curr);
                    curr = curr.left;
                }
                curr = stack.pop();
                count++;
                if (count == k) return curr.val;
                curr = curr.right;
            }
            return -1;
        }
    }
    
    // Common BST operations
    public static TreeNode sortedArrayToBST(int[] nums) {
        // TODO: Implement sorted array to BST
        return null;
    }
    
    public static TreeNode searchBST(TreeNode root, int val) {
        // TODO: Implement BST search
        return null;
    }
    
    public static int rangeSumBST(TreeNode root, int low, int high) {
        // TODO: Implement range sum
        return 0;
    }
    
    public static void main(String[] args) {
        BST bst = new BST();
        bst.insert(5);
        bst.insert(3);
        bst.insert(7);
        bst.insert(1);
        bst.insert(9);
        
        System.out.println("Inorder traversal: " + bst.inorderTraversal());
        System.out.println("Search 7: " + (bst.search(7) ? "Found" : "Not found"));
        System.out.println("Is valid BST: " + bst.isValidBST());
        System.out.println("3rd smallest: " + bst.kthSmallest(3));
    }
}

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
    
    static class BinaryTree {
        private TreeNode root;
        
        public BinaryTree() {
            root = null;
        }
        
        public void insert(int val) {
            root = insertHelper(root, val);
        }
        
        private TreeNode insertHelper(TreeNode node, int val) {
            if (node == null) return new TreeNode(val);
            if (val < node.val) {
                node.left = insertHelper(node.left, val);
            } else {
                node.right = insertHelper(node.right, val);
            }
            return node;
        }
        
        // DFS Traversals
        public List<Integer> preorderTraversal() {
            List<Integer> result = new ArrayList<>();
            preorderHelper(root, result);
            return result;
        }
        
        private void preorderHelper(TreeNode node, List<Integer> result) {
            if (node == null) return;
            result.add(node.val);
            preorderHelper(node.left, result);
            preorderHelper(node.right, result);
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
        
        public List<Integer> postorderTraversal() {
            List<Integer> result = new ArrayList<>();
            postorderHelper(root, result);
            return result;
        }
        
        private void postorderHelper(TreeNode node, List<Integer> result) {
            if (node == null) return;
            postorderHelper(node.left, result);
            postorderHelper(node.right, result);
            result.add(node.val);
        }
        
        // BFS Traversal
        public List<List<Integer>> levelOrderTraversal() {
            List<List<Integer>> result = new ArrayList<>();
            if (root == null) return result;
            
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            
            while (!queue.isEmpty()) {
                int size = queue.size();
                List<Integer> level = new ArrayList<>();
                
                for (int i = 0; i < size; i++) {
                    TreeNode node = queue.poll();
                    level.add(node.val);
                    
                    if (node.left != null) queue.offer(node.left);
                    if (node.right != null) queue.offer(node.right);
                }
                result.add(level);
            }
            return result;
        }
        
        public int maxDepth() {
            return maxDepthHelper(root);
        }
        
        private int maxDepthHelper(TreeNode node) {
            if (node == null) return 0;
            return 1 + Math.max(maxDepthHelper(node.left), maxDepthHelper(node.right));
        }
        
        public boolean isBalanced() {
            return isBalancedHelper(root) != -1;
        }
        
        private int isBalancedHelper(TreeNode node) {
            if (node == null) return 0;
            
            int left = isBalancedHelper(node.left);
            if (left == -1) return -1;
            
            int right = isBalancedHelper(node.right);
            if (right == -1) return -1;
            
            if (Math.abs(left - right) > 1) return -1;
            return 1 + Math.max(left, right);
        }
    }
    
    // Common tree operations
    public static boolean isSameTree(TreeNode p, TreeNode q) {
    if (p == null && q == null) return true;
    if (p == null || q == null) return false;
    if (p.val != q.val) return false;
    return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
    
    public static boolean isSymmetric(TreeNode root) {
        if (root == null) return true;
        return isMirror(root.left, root.right);
    }
    private static boolean isMirror(TreeNode left, TreeNode right) {
        if (left == null && right == null) return true;
        if (left == null || right == null) return false;
        if (left.val != right.val) return false;
        return isMirror(left.left, right.right) && isMirror(left.right, right.left);
    }
    
    public static TreeNode invertTree(TreeNode root) {
    if (root == null) return null;
    TreeNode left = invertTree(root.left);
    TreeNode right = invertTree(root.right);
    root.left = right;
    root.right = left;
    return root;
    }
    
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.insert(5);
        tree.insert(3);
        tree.insert(7);
        tree.insert(1);
        tree.insert(9);
        
        System.out.println("Inorder: " + tree.inorderTraversal());
        System.out.println("Max depth: " + tree.maxDepth());
        System.out.println("Is balanced: " + tree.isBalanced());
    }
}

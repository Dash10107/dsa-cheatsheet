import java.util.*;

public class Template {
    static class Graph {
        private int vertices;
        private List<List<Integer>> adjList;
        
        public Graph(int v) {
            vertices = v;
            adjList = new ArrayList<>();
            for (int i = 0; i < v; i++) {
                adjList.add(new ArrayList<>());
            }
        }
        
        public void addEdge(int u, int v) {
            adjList.get(u).add(v);
            adjList.get(v).add(u); // For undirected graph
        }
        
        // DFS using recursion
        public void dfsRecursive(int start, boolean[] visited) {
            visited[start] = true;
            System.out.print(start + " ");
            
            for (int neighbor : adjList.get(start)) {
                if (!visited[neighbor]) {
                    dfsRecursive(neighbor, visited);
                }
            }
        }
        
        // DFS using stack
        public void dfsIterative(int start) {
            boolean[] visited = new boolean[vertices];
            Stack<Integer> stack = new Stack<>();
            stack.push(start);
            
            while (!stack.isEmpty()) {
                int current = stack.pop();
                
                if (!visited[current]) {
                    visited[current] = true;
                    System.out.print(current + " ");
                    
                    for (int neighbor : adjList.get(current)) {
                        if (!visited[neighbor]) {
                            stack.push(neighbor);
                        }
                    }
                }
            }
        }
        
        // BFS using queue
        public void bfs(int start) {
            boolean[] visited = new boolean[vertices];
            Queue<Integer> queue = new LinkedList<>();
            queue.offer(start);
            visited[start] = true;
            
            while (!queue.isEmpty()) {
                int current = queue.poll();
                System.out.print(current + " ");
                
                for (int neighbor : adjList.get(current)) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        queue.offer(neighbor);
                    }
                }
            }
        }
        
        // Check if graph is connected
        public boolean isConnected() {
            boolean[] visited = new boolean[vertices];
            dfsRecursive(0, visited);
            
            for (boolean v : visited) {
                if (!v) return false;
            }
            return true;
        }
        
        // Count connected components
        public int countConnectedComponents() {
            boolean[] visited = new boolean[vertices];
            int components = 0;
            
            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    dfsRecursive(i, visited);
                    components++;
                }
            }
            return components;
        }
    }
    
    static class TreeNode {
        int val;
        List<TreeNode> children;
        
        TreeNode(int x) {
            val = x;
            children = new ArrayList<>();
        }
    }
    
    static class TreeTraversal {
        // DFS Traversals for binary tree
        public static List<Integer> preorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            if (root == null) return result;
            
            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);
            
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                result.add(node.val);
                
                // Push children in reverse order
                for (int i = node.children.size() - 1; i >= 0; i--) {
                    stack.push(node.children.get(i));
                }
            }
            return result;
        }
        
        public static List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            Stack<TreeNode> stack = new Stack<>();
            TreeNode current = root;
            
            while (current != null || !stack.isEmpty()) {
                while (current != null) {
                    stack.push(current);
                    current = current.children.isEmpty() ? null : current.children.get(0);
                }
                current = stack.pop();
                result.add(current.val);
                current = current.children.size() > 1 ? current.children.get(1) : null;
            }
            return result;
        }
        
        public static List<Integer> postorderTraversal(TreeNode root) {
            List<Integer> result = new ArrayList<>();
            if (root == null) return result;
            
            Stack<TreeNode> stack = new Stack<>();
            stack.push(root);
            
            while (!stack.isEmpty()) {
                TreeNode node = stack.pop();
                result.add(0, node.val); // Add to beginning
                
                for (TreeNode child : node.children) {
                    stack.push(child);
                }
            }
            return result;
        }
        
        // Level order traversal (BFS)
        public static List<List<Integer>> levelOrder(TreeNode root) {
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
                    
                    for (TreeNode child : node.children) {
                        queue.offer(child);
                    }
                }
                result.add(level);
            }
            return result;
        }
        
        // Tree height/depth
        public static int maxDepth(TreeNode root) {
            if (root == null) return 0;
            
            int maxChildDepth = 0;
            for (TreeNode child : root.children) {
                maxChildDepth = Math.max(maxChildDepth, maxDepth(child));
            }
            return 1 + maxChildDepth;
        }
        
        // Check if tree is balanced
        public static boolean isBalanced(TreeNode root) {
            return checkHeight(root) != -1;
        }
        
        private static int checkHeight(TreeNode root) {
            if (root == null) return 0;
            
            int leftHeight = root.children.isEmpty() ? 0 : checkHeight(root.children.get(0));
            if (leftHeight == -1) return -1;
            
            int rightHeight = root.children.size() > 1 ? checkHeight(root.children.get(1)) : 0;
            if (rightHeight == -1) return -1;
            
            if (Math.abs(leftHeight - rightHeight) > 1) return -1;
            return 1 + Math.max(leftHeight, rightHeight);
        }
    }
    
    // Common DFS/BFS problems
    public static boolean hasPath(int[][] graph, int start, int end) {
        // TODO: Implement path finding
        return false;
    }
    
    public static List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        // TODO: Implement all paths from source to target
        return new ArrayList<>();
    }
    
    public static int shortestPathBinaryMatrix(int[][] grid) {
        // TODO: Implement shortest path in binary matrix
        return -1;
    }
    
    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        // TODO: Implement course schedule
        return false;
    }
    
    public static int[] findOrder(int numCourses, int[][] prerequisites) {
        // TODO: Implement course schedule II
        return new int[0];
    }
    
    public static void main(String[] args) {
        // Test graph operations
        Graph g = new Graph(6);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(2, 4);
        g.addEdge(3, 5);
        
        System.out.print("DFS (recursive): ");
        boolean[] visited = new boolean[6];
        g.dfsRecursive(0, visited);
        System.out.println();
        
        System.out.print("DFS (iterative): ");
        g.dfsIterative(0);
        System.out.println();
        
        System.out.print("BFS: ");
        g.bfs(0);
        System.out.println();
        
        System.out.println("Connected components: " + g.countConnectedComponents());
        
        // Test tree operations
        TreeNode root = new TreeNode(1);
        root.children.add(new TreeNode(2));
        root.children.add(new TreeNode(3));
        root.children.get(0).children.add(new TreeNode(4));
        root.children.get(0).children.add(new TreeNode(5));
        
        System.out.println("Tree height: " + TreeTraversal.maxDepth(root));
        System.out.println("Is balanced: " + TreeTraversal.isBalanced(root));
    }
}

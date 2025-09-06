import java.util.*;

public class Template {
    static class DisjointSet {
        private int[] parent;
        private int[] rank;
        private int components;
        
        public DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];
            components = n;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        public int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }
        
        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            
            if (rootX == rootY) return;
            
            // Union by rank
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            components--;
        }
        
        public boolean connected(int x, int y) {
            return find(x) == find(y);
        }
        
        public int getComponents() {
            return components;
        }
        
        public int getSize(int x) {
            int root = find(x);
            int size = 0;
            for (int i = 0; i < parent.length; i++) {
                if (find(i) == root) size++;
            }
            return size;
        }
    }
    
    // Common disjoint set operations
    public static int countComponents(int n, int[][] edges) {
        // TODO: Implement component counting
        return 0;
    }
    
    public static boolean validTree(int n, int[][] edges) {
        // TODO: Implement valid tree check
        return false;
    }
    
    public static int findCircleNum(int[][] isConnected) {
        // TODO: Implement number of provinces
        return 0;
    }
    
    public static void main(String[] args) {
        DisjointSet ds = new DisjointSet(5);
        
        ds.union(0, 1);
        ds.union(2, 3);
        ds.union(1, 4);
        
        System.out.println("Components: " + ds.getComponents());
        System.out.println("0 and 4 connected: " + ds.connected(0, 4));
        System.out.println("0 and 2 connected: " + ds.connected(0, 2));
    }
}

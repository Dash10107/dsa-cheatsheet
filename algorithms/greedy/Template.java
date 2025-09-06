import java.util.*;

public class Template {
    // Activity selection problem
    public static int activitySelection(int[][] activities) {
        if (activities.length == 0) return 0;
        
        // Sort by finish time
        Arrays.sort(activities, (a, b) -> Integer.compare(a[1], b[1]));
        
        int count = 1;
        int lastFinish = activities[0][1];
        
        for (int i = 1; i < activities.length; i++) {
            if (activities[i][0] >= lastFinish) {
                count++;
                lastFinish = activities[i][1];
            }
        }
        return count;
    }
    
    // Fractional knapsack
    public static double fractionalKnapsack(int[] weights, int[] values, int capacity) {
        int n = weights.length;
        double[][] items = new double[n][3];
        
        for (int i = 0; i < n; i++) {
            items[i][0] = weights[i];
            items[i][1] = values[i];
            items[i][2] = (double) values[i] / weights[i];
        }
        
        Arrays.sort(items, (a, b) -> Double.compare(b[2], a[2]));
        
        double totalValue = 0;
        int remainingCapacity = capacity;
        
        for (double[] item : items) {
            if (item[0] <= remainingCapacity) {
                totalValue += item[1];
                remainingCapacity -= item[0];
            } else {
                totalValue += item[1] * remainingCapacity / item[0];
                break;
            }
        }
        return totalValue;
    }
    
    // Minimum number of coins
    public static int minCoins(int[] coins, int amount) {
        Arrays.sort(coins);
        int count = 0;
        
        for (int i = coins.length - 1; i >= 0; i--) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                count++;
            }
        }
        return amount == 0 ? count : -1;
    }
    
    // Huffman coding
    static class HuffmanNode {
        char data;
        int freq;
        HuffmanNode left, right;
        
        HuffmanNode(char d, int f) {
            data = d;
            freq = f;
            left = right = null;
        }
    }
    
    public static HuffmanNode buildHuffmanTree(char[] chars, int[] freqs) {
        PriorityQueue<HuffmanNode> pq = new PriorityQueue<>((a, b) -> Integer.compare(a.freq, b.freq));
        
        for (int i = 0; i < chars.length; i++) {
            pq.offer(new HuffmanNode(chars[i], freqs[i]));
        }
        
        while (pq.size() > 1) {
            HuffmanNode left = pq.poll();
            HuffmanNode right = pq.poll();
            
            HuffmanNode merged = new HuffmanNode('$', left.freq + right.freq);
            merged.left = left;
            merged.right = right;
            
            pq.offer(merged);
        }
        return pq.poll();
    }
    
    // Minimum spanning tree (Kruskal's algorithm)
    static class Edge {
        int src, dest, weight;
        
        Edge(int s, int d, int w) {
            src = s;
            dest = d;
            weight = w;
        }
    }
    
    static class UnionFind {
        int[] parent, rank;
        
        UnionFind(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        void union(int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if (px == py) return;
            
            if (rank[px] < rank[py]) {
                parent[px] = py;
            } else if (rank[px] > rank[py]) {
                parent[py] = px;
            } else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
    
    public static int kruskalMST(Edge[] edges, int vertices) {
        Arrays.sort(edges, (a, b) -> Integer.compare(a.weight, b.weight));
        
        UnionFind uf = new UnionFind(vertices);
        int mstWeight = 0;
        int edgeCount = 0;
        
        for (Edge edge : edges) {
            if (edgeCount == vertices - 1) break;
            
            int srcParent = uf.find(edge.src);
            int destParent = uf.find(edge.dest);
            
            if (srcParent != destParent) {
                mstWeight += edge.weight;
                uf.union(srcParent, destParent);
                edgeCount++;
            }
        }
        return mstWeight;
    }
    
    // Job sequencing with deadlines
    static class Job {
        int id, deadline, profit;
        
        Job(int i, int d, int p) {
            id = i;
            deadline = d;
            profit = p;
        }
    }
    
    public static int[] jobSequencing(Job[] jobs) {
        Arrays.sort(jobs, (a, b) -> Integer.compare(b.profit, a.profit));
        
        int maxDeadline = 0;
        for (Job job : jobs) {
            maxDeadline = Math.max(maxDeadline, job.deadline);
        }
        
        int[] result = new int[maxDeadline + 1];
        Arrays.fill(result, -1);
        int totalProfit = 0;
        int jobCount = 0;
        
        for (Job job : jobs) {
            for (int j = job.deadline; j > 0; j--) {
                if (result[j] == -1) {
                    result[j] = job.id;
                    totalProfit += job.profit;
                    jobCount++;
                    break;
                }
            }
        }
        
        return new int[]{jobCount, totalProfit};
    }
    
    // Gas station problem
    public static int canCompleteCircuit(int[] gas, int[] cost) {
        int totalTank = 0, currentTank = 0, startStation = 0;
        
        for (int i = 0; i < gas.length; i++) {
            totalTank += gas[i] - cost[i];
            currentTank += gas[i] - cost[i];
            
            if (currentTank < 0) {
                startStation = i + 1;
                currentTank = 0;
            }
        }
        return totalTank >= 0 ? startStation : -1;
    }
    
    // Maximum product of three numbers
    public static int maximumProduct(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;
        
        return Math.max(nums[0] * nums[1] * nums[n - 1],
                       nums[n - 3] * nums[n - 2] * nums[n - 1]);
    }
    
    // Lemonade change
    public static boolean lemonadeChange(int[] bills) {
        int five = 0, ten = 0;
        
        for (int bill : bills) {
            if (bill == 5) {
                five++;
            } else if (bill == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else { // bill == 20
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
    
    // Common greedy problems
    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));
        int count = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= end) {
                count++;
                end = intervals[i][1];
            }
        }
        return intervals.length - count;
    }

    public static int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int i = 0, j = 0;
        while (i < g.length && j < s.length) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
    
    public static void main(String[] args) {
        // Test activity selection
        int[][] activities = {{1, 3}, {2, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
        System.out.println("Max activities: " + activitySelection(activities));
        
        // Test fractional knapsack
        int[] weights = {10, 20, 30};
        int[] values = {60, 100, 120};
        int capacity = 50;
        System.out.println("Max value: " + fractionalKnapsack(weights, values, capacity));
        
        // Test job sequencing
        Job[] jobs = {new Job(1, 2, 100), new Job(2, 1, 19), new Job(3, 2, 27), 
                     new Job(4, 1, 25), new Job(5, 3, 15)};
        int[] result = jobSequencing(jobs);
        System.out.println("Jobs scheduled: " + result[0] + ", Profit: " + result[1]);
        
        // Test gas station
        int[] gas = {1, 2, 3, 4, 5};
        int[] cost = {3, 4, 5, 1, 2};
        System.out.println("Start station: " + canCompleteCircuit(gas, cost));
    }
}

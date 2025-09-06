#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Greedy {
public:
    // Activity selection problem
    int activitySelection(vector<pair<int, int>>& activities) {
        if (activities.empty()) return 0;
        
        // Sort by finish time
        sort(activities.begin(), activities.end(), 
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        
        int count = 1;
        int lastFinish = activities[0].second;
        
        for (int i = 1; i < activities.size(); i++) {
            if (activities[i].first >= lastFinish) {
                count++;
                lastFinish = activities[i].second;
            }
        }
        return count;
    }
    
    // Fractional knapsack
    double fractionalKnapsack(vector<int>& weights, vector<int>& values, int capacity) {
        vector<pair<double, int>> valuePerWeight;
        
        for (int i = 0; i < weights.size(); i++) {
            valuePerWeight.push_back({(double)values[i] / weights[i], i});
        }
        
        sort(valuePerWeight.rbegin(), valuePerWeight.rend());
        
        double totalValue = 0;
        int remainingCapacity = capacity;
        
        for (auto& item : valuePerWeight) {
            int index = item.second;
            if (weights[index] <= remainingCapacity) {
                totalValue += values[index];
                remainingCapacity -= weights[index];
            } else {
                totalValue += (double)values[index] * remainingCapacity / weights[index];
                break;
            }
        }
        return totalValue;
    }
    
    // Minimum number of coins
    int minCoins(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int count = 0;
        
        for (int coin : coins) {
            while (amount >= coin) {
                amount -= coin;
                count++;
            }
        }
        return amount == 0 ? count : -1;
    }
    
    // Huffman coding
    struct HuffmanNode {
        char data;
        int freq;
        HuffmanNode* left;
        HuffmanNode* right;
        
        HuffmanNode(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
    };
    
    struct Compare {
        bool operator()(HuffmanNode* a, HuffmanNode* b) {
            return a->freq > b->freq;
        }
    };
    
    HuffmanNode* buildHuffmanTree(vector<char>& chars, vector<int>& freqs) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
        
        for (int i = 0; i < chars.size(); i++) {
            pq.push(new HuffmanNode(chars[i], freqs[i]));
        }
        
        while (pq.size() > 1) {
            HuffmanNode* left = pq.top(); pq.pop();
            HuffmanNode* right = pq.top(); pq.pop();
            
            HuffmanNode* merged = new HuffmanNode('$', left->freq + right->freq);
            merged->left = left;
            merged->right = right;
            
            pq.push(merged);
        }
        return pq.top();
    }
    
    // Minimum spanning tree (Kruskal's algorithm)
    struct Edge {
        int src, dest, weight;
        Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
    };
    
    int findParent(vector<int>& parent, int i) {
        if (parent[i] == i) return i;
        return parent[i] = findParent(parent, parent[i]);
    }
    
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int px = findParent(parent, x);
        int py = findParent(parent, y);
        
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
    }
    
    int kruskalMST(vector<Edge>& edges, int vertices) {
        sort(edges.begin(), edges.end(), 
             [](const Edge& a, const Edge& b) { return a.weight < b.weight; });
        
        vector<int> parent(vertices);
        vector<int> rank(vertices, 0);
        for (int i = 0; i < vertices; i++) parent[i] = i;
        
        int mstWeight = 0;
        int edgeCount = 0;
        
        for (Edge& edge : edges) {
            if (edgeCount == vertices - 1) break;
            
            int srcParent = findParent(parent, edge.src);
            int destParent = findParent(parent, edge.dest);
            
            if (srcParent != destParent) {
                mstWeight += edge.weight;
                unionSets(parent, rank, srcParent, destParent);
                edgeCount++;
            }
        }
        return mstWeight;
    }
    
    // Job sequencing with deadlines
    struct Job {
        int id, deadline, profit;
        Job(int i, int d, int p) : id(i), deadline(d), profit(p) {}
    };
    
    vector<int> jobSequencing(vector<Job>& jobs) {
        sort(jobs.begin(), jobs.end(), 
             [](const Job& a, const Job& b) { return a.profit > b.profit; });
        
        int maxDeadline = 0;
        for (Job& job : jobs) {
            maxDeadline = max(maxDeadline, job.deadline);
        }
        
        vector<int> result(maxDeadline + 1, -1);
        int totalProfit = 0;
        int jobCount = 0;
        
        for (Job& job : jobs) {
            for (int j = job.deadline; j > 0; j--) {
                if (result[j] == -1) {
                    result[j] = job.id;
                    totalProfit += job.profit;
                    jobCount++;
                    break;
                }
            }
        }
        
        return {jobCount, totalProfit};
    }
    
    // Gas station problem
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalTank = 0, currentTank = 0, startStation = 0;
        
        for (int i = 0; i < gas.size(); i++) {
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
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        return max(nums[0] * nums[1] * nums[n - 1],
                   nums[n - 3] * nums[n - 2] * nums[n - 1]);
    }
    
    // Lemonade change
    bool lemonadeChange(vector<int>& bills) {
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
};

// Common greedy problems
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // TODO: Implement erase overlapping intervals
    return 0;
}

int findContentChildren(vector<int>& g, vector<int>& s) {
    // TODO: Implement assign cookies
    return 0;
}

int main() {
    Greedy g;
    
    // Test activity selection
    vector<pair<int, int>> activities = {{1, 3}, {2, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    cout << "Max activities: " << g.activitySelection(activities) << endl;
    
    // Test fractional knapsack
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int capacity = 50;
    cout << "Max value: " << g.fractionalKnapsack(weights, values, capacity) << endl;
    
    // Test job sequencing
    vector<Greedy::Job> jobs = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    vector<int> result = g.jobSequencing(jobs);
    cout << "Jobs scheduled: " << result[0] << ", Profit: " << result[1] << endl;
    
    // Test gas station
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    cout << "Start station: " << g.canCompleteCircuit(gas, cost) << endl;
    
    return 0;
}

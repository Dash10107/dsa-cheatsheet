#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int components;
    
public:
    DisjointSet(int n) : parent(n), rank(n, 0), components(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void unionSets(int x, int y) {
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
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    
    int getComponents() {
        return components;
    }
    
    int getSize(int x) {
        int root = find(x);
        int size = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (find(i) == root) size++;
        }
        return size;
    }
};

// Common disjoint set operations
int countComponents(int n, vector<vector<int>>& edges) {
    // TODO: Implement component counting
    return 0;
}

bool validTree(int n, vector<vector<int>>& edges) {
    // TODO: Implement valid tree check
    return false;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    // TODO: Implement number of provinces
    return 0;
}

int main() {
    DisjointSet ds(5);
    
    ds.unionSets(0, 1);
    ds.unionSets(2, 3);
    ds.unionSets(1, 4);
    
    cout << "Components: " << ds.getComponents() << endl;
    cout << "0 and 4 connected: " << (ds.connected(0, 4) ? "Yes" : "No") << endl;
    cout << "0 and 2 connected: " << (ds.connected(0, 2) ? "Yes" : "No") << endl;
    
    return 0;
}

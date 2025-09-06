#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int x) : val(x) {}
};

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    
public:
    Graph(int v) : vertices(v) {
        adjList.resize(v);
    }
    
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }
    
    // DFS using recursion
    void dfsRecursive(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";
        
        for (int neighbor : adjList[start]) {
            if (!visited[neighbor]) {
                dfsRecursive(neighbor, visited);
            }
        }
    }
    
    // DFS using stack
    void dfsIterative(int start) {
        vector<bool> visited(vertices, false);
        stack<int> st;
        st.push(start);
        
        while (!st.empty()) {
            int current = st.top();
            st.pop();
            
            if (!visited[current]) {
                visited[current] = true;
                cout << current << " ";
                
                for (int neighbor : adjList[current]) {
                    if (!visited[neighbor]) {
                        st.push(neighbor);
                    }
                }
            }
        }
    }
    
    // BFS using queue
    void bfs(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            
            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
    
    // Check if graph is connected
    bool isConnected() {
        vector<bool> visited(vertices, false);
        dfsRecursive(0, visited);
        
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }
    
    // Count connected components
    int countConnectedComponents() {
        vector<bool> visited(vertices, false);
        int components = 0;
        
        for (int i = 0; i < vertices; i++) {
            if (!visited[i]) {
                dfsRecursive(i, visited);
                components++;
            }
        }
        return components;
    }
};

class TreeTraversal {
public:
    // DFS Traversals for binary tree
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.push_back(node->val);
            
            // Push right child first, then left
            if (node->children.size() > 1) {
                if (node->children[1]) st.push(node->children[1]);
            }
            if (node->children.size() > 0) {
                if (node->children[0]) st.push(node->children[0]);
            }
        }
        return result;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->children.empty() ? nullptr : current->children[0];
            }
            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->children.size() > 1 ? current->children[1] : nullptr;
        }
        return result;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            result.insert(result.begin(), node->val);
            
            for (TreeNode* child : node->children) {
                if (child) st.push(child);
            }
        }
        return result;
    }
    
    // Level order traversal (BFS)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                
                for (TreeNode* child : node->children) {
                    if (child) q.push(child);
                }
            }
            result.push_back(level);
        }
        return result;
    }
    
    // Tree height/depth
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        
        int maxChildDepth = 0;
        for (TreeNode* child : root->children) {
            maxChildDepth = max(maxChildDepth, maxDepth(child));
        }
        return 1 + maxChildDepth;
    }
    
    // Check if tree is balanced
    bool isBalanced(TreeNode* root) {
        return checkHeight(root) != -1;
    }
    
    int checkHeight(TreeNode* root) {
        if (!root) return 0;
        
        int leftHeight = checkHeight(root->children.empty() ? nullptr : root->children[0]);
        if (leftHeight == -1) return -1;
        
        int rightHeight = checkHeight(root->children.size() > 1 ? root->children[1] : nullptr);
        if (rightHeight == -1) return -1;
        
        if (abs(leftHeight - rightHeight) > 1) return -1;
        return 1 + max(leftHeight, rightHeight);
    }
};

// Common DFS/BFS problems
bool hasPath(vector<vector<int>>& graph, int start, int end) {
    vector<bool> visited(graph.size(), false);
    return dfsPath(graph, start, end, visited);
}

bool dfsPath(vector<vector<int>>& graph, int current, int end, vector<bool>& visited) {
    if (current == end) return true;
    visited[current] = true;
    for (int neighbor : graph[current]) {
        if (!visited[neighbor] && dfsPath(graph, neighbor, end, visited)) return true;
    }
    return false;
}

void dfsAllPaths(vector<vector<int>>& graph, int node, int target, vector<int>& path, vector<vector<int>>& result) {
    path.push_back(node);
    if (node == target) {
        result.push_back(path);
    } else {
        for (int neighbor : graph[node]) {
            dfsAllPaths(graph, neighbor, target, path, result);
        }
    }
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> result;
    vector<int> path;
    dfsAllPaths(graph, 0, graph.size() - 1, path, result);
    return result;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
    vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    queue<tuple<int,int,int>> q;
    q.push({0,0,1});
    grid[0][0] = 1;
    while (!q.empty()) {
        auto [r, c, d] = q.front(); q.pop();
        if (r == n - 1 && c == n - 1) return d;
        for (auto& dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                q.push({nr, nc, d + 1});
                grid[nr][nc] = 1;
            }
        }
    }
    return -1;
}

bool hasCycle(vector<vector<int>>& graph, int node, vector<int>& state) {
    if (state[node] == 1) return true;
    if (state[node] == 2) return false;
    state[node] = 1;
    for (int neighbor : graph[node]) {
        if (hasCycle(graph, neighbor, state)) return true;
    }
    state[node] = 2;
    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    for (auto& pre : prerequisites) graph[pre[1]].push_back(pre[0]);
    vector<int> state(numCourses, 0);
    for (int i = 0; i < numCourses; i++) {
        if (hasCycle(graph, i, state)) return false;
    }
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);
    for (auto& pre : prerequisites) {
        graph[pre[1]].push_back(pre[0]);
        indegree[pre[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) if (indegree[i] == 0) q.push(i);
    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);
        for (int neighbor : graph[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }
    return order.size() == numCourses ? order : vector<int>();
}

int main() {
    // Test graph operations
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    
    cout << "DFS (recursive): ";
    vector<bool> visited(6, false);
    g.dfsRecursive(0, visited);
    cout << endl;
    
    cout << "DFS (iterative): ";
    g.dfsIterative(0);
    cout << endl;
    
    cout << "BFS: ";
    g.bfs(0);
    cout << endl;
    
    cout << "Connected components: " << g.countConnectedComponents() << endl;
    
    // Test tree operations
    TreeNode* root = new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children[0]->children.push_back(new TreeNode(4));
    root->children[0]->children.push_back(new TreeNode(5));
    
    TreeTraversal tt;
    cout << "Tree height: " << tt.maxDepth(root) << endl;
    cout << "Is balanced: " << (tt.isBalanced(root) ? "Yes" : "No") << endl;
    
    return 0;
}

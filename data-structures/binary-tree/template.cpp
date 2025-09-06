#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;
    
public:
    BinaryTree() : root(nullptr) {}
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) {
            node->left = insertHelper(node->left, val);
        } else {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }
    
    // DFS Traversals
    vector<int> preorderTraversal() {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }
    
    void preorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        result.push_back(node->val);
        preorderHelper(node->left, result);
        preorderHelper(node->right, result);
    }
    
    vector<int> inorderTraversal() {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }
    
    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        inorderHelper(node->left, result);
        result.push_back(node->val);
        inorderHelper(node->right, result);
    }
    
    vector<int> postorderTraversal() {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }
    
    void postorderHelper(TreeNode* node, vector<int>& result) {
        if (!node) return;
        postorderHelper(node->left, result);
        postorderHelper(node->right, result);
        result.push_back(node->val);
    }
    
    // BFS Traversal
    vector<vector<int>> levelOrderTraversal() {
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
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            result.push_back(level);
        }
        return result;
    }
    
    int maxDepth() {
        return maxDepthHelper(root);
    }
    
    int maxDepthHelper(TreeNode* node) {
        if (!node) return 0;
        return 1 + max(maxDepthHelper(node->left), maxDepthHelper(node->right));
    }
    
    bool isBalanced() {
        return isBalancedHelper(root) != -1;
    }
    
    int isBalancedHelper(TreeNode* node) {
        if (!node) return 0;
        
        int left = isBalancedHelper(node->left);
        if (left == -1) return -1;
        
        int right = isBalancedHelper(node->right);
        if (right == -1) return -1;
        
        if (abs(left - right) > 1) return -1;
        return 1 + max(left, right);
    }
};

// Common tree operations
bool isSameTree(TreeNode* p, TreeNode* q) {
    // TODO: Implement same tree check
    return false;
}

bool isSymmetric(TreeNode* root) {
    // TODO: Implement symmetric tree check
    return false;
}

TreeNode* invertTree(TreeNode* root) {
    // TODO: Implement tree inversion
    return nullptr;
}
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;
    return isMirror(left->left, right->right) && isMirror(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

int main() {
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);
    
    cout << "Inorder: ";
    vector<int> inorder = tree.inorderTraversal();
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Max depth: " << tree.maxDepth() << endl;
    cout << "Is balanced: " << (tree.isBalanced() ? "Yes" : "No") << endl;
    
    return 0;
}

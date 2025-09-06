#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BST {
private:
    TreeNode* root;
    
public:
    BST() : root(nullptr) {}
    
    void insert(int val) {
        root = insertHelper(root, val);
    }
    
    TreeNode* insertHelper(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) {
            node->left = insertHelper(node->left, val);
        } else if (val > node->val) {
            node->right = insertHelper(node->right, val);
        }
        return node;
    }
    
    bool search(int val) {
        return searchHelper(root, val);
    }
    
    bool searchHelper(TreeNode* node, int val) {
        if (!node) return false;
        if (val == node->val) return true;
        if (val < node->val) return searchHelper(node->left, val);
        return searchHelper(node->right, val);
    }
    
    void deleteNode(int val) {
        root = deleteHelper(root, val);
    }
    
    TreeNode* deleteHelper(TreeNode* node, int val) {
        if (!node) return nullptr;
        
        if (val < node->val) {
            node->left = deleteHelper(node->left, val);
        } else if (val > node->val) {
            node->right = deleteHelper(node->right, val);
        } else {
            if (!node->left) return node->right;
            if (!node->right) return node->left;
            
            TreeNode* minNode = findMin(node->right);
            node->val = minNode->val;
            node->right = deleteHelper(node->right, minNode->val);
        }
        return node;
    }
    
    TreeNode* findMin(TreeNode* node) {
        while (node->left) node = node->left;
        return node;
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
    
    bool isValidBST() {
        return isValidHelper(root, LONG_MIN, LONG_MAX);
    }
    
    bool isValidHelper(TreeNode* node, long min, long max) {
        if (!node) return true;
        if (node->val <= min || node->val >= max) return false;
        return isValidHelper(node->left, min, node->val) && 
               isValidHelper(node->right, node->val, max);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;
        if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
    
    int kthSmallest(int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int count = 0;
        
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            count++;
            if (count == k) return curr->val;
            curr = curr->right;
        }
        return -1;
    }
};

// Common BST operations
TreeNode* sortedArrayToBST(vector<int>& nums) {
    // TODO: Implement sorted array to BST
    return nullptr;
}

TreeNode* searchBST(TreeNode* root, int val) {
    // TODO: Implement BST search
    return nullptr;
}

int rangeSumBST(TreeNode* root, int low, int high) {
    // TODO: Implement range sum
    return 0;
}

int main() {
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(1);
    bst.insert(9);
    
    cout << "Inorder traversal: ";
    vector<int> inorder = bst.inorderTraversal();
    for (int val : inorder) {
        cout << val << " ";
    }
    cout << endl;
    
    cout << "Search 7: " << (bst.search(7) ? "Found" : "Not found") << endl;
    cout << "Is valid BST: " << (bst.isValidBST() ? "Yes" : "No") << endl;
    cout << "3rd smallest: " << bst.kthSmallest(3) << endl;
    
    return 0;
}

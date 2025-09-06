#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Backtracking {
public:
    // Generate all permutations
    vector<vector<int>> generatePermutations(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        
        function<void()> backtrack = [&]() {
            if (path.size() == nums.size()) {
                result.push_back(path);
                return;
            }
            
            for (int i = 0; i < nums.size(); i++) {
                if (used[i]) continue;
                used[i] = true;
                path.push_back(nums[i]);
                backtrack();
                path.pop_back();
                used[i] = false;
            }
        };
        
        backtrack();
        return result;
    }
    
    // Generate all combinations
    vector<vector<int>> generateCombinations(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        
        function<void(int)> backtrack = [&](int start) {
            if (path.size() == k) {
                result.push_back(path);
                return;
            }
            
            for (int i = start; i <= n; i++) {
                path.push_back(i);
                backtrack(i + 1);
                path.pop_back();
            }
        };
        
        backtrack(1);
        return result;
    }
    
    // Combination sum
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        
        function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (remaining == 0) {
                result.push_back(path);
                return;
            }
            
            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > remaining) break;
                path.push_back(candidates[i]);
                backtrack(i, remaining - candidates[i]);
                path.pop_back();
            }
        };
        
        backtrack(0, target);
        return result;
    }
    
    // N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        function<bool(int, int)> isSafe = [&](int row, int col) {
            // Check column
            for (int i = 0; i < row; i++) {
                if (board[i][col] == 'Q') return false;
            }
            
            // Check diagonal (top-left to bottom-right)
            for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
                if (board[i][j] == 'Q') return false;
            }
            
            // Check diagonal (top-right to bottom-left)
            for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
                if (board[i][j] == 'Q') return false;
            }
            
            return true;
        };
        
        function<void(int)> backtrack = [&](int row) {
            if (row == n) {
                result.push_back(board);
                return;
            }
            
            for (int col = 0; col < n; col++) {
                if (isSafe(row, col)) {
                    board[row][col] = 'Q';
                    backtrack(row + 1);
                    board[row][col] = '.';
                }
            }
        };
        
        backtrack(0);
        return result;
    }
    
    // Generate valid parentheses
    vector<string> generateParentheses(int n) {
        vector<string> result;
        string path;
        
        function<void(int, int)> backtrack = [&](int open, int close) {
            if (path.length() == 2 * n) {
                result.push_back(path);
                return;
            }
            
            if (open < n) {
                path.push_back('(');
                backtrack(open + 1, close);
                path.pop_back();
            }
            
            if (close < open) {
                path.push_back(')');
                backtrack(open, close + 1);
                path.pop_back();
            }
        };
        
        backtrack(0, 0);
        return result;
    }
    
    // Palindrome partitioning
    vector<vector<string>> palindromePartitioning(string s) {
        vector<vector<string>> result;
        vector<string> path;
        
        function<bool(string)> isPalindrome = [](string str) {
            int left = 0, right = str.length() - 1;
            while (left < right) {
                if (str[left] != str[right]) return false;
                left++;
                right--;
            }
            return true;
        };
        
        function<void(int)> backtrack = [&](int start) {
            if (start == s.length()) {
                result.push_back(path);
                return;
            }
            
            for (int end = start + 1; end <= s.length(); end++) {
                string substring = s.substr(start, end - start);
                if (isPalindrome(substring)) {
                    path.push_back(substring);
                    backtrack(end);
                    path.pop_back();
                }
            }
        };
        
        backtrack(0);
        return result;
    }
    
    // Subset sum
    vector<vector<int>> subsetSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(nums.begin(), nums.end());
        
        function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (remaining == 0) {
                result.push_back(path);
                return;
            }
            
            for (int i = start; i < nums.size(); i++) {
                if (nums[i] > remaining) break;
                path.push_back(nums[i]);
                backtrack(i + 1, remaining - nums[i]);
                path.pop_back();
            }
        };
        
        backtrack(0, target);
        return result;
    }
};

// Common backtracking problems
bool isValidSudoku(vector<vector<char>>& board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValidSudoku(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool dfsWordSearch(vector<vector<char>>& board, int i, int j, string& word, int idx) {
    if (idx == word.size()) return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) return false;
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = dfsWordSearch(board, i + 1, j, word, idx + 1) ||
                 dfsWordSearch(board, i - 1, j, word, idx + 1) ||
                 dfsWordSearch(board, i, j + 1, word, idx + 1) ||
                 dfsWordSearch(board, i, j - 1, word, idx + 1);
    board[i][j] = temp;
    return found;
}

vector<string> wordSearchII(vector<vector<char>>& board, vector<string>& words) {
    set<string> result;
    int m = board.size(), n = board[0].size();
    for (string& word : words) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfsWordSearch(board, i, j, word, 0)) {
                    result.insert(word);
                }
            }
        }
    }
    return vector<string>(result.begin(), result.end());
}

int main() {
    Backtracking bt;
    
    // Test permutations
    vector<int> nums = {1, 2, 3};
    auto permutations = bt.generatePermutations(nums);
    cout << "Permutations of [1,2,3]:" << endl;
    for (auto& perm : permutations) {
        for (int num : perm) cout << num << " ";
        cout << endl;
    }
    
    // Test combinations
    auto combinations = bt.generateCombinations(4, 2);
    cout << "\nCombinations of 2 from 1-4:" << endl;
    for (auto& comb : combinations) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
    
    // Test combination sum
    vector<int> candidates = {2, 3, 6, 7};
    auto combSum = bt.combinationSum(candidates, 7);
    cout << "\nCombinations that sum to 7:" << endl;
    for (auto& comb : combSum) {
        for (int num : comb) cout << num << " ";
        cout << endl;
    }
    
    // Test parentheses
    auto parentheses = bt.generateParentheses(3);
    cout << "\nValid parentheses for n=3:" << endl;
    for (string& paren : parentheses) {
        cout << paren << endl;
    }
    
    return 0;
}

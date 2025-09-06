#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MonotonicStack {
private:
    stack<int> st;
    
public:
    void push(int val) {
        while (!st.empty() && st.top() < val) {
            st.pop();
        }
        st.push(val);
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        return st.empty() ? -1 : st.top();
    }
    
    bool empty() {
        return st.empty();
    }
    
    int size() {
        return st.size();
    }
};

class MonotonicOperations {
public:
    // Next greater element
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    
    // Next smaller element
    vector<int> nextSmallerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    
    // Previous greater element
    vector<int> previousGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    
    // Previous smaller element
    vector<int> previousSmallerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                result[st.top()] = nums[i];
                st.pop();
            }
            st.push(i);
        }
        return result;
    }
    
    // Largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
    
    // Trapping rain water
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        stack<int> st;
        int water = 0;
        
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int top = st.top();
                st.pop();
                
                if (st.empty()) break;
                
                int distance = i - st.top() - 1;
                int boundedHeight = min(height[i], height[st.top()]) - height[top];
                water += distance * boundedHeight;
            }
            st.push(i);
        }
        return water;
    }
    
    // Daily temperatures
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int prevIndex = st.top();
                st.pop();
                result[prevIndex] = i - prevIndex;
            }
            st.push(i);
        }
        return result;
    }
    
    // Stock span problem
    vector<int> stockSpan(vector<int>& prices) {
        int n = prices.size();
        vector<int> span(n, 1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.top()] <= prices[i]) {
                st.pop();
            }
            span[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return span;
    }
    
    // Sum of subarray minimums
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> st;
        
        // Find previous smaller element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        
        // Find next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        
        long long result = 0;
        for (int i = 0; i < n; i++) {
            result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % 1000000007;
        }
        return result;
    }
    
    // Online stock span
    class StockSpanner {
    private:
        stack<pair<int, int>> st; // {price, span}
        
    public:
        int next(int price) {
            int span = 1;
            while (!st.empty() && st.top().first <= price) {
                span += st.top().second;
                st.pop();
            }
            st.push({price, span});
            return span;
        }
    };
    
    // Remove duplicate letters
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> visited(26, false);
        stack<char> st;
        
        for (char c : s) count[c - 'a']++;
        
        for (char c : s) {
            count[c - 'a']--;
            if (visited[c - 'a']) continue;
            
            while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            
            st.push(c);
            visited[c - 'a'] = true;
        }
        
        string result = "";
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};

// Common monotonic stack problems
// LeetCode 503: Next Greater Element II (circular array)
vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1);
    stack<int> st;
    for (int i = 0; i < 2 * n; i++) {
        int num = nums[i % n];
        while (!st.empty() && nums[st.top()] < num) {
            result[st.top()] = num;
            st.pop();
        }
        if (i < n) st.push(i);
    }
    return result;
}

// LeetCode 85: Maximal Rectangle
int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int maxArea = 0;
    int cols = matrix[0].size();
    vector<int> heights(cols, 0);
    for (const auto& row : matrix) {
        for (int i = 0; i < cols; i++) {
            heights[i] = row[i] == '1' ? heights[i] + 1 : 0;
        }
        // Use largestRectangleArea from above
        stack<int> st;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            while (!st.empty() && heights[st.top()] > h) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
    }
    return maxArea;
}

int main() {
    MonotonicOperations mo;
    
    // Test next greater element
    vector<int> nums = {4, 5, 2, 10, 8};
    vector<int> nge = mo.nextGreaterElement(nums);
    cout << "Next greater elements: ";
    for (int val : nge) cout << val << " ";
    cout << endl;
    
    // Test largest rectangle
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Largest rectangle area: " << mo.largestRectangleArea(heights) << endl;
    
    // Test trapping rain water
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped water: " << mo.trap(water) << endl;
    
    // Test daily temperatures
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> days = mo.dailyTemperatures(temps);
    cout << "Days to warmer temperature: ";
    for (int val : days) cout << val << " ";
    cout << endl;
    
    // Test stock span
    vector<int> prices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans = mo.stockSpan(prices);
    cout << "Stock spans: ";
    for (int val : spans) cout << val << " ";
    cout << endl;
    
    // Test sum of subarray minimums
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of subarray minimums: " << mo.sumSubarrayMins(arr) << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class MonotonicQueue {
private:
    deque<int> dq;
    
public:
    void push(int val) {
        while (!dq.empty() && dq.back() < val) {
            dq.pop_back();
        }
        dq.push_back(val);
    }
    
    void pop(int val) {
        if (!dq.empty() && dq.front() == val) {
            dq.pop_front();
        }
    }
    
    int max() {
        return dq.front();
    }
    
    bool empty() {
        return dq.empty();
    }
    
    int size() {
        return dq.size();
    }
};

class MonotonicStack {
private:
    vector<int> st;
    
public:
    void push(int val) {
        while (!st.empty() && st.back() < val) {
            st.pop_back();
        }
        st.push_back(val);
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop_back();
        }
    }
    
    int top() {
        return st.empty() ? -1 : st.back();
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
    // Sliding window maximum
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue mq;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); i++) {
            mq.push(nums[i]);
            
            if (i >= k - 1) {
                result.push_back(mq.max());
                mq.pop(nums[i - k + 1]);
            }
        }
        return result;
    }
    
    // Next greater element
    vector<int> nextGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        MonotonicStack st;
        
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
        vector<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                result[st.back()] = nums[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return result;
    }
    
    // Previous greater element
    vector<int> previousGreaterElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        vector<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] < nums[i]) {
                result[st.back()] = nums[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return result;
    }
    
    // Previous smaller element
    vector<int> previousSmallerElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        vector<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] > nums[i]) {
                result[st.back()] = nums[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return result;
    }
    
    // Largest rectangle in histogram
    int largestRectangleArea(vector<int>& heights) {
        vector<int> st;
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            int h = (i == n) ? 0 : heights[i];
            
            while (!st.empty() && heights[st.back()] > h) {
                int height = heights[st.back()];
                st.pop_back();
                int width = st.empty() ? i : i - st.back() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push_back(i);
        }
        return maxArea;
    }
    
    // Trapping rain water
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                right--;
            }
        }
        return water;
    }
    
    // Daily temperatures
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        vector<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[st.back()] < temperatures[i]) {
                int prevIndex = st.back();
                st.pop_back();
                result[prevIndex] = i - prevIndex;
            }
            st.push_back(i);
        }
        return result;
    }
    
    // Stock span problem
    vector<int> stockSpan(vector<int>& prices) {
        int n = prices.size();
        vector<int> span(n, 1);
        vector<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && prices[st.back()] <= prices[i]) {
                st.pop_back();
            }
            span[i] = st.empty() ? i + 1 : i - st.back();
            st.push_back(i);
        }
        return span;
    }
    
    // Minimum cost to remove all elements
    int minCost(vector<int>& arr, int x) {
        int n = arr.size();
        int minCost = 0;
        vector<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.back()] > arr[i]) {
                st.pop_back();
            }
            if (!st.empty()) {
                minCost += x;
            }
            st.push_back(i);
        }
        return minCost;
    }
};

// Common monotonic problems
// Returns an array of the minimum of each subarray (for demonstration, not a standard problem)
vector<int> sumOfSubarrayMinimums(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        int minVal = arr[i];
        for (int j = i; j < n; j++) {
            minVal = min(minVal, arr[j]);
            result[i] += minVal;
        }
    }
    return result;
}

// LeetCode 907: Sum of Subarray Minimums
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n), right(n);
    stack<int> st;
    // Previous less element
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }
        left[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    // Next less element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        right[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    long long result = 0;
    int MOD = 1e9 + 7;
    for (int i = 0; i < n; i++) {
        result = (result + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % MOD;
    }
    return (int)result;
}

int main() {
    MonotonicOperations mo;
    
    // Test sliding window maximum
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = mo.maxSlidingWindow(nums, k);
    cout << "Sliding window maximum: ";
    for (int val : result) cout << val << " ";
    cout << endl;
    
    // Test next greater element
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> nge = mo.nextGreaterElement(arr);
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
    
    return 0;
}

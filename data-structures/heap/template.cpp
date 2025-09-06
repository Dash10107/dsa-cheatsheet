#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] <= heap[index]) break;
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }
    
    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;
            
            if (left < heap.size() && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < heap.size() && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if (smallest == index) break;
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
    
public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    
    int pop() {
        if (heap.empty()) return -1;
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return min;
    }
    
    int peek() {
        return heap.empty() ? -1 : heap[0];
    }
    
    int size() {
        return heap.size();
    }
    
    bool empty() {
        return heap.empty();
    }
};

class MaxHeap {
private:
    vector<int> heap;
    
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] >= heap[index]) break;
            swap(heap[parent], heap[index]);
            index = parent;
        }
    }
    
    void heapifyDown(int index) {
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            
            if (left < heap.size() && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < heap.size() && heap[right] > heap[largest]) {
                largest = right;
            }
            
            if (largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }
    
public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    
    int pop() {
        if (heap.empty()) return -1;
        int max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return max;
    }
    
    int peek() {
        return heap.empty() ? -1 : heap[0];
    }
    
    int size() {
        return heap.size();
    }
    
    bool empty() {
        return heap.empty();
    }
};

class MedianFinder {
private:
    priority_queue<int> small; // max heap
    priority_queue<int, vector<int>, greater<int>> large; // min heap
    
public:
    void addNum(int num) {
        if (small.size() == large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if (small.size() == large.size()) {
            return (small.top() + large.top()) / 2.0;
        } else {
            return large.top();
        }
    }
};

// Common heap operations
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}

vector<int> mergeSortedArrays(vector<vector<int>>& arrays) {
    typedef tuple<int, int, int> T; // value, array index, element index
    priority_queue<T, vector<T>, greater<T>> pq;
    int total = 0;
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            pq.emplace(arrays[i][0], i, 0);
            total += arrays[i].size();
        }
    }
    vector<int> result;
    while (!pq.empty()) {
        auto [val, arrIdx, elemIdx] = pq.top(); pq.pop();
        result.push_back(val);
        if (elemIdx + 1 < arrays[arrIdx].size()) {
            pq.emplace(arrays[arrIdx][elemIdx + 1], arrIdx, elemIdx + 1);
        }
    }
    return result;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> freq;
    for (int num : nums) freq[num]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto& [num, count] : freq) {
        pq.emplace(count, num);
        if (pq.size() > k) pq.pop();
    }
    vector<int> res;
    while (!pq.empty()) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int kthSmallestInMatrix(vector<vector<int>>& matrix, int k) {
    typedef tuple<int, int, int> T; // value, row, col
    int n = matrix.size();
    priority_queue<T, vector<T>, greater<T>> pq;
    for (int i = 0; i < n; ++i) pq.emplace(matrix[i][0], i, 0);
    int count = 0;
    while (!pq.empty()) {
        auto [val, row, col] = pq.top(); pq.pop();
        count++;
        if (count == k) return val;
        if (col + 1 < n) pq.emplace(matrix[row][col + 1], row, col + 1);
    }
    return -1;
}

vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

int main() {
    MinHeap minHeap;
    minHeap.push(3);
    minHeap.push(1);
    minHeap.push(4);
    minHeap.push(1);
    minHeap.push(5);
    
    cout << "Min heap: ";
    while (!minHeap.empty()) {
        cout << minHeap.pop() << " ";
    }
    cout << endl;
    
    MaxHeap maxHeap;
    maxHeap.push(3);
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(1);
    maxHeap.push(5);
    
    cout << "Max heap: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.pop() << " ";
    }
    cout << endl;
    
    return 0;
}

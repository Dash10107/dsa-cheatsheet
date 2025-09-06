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
    // TODO: Implement kth largest element
    return 0;
}

vector<int> mergeSortedArrays(vector<vector<int>>& arrays) {
    // TODO: Implement merge k sorted arrays
    return {};
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    // TODO: Implement top k frequent elements
    return {};
}

int kthSmallestInMatrix(vector<vector<int>>& matrix, int k) {
    // TODO: Implement kth smallest in sorted matrix
    return 0;
}

vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    // TODO: Implement sliding window maximum
    return {};
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

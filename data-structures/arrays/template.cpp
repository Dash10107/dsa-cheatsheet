#include <vector>
#include <iostream>
using namespace std;

class Array {
private:
    vector<int> data;
    
public:
    Array(vector<int> arr = {}) : data(arr) {}
    
    int get(int index) {
        if (index >= 0 && index < data.size()) {
            return data[index];
        }
        return -1; // or throw exception
    }
    
    void set(int index, int value) {
        if (index >= 0 && index < data.size()) {
            data[index] = value;
        }
    }
    
    void append(int value) {
        data.push_back(value);
    }
    
    void insert(int index, int value) {
        if (index >= 0 && index <= data.size()) {
            data.insert(data.begin() + index, value);
        }
    }
    
    void remove(int value) {
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (*it == value) {
                data.erase(it);
                break;
            }
        }
    }
    
    int pop(int index = -1) {
        if (data.empty()) return -1;
        if (index == -1) index = data.size() - 1;
        int val = data[index];
        data.erase(data.begin() + index);
        return val;
    }
    
    int size() {
        return data.size();
    }
    
    void print() {
        for (int i = 0; i < data.size(); i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// Common array operations
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (map.count(complement)) {
            return {map[complement], i};
        }
        map[nums[i]] = i;
    }
    return {};
}

int maxSubarray(vector<int>& nums) {
    int maxSum = nums[0];
    int currSum = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> output(n, 1);
    int left = 1;
    for (int i = 0; i < n; ++i) {
        output[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}

int main() {
    Array arr({1, 2, 3, 4, 5});
    arr.print();
    cout << "Size: " << arr.size() << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;
    
    return 0;
}

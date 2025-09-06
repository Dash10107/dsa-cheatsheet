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
    // TODO: Implement two sum
    return {};
}

int maxSubarray(vector<int>& nums) {
    // TODO: Implement Kadane's algorithm
    return 0;
}

vector<int> productExceptSelf(vector<int>& nums) {
    // TODO: Implement product except self
    return {};
}

int main() {
    Array arr({1, 2, 3, 4, 5});
    arr.print();
    cout << "Size: " << arr.size() << endl;
    cout << "Element at index 2: " << arr.get(2) << endl;
    
    return 0;
}

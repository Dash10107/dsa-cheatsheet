#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class HashMap {
private:
    unordered_map<string, int> map;
    
public:
    void put(string key, int value) {
        map[key] = value;
    }
    
    int get(string key) {
        auto it = map.find(key);
        return (it != map.end()) ? it->second : -1;
    }
    
    void remove(string key) {
        map.erase(key);
    }
    
    bool containsKey(string key) {
        return map.find(key) != map.end();
    }
    
    int size() {
        return map.size();
    }
    
    bool empty() {
        return map.empty();
    }
    
    void clear() {
        map.clear();
    }
    
    vector<string> keys() {
        vector<string> result;
        for (auto& pair : map) {
            result.push_back(pair.first);
        }
        return result;
    }
    
    vector<int> values() {
        vector<int> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        return result;
    }
};

// Common hashmap operations
vector<int> twoSum(vector<int>& nums, int target) {
    // TODO: Implement two sum using hashmap
    return {};
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    // TODO: Implement group anagrams
    return {};
}

int longestConsecutive(vector<int>& nums) {
    // TODO: Implement longest consecutive sequence
    return 0;
}

bool containsDuplicate(vector<int>& nums) {
    // TODO: Implement duplicate check
    return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // TODO: Implement array intersection
    return {};
}

int main() {
    HashMap hm;
    hm.put("apple", 5);
    hm.put("banana", 3);
    hm.put("cherry", 8);
    
    cout << "Size: " << hm.size() << endl;
    cout << "Value for 'apple': " << hm.get("apple") << endl;
    cout << "Contains 'banana': " << (hm.containsKey("banana") ? "Yes" : "No") << endl;
    
    vector<string> keys = hm.keys();
    cout << "Keys: ";
    for (string key : keys) {
        cout << key << " ";
    }
    cout << endl;
    
    return 0;
}

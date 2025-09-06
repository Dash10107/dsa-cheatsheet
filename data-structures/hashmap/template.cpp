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

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string& s : strs) {
        string key = s;
        sort(key.begin(), key.end());
        map[key].push_back(s);
    }
    vector<vector<string>> result;
    for (auto& p : map) {
        result.push_back(p.second);
    }
    return result;
}

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int longest = 0;
    for (int num : set) {
        if (!set.count(num - 1)) {
            int current = num;
            int streak = 1;
            while (set.count(current + 1)) {
                current++;
                streak++;
            }
            longest = max(longest, streak);
        }
    }
    return longest;
}

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for (int num : nums) {
        if (!set.insert(num).second) return true;
    }
    return false;
}

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> result;
    for (int n : nums2) if (set1.count(n)) result.insert(n);
    return vector<int>(result.begin(), result.end());
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

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class SlidingWindow {
public:
    // Maximum sum of subarray of size k
    int maxSumSubarray(vector<int>& nums, int k) {
        if (nums.size() < k) return -1;
        
        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }
        
        int maxSum = windowSum;
        for (int i = k; i < nums.size(); i++) {
            windowSum = windowSum - nums[i - k] + nums[i];
            maxSum = max(maxSum, windowSum);
        }
        return maxSum;
    }
    
    // Longest substring without repeating characters
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            while (window.find(s[right]) != window.end()) {
                window.erase(s[left]);
                left++;
            }
            window.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
    
    // Longest substring with at most K distinct characters
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> window;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            window[s[right]]++;
            
            while (window.size() > k) {
                window[s[left]]--;
                if (window[s[left]] == 0) {
                    window.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
    
    // Minimum window substring
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;
        
        while (right < s.length()) {
            char c = s[right];
            right++;
            
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            
            while (valid == need.size()) {
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                
                char d = s[left];
                left++;
                
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
    
    // Find all anagrams in a string
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length() < p.length()) return result;
        
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0;
        
        while (right < s.length()) {
            char c = s[right];
            right++;
            
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            
            while (right - left >= p.length()) {
                if (valid == need.size()) {
                    result.push_back(left);
                }
                
                char d = s[left];
                left++;
                
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return result;
    }
    
    // Permutation in string
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        unordered_map<char, int> need, window;
        for (char c : s1) need[c]++;
        
        int left = 0, right = 0;
        int valid = 0;
        
        while (right < s2.length()) {
            char c = s2[right];
            right++;
            
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            
            while (right - left >= s1.length()) {
                if (valid == need.size()) return true;
                
                char d = s2[left];
                left++;
                
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return false;
    }
    
    // Maximum number of vowels in a substring
    int maxVowels(string s, int k) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int maxCount = 0;
        int currentCount = 0;
        
        for (int i = 0; i < k; i++) {
            if (vowels.count(s[i])) currentCount++;
        }
        maxCount = currentCount;
        
        for (int i = k; i < s.length(); i++) {
            if (vowels.count(s[i - k])) currentCount--;
            if (vowels.count(s[i])) currentCount++;
            maxCount = max(maxCount, currentCount);
        }
        return maxCount;
    }
    
    // Longest repeating character replacement
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;
        int left = 0, maxLen = 0;
        int maxCount = 0;
        
        for (int right = 0; right < s.length(); right++) {
            window[s[right]]++;
            maxCount = max(maxCount, window[s[right]]);
            
            if (right - left + 1 - maxCount > k) {
                window[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
    
    // Subarray product less than K
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int left = 0, count = 0;
        long product = 1;
        
        for (int right = 0; right < nums.size(); right++) {
            product *= nums[right];
            
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    
    // Fruit into baskets
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> window;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < fruits.size(); right++) {
            window[fruits[right]]++;
            
            while (window.size() > 2) {
                window[fruits[left]]--;
                if (window[fruits[left]] == 0) {
                    window.erase(fruits[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

// Common sliding window problems
// LeetCode 239: Sliding Window Maximum
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq;
    for (int i = 0; i < nums.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

// LeetCode 1004: Max Consecutive Ones III
int longestOnes(vector<int>& nums, int k) {
    int left = 0, maxLen = 0, zeros = 0;
    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0) zeros++;
        while (zeros > k) {
            if (nums[left++] == 0) zeros--;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    SlidingWindow sw;
    
    // Test maximum sum subarray
    vector<int> nums = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    cout << "Max sum of subarray of size " << k << ": " << sw.maxSumSubarray(nums, k) << endl;
    
    // Test longest substring without repeating characters
    string s = "abcabcbb";
    cout << "Longest substring without repeating: " << sw.lengthOfLongestSubstring(s) << endl;
    
    // Test minimum window substring
    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << "Minimum window substring: " << sw.minWindow(s1, t1) << endl;
    
    // Test find anagrams
    string s2 = "cbaebabacd";
    string p = "abc";
    vector<int> anagrams = sw.findAnagrams(s2, p);
    cout << "Anagram indices: ";
    for (int idx : anagrams) cout << idx << " ";
    cout << endl;
    
    // Test permutation in string
    string s3 = "ab";
    string s4 = "eidbaooo";
    cout << "Permutation in string: " << (sw.checkInclusion(s3, s4) ? "Yes" : "No") << endl;
    
    return 0;
}

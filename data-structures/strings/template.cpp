#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class StringOperations {
public:
    // Basic string operations
    int length(string s) {
        return s.length();
    }
    
    string reverse(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
    
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    
    string toLowerCase(string s) {
        for (char& c : s) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
        }
        return s;
    }
    
    string toUpperCase(string s) {
        for (char& c : s) {
            if (c >= 'a' && c <= 'z') {
                c = c - 'a' + 'A';
            }
        }
        return s;
    }
    
    // String searching
    int findFirstOccurrence(string text, string pattern) {
        int n = text.length();
        int m = pattern.length();
        
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) break;
            }
            if (j == m) return i;
        }
        return -1;
    }
    
    vector<int> findAllOccurrences(string text, string pattern) {
        vector<int> result;
        int n = text.length();
        int m = pattern.length();
        
        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j]) break;
            }
            if (j == m) result.push_back(i);
        }
        return result;
    }
    
    // String manipulation
    string removeSpaces(string s) {
        string result = "";
        for (char c : s) {
            if (c != ' ') {
                result += c;
            }
        }
        return result;
    }
    
    string removeDuplicates(string s) {
        unordered_map<char, bool> seen;
        string result = "";
        for (char c : s) {
            if (seen.find(c) == seen.end()) {
                seen[c] = true;
                result += c;
            }
        }
        return result;
    }
    
    string sortString(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    
    // Advanced string operations
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        unordered_map<char, int> count;
        for (char c : s) count[c]++;
        for (char c : t) {
            count[c]--;
            if (count[c] < 0) return false;
        }
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }
        return prefix;
    }
    
    int longestSubstringWithoutRepeating(string s) {
        unordered_map<char, int> charMap;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            if (charMap.find(s[right]) != charMap.end()) {
                left = max(left, charMap[s[right]] + 1);
            }
            charMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
    
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.length();
    }
};

// Common string problems
string longestPalindrome(string s) {
    int n = s.size(), start = 0, maxLen = 1;
    if (n < 2) return s;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i) dp[i][i] = true;
    for (int l = 2; l <= n; ++l) {
        for (int i = 0; i <= n - l; ++i) {
            int j = i + l - 1;
            if (s[i] == s[j]) {
                if (l == 2 || dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (l > maxLen) {
                        start = i;
                        maxLen = l;
                    }
                }
            }
        }
    }
    return s.substr(start, maxLen);
}

string minWindow(string s, string t) {
    unordered_map<char, int> dictT;
    for (char c : t) dictT[c]++;
    int required = dictT.size(), formed = 0, l = 0, r = 0, minLen = INT_MAX, minStart = 0;
    unordered_map<char, int> windowCounts;
    while (r < s.size()) {
        char c = s[r++];
        windowCounts[c]++;
        if (dictT.count(c) && windowCounts[c] == dictT[c]) formed++;
        while (formed == required) {
            if (r - l < minLen) {
                minLen = r - l;
                minStart = l;
            }
            char cl = s[l++];
            windowCounts[cl]--;
            if (dictT.count(cl) && windowCounts[cl] < dictT[cl]) formed--;
        }
    }
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (string& word : strs) {
        string key = word;
        sort(key.begin(), key.end());
        mp[key].push_back(word);
    }
    vector<vector<string>> res;
    for (auto& p : mp) res.push_back(p.second);
    return res;
}

string decodeString(string s) {
    stack<int> counts;
    stack<string> result;
    string res = "";
    int idx = 0;
    while (idx < s.size()) {
        if (isdigit(s[idx])) {
            int count = 0;
            while (isdigit(s[idx])) count = 10 * count + (s[idx++] - '0');
            counts.push(count);
        } else if (s[idx] == '[') {
            result.push(res);
            res = "";
            idx++;
        } else if (s[idx] == ']') {
            string temp = result.top(); result.pop();
            int repeatTimes = counts.top(); counts.pop();
            for (int i = 0; i < repeatTimes; ++i) temp += res;
            res = temp;
            idx++;
        } else {
            res += s[idx++];
        }
    }
    return res;
}

int main() {
    StringOperations ops;
    
    string test = "Hello World";
    cout << "Original: " << test << endl;
    cout << "Reversed: " << ops.reverse(test) << endl;
    cout << "Length: " << ops.length(test) << endl;
    cout << "Is palindrome: " << (ops.isPalindrome("racecar") ? "Yes" : "No") << endl;
    
    string text = "ababcababc";
    string pattern = "abc";
    cout << "First occurrence of '" << pattern << "': " << ops.findFirstOccurrence(text, pattern) << endl;
    
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest common prefix: " << ops.longestCommonPrefix(strs) << endl;
    
    return 0;
}

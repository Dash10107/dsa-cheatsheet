#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class TwoPointers {
public:
    // Two sum in sorted array
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1};
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
    
    // Three sum
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
    
    // Container with most water
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;
        
        while (left < right) {
            int water = min(height[left], height[right]) * (right - left);
            maxWater = max(maxWater, water);
            
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
    
    // Remove duplicates from sorted array
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int slow = 0;
        for (int fast = 1; fast < nums.size(); fast++) {
            if (nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        return slow + 1;
    }
    
    // Move zeroes to end
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }
    }
    
    // Valid palindrome
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;
            
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    
    // Sort colors (Dutch flag problem)
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
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
    
    // Remove element
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
    
    // Merge sorted arrays
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
    
    // Squares of sorted array
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        
        for (int i = n - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                result[i] = nums[left] * nums[left];
                left++;
            } else {
                result[i] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
    
    // Backspace string compare
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            i--;
            j--;
        }
        return true;
    }
    
    // Partition array into three parts
    bool canThreePartsEqualSum(vector<int>& arr) {
        int totalSum = 0;
        for (int num : arr) totalSum += num;
        
        if (totalSum % 3 != 0) return false;
        
        int target = totalSum / 3;
        int currentSum = 0;
        int parts = 0;
        
        for (int num : arr) {
            currentSum += num;
            if (currentSum == target) {
                parts++;
                currentSum = 0;
            }
        }
        return parts >= 3;
    }
};

// Common two pointers problems
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    // TODO: Implement four sum
    return {};
}

int longestMountain(vector<int>& arr) {
    // TODO: Implement longest mountain
    return 0;
}

bool isSubsequence(string s, string t) {
    // TODO: Implement is subsequence
    return false;
}

int main() {
    TwoPointers tp;
    
    // Test two sum
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = tp.twoSum(numbers, target);
    cout << "Two sum indices: " << result[0] << ", " << result[1] << endl;
    
    // Test three sum
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = tp.threeSum(nums);
    cout << "Three sum triplets: " << triplets.size() << " found" << endl;
    
    // Test container with most water
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max water area: " << tp.maxArea(height) << endl;
    
    // Test valid palindrome
    string s = "A man a plan a canal Panama";
    cout << "Is palindrome: " << (tp.isPalindrome(s) ? "Yes" : "No") << endl;
    
    // Test trapping rain water
    vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped water: " << tp.trap(water) << endl;
    
    // Test sorted squares
    vector<int> squares = {-4, -1, 0, 3, 10};
    vector<int> result2 = tp.sortedSquares(squares);
    cout << "Sorted squares: ";
    for (int val : result2) cout << val << " ";
    cout << endl;
    
    return 0;
}

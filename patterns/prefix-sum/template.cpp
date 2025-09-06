#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class PrefixSum {
public:
    // 1D Prefix Sum
    vector<int> buildPrefixSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        return prefix;
    }
    
    int rangeSum(vector<int>& prefix, int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
    
    // 2D Prefix Sum
    vector<vector<int>> build2DPrefixSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefix[i][j] = matrix[i - 1][j - 1] + 
                              prefix[i - 1][j] + 
                              prefix[i][j - 1] - 
                              prefix[i - 1][j - 1];
            }
        }
        return prefix;
    }
    
    int rangeSum2D(vector<vector<int>>& prefix, int row1, int col1, int row2, int col2) {
        return prefix[row2 + 1][col2 + 1] - 
               prefix[row1][col2 + 1] - 
               prefix[row2 + 1][col1] + 
               prefix[row1][col1];
    }
    
    // Subarray sum equals K
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1;
        
        int count = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            if (prefixCount.find(prefixSum - k) != prefixCount.end()) {
                count += prefixCount[prefixSum - k];
            }
            prefixCount[prefixSum]++;
        }
        return count;
    }
    
    // Subarray sum divisible by K
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> remainderCount;
        remainderCount[0] = 1;
        
        int count = 0;
        int prefixSum = 0;
        
        for (int num : nums) {
            prefixSum += num;
            int remainder = ((prefixSum % k) + k) % k;
            
            if (remainderCount.find(remainder) != remainderCount.end()) {
                count += remainderCount[remainder];
            }
            remainderCount[remainder]++;
        }
        return count;
    }
    
    // Continuous subarray sum
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1;
        
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            int remainder = k == 0 ? prefixSum : prefixSum % k;
            
            if (remainderIndex.find(remainder) != remainderIndex.end()) {
                if (i - remainderIndex[remainder] > 1) {
                    return true;
                }
            } else {
                remainderIndex[remainder] = i;
            }
        }
        return false;
    }
    
    // Product of array except self
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 1);
        
        // Left pass
        for (int i = 1; i < n; i++) {
            result[i] = result[i - 1] * nums[i - 1];
        }
        
        // Right pass
        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= rightProduct;
            rightProduct *= nums[i];
        }
        return result;
    }
    
    // Range sum query 2D
    class NumMatrix {
    private:
        vector<vector<int>> prefix;
        
    public:
        NumMatrix(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            prefix = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
            
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                    prefix[i][j] = matrix[i - 1][j - 1] + 
                                  prefix[i - 1][j] + 
                                  prefix[i][j - 1] - 
                                  prefix[i - 1][j - 1];
                }
            }
        }
        
        int sumRegion(int row1, int col1, int row2, int col2) {
            return prefix[row2 + 1][col2 + 1] - 
                   prefix[row1][col2 + 1] - 
                   prefix[row2 + 1][col1] + 
                   prefix[row1][col1];
        }
    };
    
    // Count number of nice subarrays
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        
        int result = 0;
        int oddCount = 0;
        
        for (int num : nums) {
            if (num % 2 == 1) oddCount++;
            
            if (count.find(oddCount - k) != count.end()) {
                result += count[oddCount - k];
            }
            count[oddCount]++;
        }
        return result;
    }
    
    // Subarray sum with target
    vector<int> subarraySum(vector<int>& nums, int target) {
        unordered_map<int, int> prefixIndex;
        prefixIndex[0] = -1;
        
        int prefixSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            if (prefixIndex.find(prefixSum - target) != prefixIndex.end()) {
                return {prefixIndex[prefixSum - target] + 1, i};
            }
            prefixIndex[prefixSum] = i;
        }
        return {};
    }
    
    // Maximum size subarray sum equals k
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> prefixIndex;
        prefixIndex[0] = -1;
        
        int maxLen = 0;
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];
            
            if (prefixIndex.find(prefixSum - k) != prefixIndex.end()) {
                maxLen = max(maxLen, i - prefixIndex[prefixSum - k]);
            }
            
            if (prefixIndex.find(prefixSum) == prefixIndex.end()) {
                prefixIndex[prefixSum] = i;
            }
        }
        return maxLen;
    }
};

// Common prefix sum problems
int findMaxLength(vector<int>& nums) {
    // TODO: Implement contiguous array
    return 0;
}

int subarraySum(vector<int>& nums, int k) {
    // TODO: Implement subarray sum equals K
    return 0;
}

int main() {
    PrefixSum ps;
    
    // Test 1D prefix sum
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<int> prefix = ps.buildPrefixSum(nums);
    cout << "Range sum [1, 3]: " << ps.rangeSum(prefix, 1, 3) << endl;
    
    // Test subarray sum equals K
    vector<int> arr = {1, 1, 1};
    int k = 2;
    cout << "Subarrays with sum " << k << ": " << ps.subarraySum(arr, k) << endl;
    
    // Test subarray sum divisible by K
    vector<int> nums2 = {4, 5, 0, -2, -3, 1};
    int k2 = 5;
    cout << "Subarrays divisible by " << k2 << ": " << ps.subarraysDivByK(nums2, k2) << endl;
    
    // Test product except self
    vector<int> nums3 = {1, 2, 3, 4};
    vector<int> result = ps.productExceptSelf(nums3);
    cout << "Product except self: ";
    for (int val : result) cout << val << " ";
    cout << endl;
    
    // Test 2D prefix sum
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 0, 1, 7},
        {1, 0, 3, 0, 5}
    };
    auto prefix2D = ps.build2DPrefixSum(matrix);
    cout << "2D range sum: " << ps.rangeSum2D(prefix2D, 2, 1, 4, 3) << endl;
    
    return 0;
}

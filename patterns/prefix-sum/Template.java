import java.util.*;

public class Template {
    static class PrefixSum {
        // 1D Prefix Sum
        public static int[] buildPrefixSum(int[] nums) {
            int n = nums.length;
            int[] prefix = new int[n + 1];
            
            for (int i = 0; i < n; i++) {
                prefix[i + 1] = prefix[i] + nums[i];
            }
            return prefix;
        }
        
        public static int rangeSum(int[] prefix, int left, int right) {
            return prefix[right + 1] - prefix[left];
        }
        
        // 2D Prefix Sum
        public static int[][] build2DPrefixSum(int[][] matrix) {
            int m = matrix.length;
            int n = matrix[0].length;
            int[][] prefix = new int[m + 1][n + 1];
            
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
        
        public static int rangeSum2D(int[][] prefix, int row1, int col1, int row2, int col2) {
            return prefix[row2 + 1][col2 + 1] - 
                   prefix[row1][col2 + 1] - 
                   prefix[row2 + 1][col1] + 
                   prefix[row1][col1];
        }
        
        // Subarray sum equals K
        public static int subarraySum(int[] nums, int k) {
            Map<Integer, Integer> prefixCount = new HashMap<>();
            prefixCount.put(0, 1);
            
            int count = 0;
            int prefixSum = 0;
            
            for (int num : nums) {
                prefixSum += num;
                if (prefixCount.containsKey(prefixSum - k)) {
                    count += prefixCount.get(prefixSum - k);
                }
                prefixCount.put(prefixSum, prefixCount.getOrDefault(prefixSum, 0) + 1);
            }
            return count;
        }
        
        // Subarray sum divisible by K
        public static int subarraysDivByK(int[] nums, int k) {
            Map<Integer, Integer> remainderCount = new HashMap<>();
            remainderCount.put(0, 1);
            
            int count = 0;
            int prefixSum = 0;
            
            for (int num : nums) {
                prefixSum += num;
                int remainder = ((prefixSum % k) + k) % k;
                
                if (remainderCount.containsKey(remainder)) {
                    count += remainderCount.get(remainder);
                }
                remainderCount.put(remainder, remainderCount.getOrDefault(remainder, 0) + 1);
            }
            return count;
        }
        
        // Continuous subarray sum
        public static boolean checkSubarraySum(int[] nums, int k) {
            Map<Integer, Integer> remainderIndex = new HashMap<>();
            remainderIndex.put(0, -1);
            
            int prefixSum = 0;
            for (int i = 0; i < nums.length; i++) {
                prefixSum += nums[i];
                int remainder = k == 0 ? prefixSum : prefixSum % k;
                
                if (remainderIndex.containsKey(remainder)) {
                    if (i - remainderIndex.get(remainder) > 1) {
                        return true;
                    }
                } else {
                    remainderIndex.put(remainder, i);
                }
            }
            return false;
        }
        
        // Product of array except self
        public static int[] productExceptSelf(int[] nums) {
            int n = nums.length;
            int[] result = new int[n];
            
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
        static class NumMatrix {
            private int[][] prefix;
            
            public NumMatrix(int[][] matrix) {
                int m = matrix.length;
                int n = matrix[0].length;
                prefix = new int[m + 1][n + 1];
                
                for (int i = 1; i <= m; i++) {
                    for (int j = 1; j <= n; j++) {
                        prefix[i][j] = matrix[i - 1][j - 1] + 
                                      prefix[i - 1][j] + 
                                      prefix[i][j - 1] - 
                                      prefix[i - 1][j - 1];
                    }
                }
            }
            
            public int sumRegion(int row1, int col1, int row2, int col2) {
                return prefix[row2 + 1][col2 + 1] - 
                       prefix[row1][col2 + 1] - 
                       prefix[row2 + 1][col1] + 
                       prefix[row1][col1];
            }
        }
        
        // Count number of nice subarrays
        public static int numberOfSubarrays(int[] nums, int k) {
            Map<Integer, Integer> count = new HashMap<>();
            count.put(0, 1);
            
            int result = 0;
            int oddCount = 0;
            
            for (int num : nums) {
                if (num % 2 == 1) oddCount++;
                
                if (count.containsKey(oddCount - k)) {
                    result += count.get(oddCount - k);
                }
                count.put(oddCount, count.getOrDefault(oddCount, 0) + 1);
            }
            return result;
        }
        
        // Subarray sum with target
        public static int[] subarraySum(int[] nums, int target) {
            Map<Integer, Integer> prefixIndex = new HashMap<>();
            prefixIndex.put(0, -1);
            
            int prefixSum = 0;
            for (int i = 0; i < nums.length; i++) {
                prefixSum += nums[i];
                
                if (prefixIndex.containsKey(prefixSum - target)) {
                    return new int[]{prefixIndex.get(prefixSum - target) + 1, i};
                }
                prefixIndex.put(prefixSum, i);
            }
            return new int[0];
        }
        
        // Maximum size subarray sum equals k
        public static int maxSubArrayLen(int[] nums, int k) {
            Map<Integer, Integer> prefixIndex = new HashMap<>();
            prefixIndex.put(0, -1);
            
            int maxLen = 0;
            int prefixSum = 0;
            
            for (int i = 0; i < nums.length; i++) {
                prefixSum += nums[i];
                
                if (prefixIndex.containsKey(prefixSum - k)) {
                    maxLen = Math.max(maxLen, i - prefixIndex.get(prefixSum - k));
                }
                
                if (!prefixIndex.containsKey(prefixSum)) {
                    prefixIndex.put(prefixSum, i);
                }
            }
            return maxLen;
        }
    }
    
    // Common prefix sum problems
    public static int findMaxLength(int[] nums) {
        // TODO: Implement contiguous array
        return 0;
    }
    
    public static int subarraySum(int[] nums, int k) {
        // TODO: Implement subarray sum equals K
        return 0;
    }
    
    public static void main(String[] args) {
        // Test 1D prefix sum
        int[] nums = {1, 2, 3, 4, 5};
        int[] prefix = PrefixSum.buildPrefixSum(nums);
        System.out.println("Range sum [1, 3]: " + PrefixSum.rangeSum(prefix, 1, 3));
        
        // Test subarray sum equals K
        int[] arr = {1, 1, 1};
        int k = 2;
        System.out.println("Subarrays with sum " + k + ": " + PrefixSum.subarraySum(arr, k));
        
        // Test subarray sum divisible by K
        int[] nums2 = {4, 5, 0, -2, -3, 1};
        int k2 = 5;
        System.out.println("Subarrays divisible by " + k2 + ": " + PrefixSum.subarraysDivByK(nums2, k2));
        
        // Test product except self
        int[] nums3 = {1, 2, 3, 4};
        int[] result = PrefixSum.productExceptSelf(nums3);
        System.out.println("Product except self: " + Arrays.toString(result));
        
        // Test 2D prefix sum
        int[][] matrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
        };
        int[][] prefix2D = PrefixSum.build2DPrefixSum(matrix);
        System.out.println("2D range sum: " + PrefixSum.rangeSum2D(prefix2D, 2, 1, 4, 3));
    }
}

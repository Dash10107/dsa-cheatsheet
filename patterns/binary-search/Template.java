import java.util.*;

public class Template {
    // Standard binary search
    public static int binarySearch(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
    
    // Find first occurrence
    public static int findFirstOccurrence(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                result = mid;
                right = mid - 1; // Continue searching left
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    // Find last occurrence
    public static int findLastOccurrence(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        int result = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                result = mid;
                left = mid + 1; // Continue searching right
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return result;
    }
    
    // Search insert position
    public static int searchInsertPosition(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    
    // Search in rotated array
    public static int searchRotatedArray(int[] arr, int target) {
        int left = 0, right = arr.length - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] == target) {
                return mid;
            }
            
            // Check which half is sorted
            if (arr[left] <= arr[mid]) { // Left half is sorted
                if (arr[left] <= target && target < arr[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else { // Right half is sorted
                if (arr[mid] < target && target <= arr[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
    
    // Find minimum in rotated array
    public static int findMinimumRotated(int[] arr) {
        int left = 0, right = arr.length - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return arr[left];
    }
    
    // Find peak element
    public static int findPeakElement(int[] arr) {
        int left = 0, right = arr.length - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (arr[mid] > arr[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    
    // Search in 2D matrix
    public static boolean search2DMatrix(int[][] matrix, int target) {
        if (matrix.length == 0 || matrix[0].length == 0) return false;
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        int left = 0, right = rows * cols - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = matrix[mid / cols][mid % cols];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return false;
    }
    
    // Square root using binary search
    public static int sqrtBinarySearch(int x) {
        if (x < 2) return x;
        
        int left = 2, right = x / 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;
            
            if (square == x) {
                return mid;
            } else if (square < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
    
    // Find k closest elements
    public static List<Integer> findClosestElements(int[] arr, int k, int x) {
        int left = 0, right = arr.length - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        List<Integer> result = new ArrayList<>();
        for (int i = left; i < left + k; i++) {
            result.add(arr[i]);
        }
        return result;
    }
    
    // Common binary search problems
    public static int findKthSmallest(int[][] matrix, int k) {
        // TODO: Implement kth smallest in sorted matrix
        return 0;
    }
    
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        // TODO: Implement median of two sorted arrays
        return 0.0;
    }
    
    public static void main(String[] args) {
        // Test standard binary search
        int[] arr = {1, 3, 5, 7, 9, 11, 13};
        int target = 7;
        System.out.println("Binary search for " + target + ": " + binarySearch(arr, target));
        
        // Test first occurrence
        int[] arr2 = {1, 2, 2, 2, 3, 4, 5};
        target = 2;
        System.out.println("First occurrence of " + target + ": " + findFirstOccurrence(arr2, target));
        
        // Test last occurrence
        System.out.println("Last occurrence of " + target + ": " + findLastOccurrence(arr2, target));
        
        // Test search insert position
        int[] arr3 = {1, 3, 5, 6};
        target = 4;
        System.out.println("Insert position for " + target + ": " + searchInsertPosition(arr3, target));
        
        // Test rotated array search
        int[] rotated = {4, 5, 6, 7, 0, 1, 2};
        target = 0;
        System.out.println("Search in rotated array for " + target + ": " + searchRotatedArray(rotated, target));
        
        // Test find minimum in rotated array
        System.out.println("Minimum in rotated array: " + findMinimumRotated(rotated));
        
        // Test find peak element
        int[] peak = {1, 2, 3, 1};
        System.out.println("Peak element index: " + findPeakElement(peak));
        
        // Test 2D matrix search
        int[][] matrix = {
            {1, 4, 7, 11},
            {2, 5, 8, 12},
            {3, 6, 9, 16}
        };
        target = 5;
        System.out.println("Search in 2D matrix for " + target + ": " + search2DMatrix(matrix, target));
        
        // Test square root
        int x = 8;
        System.out.println("Square root of " + x + ": " + sqrtBinarySearch(x));
    }
}

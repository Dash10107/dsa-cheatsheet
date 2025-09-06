#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BinarySearch {
public:
    // Standard binary search
    int binarySearch(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        
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
    int findFirstOccurrence(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
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
    int findLastOccurrence(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
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
    int searchInsertPosition(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        
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
    int searchRotatedArray(vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        
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
    int findMinimumRotated(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
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
    int findPeakElement(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        
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
    bool search2DMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
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
    int sqrtBinarySearch(int x) {
        if (x < 2) return x;
        
        int left = 2, right = x / 2;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long)mid * mid;
            
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
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size() - k;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};

// Common binary search problems
int findKthSmallest(vector<vector<int>>& matrix, int k) {
    // TODO: Implement kth smallest in sorted matrix
    return 0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // TODO: Implement median of two sorted arrays
    return 0.0;
}

int main() {
    BinarySearch bs;
    
    // Test standard binary search
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13};
    int target = 7;
    cout << "Binary search for " << target << ": " << bs.binarySearch(arr, target) << endl;
    
    // Test first occurrence
    vector<int> arr2 = {1, 2, 2, 2, 3, 4, 5};
    target = 2;
    cout << "First occurrence of " << target << ": " << bs.findFirstOccurrence(arr2, target) << endl;
    
    // Test last occurrence
    cout << "Last occurrence of " << target << ": " << bs.findLastOccurrence(arr2, target) << endl;
    
    // Test search insert position
    vector<int> arr3 = {1, 3, 5, 6};
    target = 4;
    cout << "Insert position for " << target << ": " << bs.searchInsertPosition(arr3, target) << endl;
    
    // Test rotated array search
    vector<int> rotated = {4, 5, 6, 7, 0, 1, 2};
    target = 0;
    cout << "Search in rotated array for " << target << ": " << bs.searchRotatedArray(rotated, target) << endl;
    
    // Test find minimum in rotated array
    cout << "Minimum in rotated array: " << bs.findMinimumRotated(rotated) << endl;
    
    // Test find peak element
    vector<int> peak = {1, 2, 3, 1};
    cout << "Peak element index: " << bs.findPeakElement(peak) << endl;
    
    // Test 2D matrix search
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16}
    };
    target = 5;
    cout << "Search in 2D matrix for " << target << ": " << (bs.search2DMatrix(matrix, target) ? "Found" : "Not found") << endl;
    
    // Test square root
    int x = 8;
    cout << "Square root of " << x << ": " << bs.sqrtBinarySearch(x) << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merge Sort
vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) return arr;
    int mid = arr.size() / 2;
    vector<int> left(arr.begin(), arr.begin() + mid);
    vector<int> right(arr.begin() + mid, arr.end());
    return merge(mergeSort(left), mergeSort(right));
}
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) result.push_back(left[i++]);
        else result.push_back(right[j++]);
    }
    while (i < left.size()) result.push_back(left[i++]);
    while (j < right.size()) result.push_back(right[j++]);
    return result;
}

// Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Maximum Subarray Sum (Divide and Conquer)
int maxSubArraySumHelper(const vector<int>& arr, int l, int r, int& total, int& prefix, int& suffix) {
    if (l == r) {
        total = prefix = suffix = arr[l];
        return arr[l];
    }
    int m = (l + r) / 2;
    int l_total, l_prefix, l_suffix;
    int r_total, r_prefix, r_suffix;
    int l_max = maxSubArraySumHelper(arr, l, m, l_total, l_prefix, l_suffix);
    int r_max = maxSubArraySumHelper(arr, m + 1, r, r_total, r_prefix, r_suffix);
    total = l_total + r_total;
    prefix = max(l_prefix, l_total + r_prefix);
    suffix = max(r_suffix, r_total + l_suffix);
    return max({l_max, r_max, l_suffix + r_prefix});
}
int maxSubArraySum(const vector<int>& arr) {
    if (arr.empty()) return 0;
    int total, prefix, suffix;
    return maxSubArraySumHelper(arr, 0, arr.size() - 1, total, prefix, suffix);
}

int main() {
    vector<int> arr = {3, 5, 1, 6, 2, 7, 4};
    vector<int> sorted = mergeSort(arr);
    cout << "Merge sort: ";
    for (int x : sorted) cout << x << ' ';
    cout << endl;
    vector<int> arr2 = {3, 5, 1, 6, 2, 7, 4};
    quickSort(arr2, 0, arr2.size() - 1);
    cout << "Quick sort: ";
    for (int x : arr2) cout << x << ' ';
    cout << endl;
    vector<int> arr3 = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max subarray sum: " << maxSubArraySum(arr3) << endl;
    return 0;
}

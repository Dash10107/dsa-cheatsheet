import java.util.*;

public class Template {
    // Merge Sort
    public static int[] mergeSort(int[] arr) {
        if (arr.length <= 1) return arr;
        int mid = arr.length / 2;
        int[] left = Arrays.copyOfRange(arr, 0, mid);
        int[] right = Arrays.copyOfRange(arr, mid, arr.length);
        return merge(mergeSort(left), mergeSort(right));
    }
    private static int[] merge(int[] left, int[] right) {
        int[] result = new int[left.length + right.length];
        int i = 0, j = 0, k = 0;
        while (i < left.length && j < right.length) {
            if (left[i] < right[j]) result[k++] = left[i++];
            else result[k++] = right[j++];
        }
        while (i < left.length) result[k++] = left[i++];
        while (j < right.length) result[k++] = right[j++];
        return result;
    }

    // Quick Sort
    public static int[] quickSort(int[] arr) {
        quickSortHelper(arr, 0, arr.length - 1);
        return arr;
    }
    private static void quickSortHelper(int[] arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSortHelper(arr, low, pi - 1);
            quickSortHelper(arr, pi + 1, high);
        }
    }
    private static int partition(int[] arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }
        int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        return i + 1;
    }

    // Maximum Subarray Sum (Divide and Conquer)
    public static int maxSubArraySum(int[] arr) {
        return maxSubArrayHelper(arr, 0, arr.length - 1)[1];
    }
    // Returns [total, maxSum, prefix, suffix]
    private static int[] maxSubArrayHelper(int[] arr, int l, int r) {
        if (l == r) return new int[]{arr[l], arr[l], arr[l], arr[l]};
        int m = (l + r) / 2;
        int[] left = maxSubArrayHelper(arr, l, m);
        int[] right = maxSubArrayHelper(arr, m + 1, r);
        int total = left[0] + right[0];
        int maxSum = Math.max(Math.max(left[1], right[1]), left[3] + right[2]);
        int prefix = Math.max(left[2], left[0] + right[2]);
        int suffix = Math.max(right[3], right[0] + left[3]);
        return new int[]{total, maxSum, prefix, suffix};
    }

    public static void main(String[] args) {
        int[] arr = {3, 5, 1, 6, 2, 7, 4};
        System.out.println("Merge sort: " + Arrays.toString(mergeSort(arr)));
        int[] arr2 = {3, 5, 1, 6, 2, 7, 4};
        System.out.println("Quick sort: " + Arrays.toString(quickSort(arr2)));
        int[] arr3 = {-2,1,-3,4,-1,2,1,-5,4};
        System.out.println("Max subarray sum: " + maxSubArraySum(arr3));
    }
}

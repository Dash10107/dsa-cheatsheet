import java.util.*;

public class Template {
    static class Array {
        private int[] data;
        private int size;
        private int capacity;
        
        public Array(int cap) {
            capacity = cap;
            data = new int[capacity];
            size = 0;
        }
        
        public Array() {
            this(10);
        }
        
        public int get(int index) {
            if (index >= 0 && index < size) {
                return data[index];
            }
            return -1; // or throw exception
        }
        
        public void set(int index, int value) {
            if (index >= 0 && index < size) {
                data[index] = value;
            }
        }
        
        public void append(int value) {
            if (size < capacity) {
                data[size++] = value;
            }
        }
        
        public void insert(int index, int value) {
            if (index >= 0 && index <= size && size < capacity) {
                for (int i = size; i > index; i--) {
                    data[i] = data[i - 1];
                }
                data[index] = value;
                size++;
            }
        }
        
        public void remove(int value) {
            for (int i = 0; i < size; i++) {
                if (data[i] == value) {
                    for (int j = i; j < size - 1; j++) {
                        data[j] = data[j + 1];
                    }
                    size--;
                    break;
                }
            }
        }
        
        public int pop(int index) {
            if (index == -1) index = size - 1;
            if (index >= 0 && index < size) {
                int val = data[index];
                for (int i = index; i < size - 1; i++) {
                    data[i] = data[i + 1];
                }
                size--;
                return val;
            }
            return -1;
        }
        
        public int size() {
            return size;
        }
        
        public void print() {
            for (int i = 0; i < size; i++) {
                System.out.print(data[i] + " ");
            }
            System.out.println();
        }
    }
    
    // Common array operations
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (map.containsKey(complement)) {
                return new int[]{map.get(complement), i};
            }
            map.put(nums[i], i);
        }
        return new int[0];
    }
    
    public static int maxSubarray(int[] nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currSum = Math.max(nums[i], currSum + nums[i]);
            maxSum = Math.max(maxSum, currSum);
        }
        return maxSum;
    }
    
    public static int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] output = new int[n];
        int left = 1;
        for (int i = 0; i < n; i++) {
            output[i] = left;
            left *= nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }
        return output;
    }
    
    public static void main(String[] args) {
        Array arr = new Array(5);
        arr.append(1);
        arr.append(2);
        arr.append(3);
        arr.append(4);
        arr.append(5);
        
        arr.print();
        System.out.println("Size: " + arr.size());
        System.out.println("Element at index 2: " + arr.get(2));
    }
}

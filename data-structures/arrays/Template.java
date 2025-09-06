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
        // TODO: Implement two sum
        return new int[0];
    }
    
    public static int maxSubarray(int[] nums) {
        // TODO: Implement Kadane's algorithm
        return 0;
    }
    
    public static int[] productExceptSelf(int[] nums) {
        // TODO: Implement product except self
        return new int[0];
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

import java.util.*;

public class Template {
    static class MinHeap {
        private List<Integer> heap;
        
        public MinHeap() {
            heap = new ArrayList<>();
        }
        
        private void heapifyUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap.get(parent) <= heap.get(index)) break;
                Collections.swap(heap, parent, index);
                index = parent;
            }
        }
        
        private void heapifyDown(int index) {
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int smallest = index;
                
                if (left < heap.size() && heap.get(left) < heap.get(smallest)) {
                    smallest = left;
                }
                if (right < heap.size() && heap.get(right) < heap.get(smallest)) {
                    smallest = right;
                }
                
                if (smallest == index) break;
                Collections.swap(heap, index, smallest);
                index = smallest;
            }
        }
        
        public void push(int val) {
            heap.add(val);
            heapifyUp(heap.size() - 1);
        }
        
        public int pop() {
            if (heap.isEmpty()) return -1;
            int min = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            if (!heap.isEmpty()) heapifyDown(0);
            return min;
        }
        
        public int peek() {
            return heap.isEmpty() ? -1 : heap.get(0);
        }
        
        public int size() {
            return heap.size();
        }
        
        public boolean empty() {
            return heap.isEmpty();
        }
    }
    
    static class MaxHeap {
        private List<Integer> heap;
        
        public MaxHeap() {
            heap = new ArrayList<>();
        }
        
        private void heapifyUp(int index) {
            while (index > 0) {
                int parent = (index - 1) / 2;
                if (heap.get(parent) >= heap.get(index)) break;
                Collections.swap(heap, parent, index);
                index = parent;
            }
        }
        
        private void heapifyDown(int index) {
            while (true) {
                int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largest = index;
                
                if (left < heap.size() && heap.get(left) > heap.get(largest)) {
                    largest = left;
                }
                if (right < heap.size() && heap.get(right) > heap.get(largest)) {
                    largest = right;
                }
                
                if (largest == index) break;
                Collections.swap(heap, index, largest);
                index = largest;
            }
        }
        
        public void push(int val) {
            heap.add(val);
            heapifyUp(heap.size() - 1);
        }
        
        public int pop() {
            if (heap.isEmpty()) return -1;
            int max = heap.get(0);
            heap.set(0, heap.get(heap.size() - 1));
            heap.remove(heap.size() - 1);
            if (!heap.isEmpty()) heapifyDown(0);
            return max;
        }
        
        public int peek() {
            return heap.isEmpty() ? -1 : heap.get(0);
        }
        
        public int size() {
            return heap.size();
        }
        
        public boolean empty() {
            return heap.isEmpty();
        }
    }
    
    static class MedianFinder {
        private PriorityQueue<Integer> small; // max heap
        private PriorityQueue<Integer> large; // min heap
        
        public MedianFinder() {
            small = new PriorityQueue<>(Collections.reverseOrder());
            large = new PriorityQueue<>();
        }
        
        public void addNum(int num) {
            if (small.size() == large.size()) {
                small.offer(num);
                large.offer(small.poll());
            } else {
                large.offer(num);
                small.offer(large.poll());
            }
        }
        
        public double findMedian() {
            if (small.size() == large.size()) {
                return (small.peek() + large.peek()) / 2.0;
            } else {
                return large.peek();
            }
        }
    }
    
    // Common heap operations
    public static int findKthLargest(int[] nums, int k) {
        // TODO: Implement kth largest element
        return 0;
    }
    
    public static int[] mergeSortedArrays(int[][] arrays) {
        // TODO: Implement merge k sorted arrays
        return new int[0];
    }
    
    public static int[] topKFrequent(int[] nums, int k) {
        // TODO: Implement top k frequent elements
        return new int[0];
    }
    
    public static int kthSmallestInMatrix(int[][] matrix, int k) {
        // TODO: Implement kth smallest in sorted matrix
        return 0;
    }
    
    public static int[] slidingWindowMaximum(int[] nums, int k) {
        // TODO: Implement sliding window maximum
        return new int[0];
    }
    
    public static void main(String[] args) {
        MinHeap minHeap = new MinHeap();
        minHeap.push(3);
        minHeap.push(1);
        minHeap.push(4);
        minHeap.push(1);
        minHeap.push(5);
        
        System.out.print("Min heap: ");
        while (!minHeap.empty()) {
            System.out.print(minHeap.pop() + " ");
        }
        System.out.println();
        
        MaxHeap maxHeap = new MaxHeap();
        maxHeap.push(3);
        maxHeap.push(1);
        maxHeap.push(4);
        maxHeap.push(1);
        maxHeap.push(5);
        
        System.out.print("Max heap: ");
        while (!maxHeap.empty()) {
            System.out.print(maxHeap.pop() + " ");
        }
        System.out.println();
    }
}

import java.util.*;

public class Template {
    static class MonotonicQueue {
        private Deque<Integer> deque;
        
        public MonotonicQueue() {
            deque = new ArrayDeque<>();
        }
        
        public void push(int val) {
            while (!deque.isEmpty() && deque.peekLast() < val) {
                deque.pollLast();
            }
            deque.offerLast(val);
        }
        
        public void pop(int val) {
            if (!deque.isEmpty() && deque.peekFirst() == val) {
                deque.pollFirst();
            }
        }
        
        public int max() {
            return deque.peekFirst();
        }
        
        public boolean empty() {
            return deque.isEmpty();
        }
        
        public int size() {
            return deque.size();
        }
    }
    
    static class MonotonicStack {
        private Deque<Integer> stack;
        
        public MonotonicStack() {
            stack = new ArrayDeque<>();
        }
        
        public void push(int val) {
            while (!stack.isEmpty() && stack.peek() < val) {
                stack.pop();
            }
            stack.push(val);
        }
        
        public void pop() {
            if (!stack.isEmpty()) {
                stack.pop();
            }
        }
        
        public int top() {
            return stack.isEmpty() ? -1 : stack.peek();
        }
        
        public boolean empty() {
            return stack.isEmpty();
        }
        
        public int size() {
            return stack.size();
        }
    }
    
    static class MonotonicOperations {
        // Sliding window maximum
        public static int[] maxSlidingWindow(int[] nums, int k) {
            MonotonicQueue mq = new MonotonicQueue();
            List<Integer> result = new ArrayList<>();
            
            for (int i = 0; i < nums.length; i++) {
                mq.push(nums[i]);
                
                if (i >= k - 1) {
                    result.add(mq.max());
                    mq.pop(nums[i - k + 1]);
                }
            }
            return result.stream().mapToInt(i -> i).toArray();
        }
        
        // Next greater element
        public static int[] nextGreaterElement(int[] nums) {
            int n = nums.length;
            int[] result = new int[n];
            Arrays.fill(result, -1);
            Deque<Integer> stack = new ArrayDeque<>();
            
            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
                    result[stack.pop()] = nums[i];
                }
                stack.push(i);
            }
            return result;
        }
        
        // Next smaller element
        public static int[] nextSmallerElement(int[] nums) {
            int n = nums.length;
            int[] result = new int[n];
            Arrays.fill(result, -1);
            Deque<Integer> stack = new ArrayDeque<>();
            
            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                    result[stack.pop()] = nums[i];
                }
                stack.push(i);
            }
            return result;
        }
        
        // Previous greater element
        public static int[] previousGreaterElement(int[] nums) {
            int n = nums.length;
            int[] result = new int[n];
            Arrays.fill(result, -1);
            Deque<Integer> stack = new ArrayDeque<>();
            
            for (int i = n - 1; i >= 0; i--) {
                while (!stack.isEmpty() && nums[stack.peek()] < nums[i]) {
                    result[stack.pop()] = nums[i];
                }
                stack.push(i);
            }
            return result;
        }
        
        // Previous smaller element
        public static int[] previousSmallerElement(int[] nums) {
            int n = nums.length;
            int[] result = new int[n];
            Arrays.fill(result, -1);
            Deque<Integer> stack = new ArrayDeque<>();
            
            for (int i = n - 1; i >= 0; i--) {
                while (!stack.isEmpty() && nums[stack.peek()] > nums[i]) {
                    result[stack.pop()] = nums[i];
                }
                stack.push(i);
            }
            return result;
        }
        
        // Largest rectangle in histogram
        public static int largestRectangleArea(int[] heights) {
            Deque<Integer> stack = new ArrayDeque<>();
            int maxArea = 0;
            int n = heights.length;
            
            for (int i = 0; i <= n; i++) {
                int h = (i == n) ? 0 : heights[i];
                
                while (!stack.isEmpty() && heights[stack.peek()] > h) {
                    int height = heights[stack.pop()];
                    int width = stack.isEmpty() ? i : i - stack.peek() - 1;
                    maxArea = Math.max(maxArea, height * width);
                }
                stack.push(i);
            }
            return maxArea;
        }
        
        // Trapping rain water
        public static int trap(int[] height) {
            if (height.length == 0) return 0;
            
            int left = 0, right = height.length - 1;
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
        
        // Daily temperatures
        public static int[] dailyTemperatures(int[] temperatures) {
            int n = temperatures.length;
            int[] result = new int[n];
            Deque<Integer> stack = new ArrayDeque<>();
            
            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && temperatures[stack.peek()] < temperatures[i]) {
                    int prevIndex = stack.pop();
                    result[prevIndex] = i - prevIndex;
                }
                stack.push(i);
            }
            return result;
        }
        
        // Stock span problem
        public static int[] stockSpan(int[] prices) {
            int n = prices.length;
            int[] span = new int[n];
            Arrays.fill(span, 1);
            Deque<Integer> stack = new ArrayDeque<>();
            
            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && prices[stack.peek()] <= prices[i]) {
                    stack.pop();
                }
                span[i] = stack.isEmpty() ? i + 1 : i - stack.peek();
                stack.push(i);
            }
            return span;
        }
        
        // Sum of subarray minimums
        public static int sumSubarrayMins(int[] arr) {
            int n = arr.length;
            int[] left = new int[n];
            int[] right = new int[n];
            Deque<Integer> stack = new ArrayDeque<>();
            
            // Find previous smaller element
            for (int i = 0; i < n; i++) {
                while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                    stack.pop();
                }
                left[i] = stack.isEmpty() ? -1 : stack.peek();
                stack.push(i);
            }
            
            stack.clear();
            
            // Find next smaller element
            for (int i = n - 1; i >= 0; i--) {
                while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                    stack.pop();
                }
                right[i] = stack.isEmpty() ? n : stack.peek();
                stack.push(i);
            }
            
            long result = 0;
            for (int i = 0; i < n; i++) {
                result = (result + (long) arr[i] * (i - left[i]) * (right[i] - i)) % 1000000007;
            }
            return (int) result;
        }
    }
    
    // Common monotonic problems
    public static int[] sumOfSubarrayMinimums(int[] arr) {
        // TODO: Implement sum of subarray minimums
        return new int[0];
    }
    
    public static int sumSubarrayMins(int[] arr) {
        // TODO: Implement sum subarray mins
        return 0;
    }
    
    public static void main(String[] args) {
        // Test sliding window maximum
        int[] nums = {1, 3, -1, -3, 5, 3, 6, 7};
        int k = 3;
        int[] result = MonotonicOperations.maxSlidingWindow(nums, k);
        System.out.println("Sliding window maximum: " + Arrays.toString(result));
        
        // Test next greater element
        int[] arr = {4, 5, 2, 10, 8};
        int[] nge = MonotonicOperations.nextGreaterElement(arr);
        System.out.println("Next greater elements: " + Arrays.toString(nge));
        
        // Test largest rectangle
        int[] heights = {2, 1, 5, 6, 2, 3};
        System.out.println("Largest rectangle area: " + MonotonicOperations.largestRectangleArea(heights));
        
        // Test trapping rain water
        int[] water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        System.out.println("Trapped water: " + MonotonicOperations.trap(water));
        
        // Test daily temperatures
        int[] temps = {73, 74, 75, 71, 69, 72, 76, 73};
        int[] days = MonotonicOperations.dailyTemperatures(temps);
        System.out.println("Days to warmer temperature: " + Arrays.toString(days));
    }
}

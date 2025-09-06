import java.util.*;

public class Template {
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
            
            Deque<Integer> stack = new ArrayDeque<>();
            int water = 0;
            
            for (int i = 0; i < height.length; i++) {
                while (!stack.isEmpty() && height[stack.peek()] < height[i]) {
                    int top = stack.pop();
                    
                    if (stack.isEmpty()) break;
                    
                    int distance = i - stack.peek() - 1;
                    int boundedHeight = Math.min(height[i], height[stack.peek()]) - height[top];
                    water += distance * boundedHeight;
                }
                stack.push(i);
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
        
        // Online stock span
        static class StockSpanner {
            private Deque<int[]> stack; // {price, span}
            
            public StockSpanner() {
                stack = new ArrayDeque<>();
            }
            
            public int next(int price) {
                int span = 1;
                while (!stack.isEmpty() && stack.peek()[0] <= price) {
                    span += stack.pop()[1];
                }
                stack.push(new int[]{price, span});
                return span;
            }
        }
        
        // Remove duplicate letters
        public static String removeDuplicateLetters(String s) {
            Deque<Character> stack = new ArrayDeque<>();
            boolean[] visited = new boolean[26];
            int[] count = new int[26];
            
            for (char c : s.toCharArray()) {
                count[c - 'a']++;
            }
            
            for (char c : s.toCharArray()) {
                count[c - 'a']--;
                if (visited[c - 'a']) continue;
                
                while (!stack.isEmpty() && stack.peek() > c && count[stack.peek() - 'a'] > 0) {
                    visited[stack.pop() - 'a'] = false;
                }
                
                stack.push(c);
                visited[c - 'a'] = true;
            }
            
            StringBuilder result = new StringBuilder();
            while (!stack.isEmpty()) {
                result.append(stack.pop());
            }
            return result.reverse().toString();
        }
    }
    
    // Common monotonic stack problems
    public static int[] nextGreaterElements(int[] nums) {
        // TODO: Implement next greater elements II
        return new int[0];
    }
    
    public static int maximalRectangle(char[][] matrix) {
        // TODO: Implement maximal rectangle
        return 0;
    }
    
    public static void main(String[] args) {
        // Test next greater element
        int[] nums = {4, 5, 2, 10, 8};
        int[] nge = MonotonicOperations.nextGreaterElement(nums);
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
        
        // Test stock span
        int[] prices = {100, 80, 60, 70, 60, 75, 85};
        int[] spans = MonotonicOperations.stockSpan(prices);
        System.out.println("Stock spans: " + Arrays.toString(spans));
        
        // Test sum of subarray minimums
        int[] arr = {3, 1, 2, 4};
        System.out.println("Sum of subarray minimums: " + MonotonicOperations.sumSubarrayMins(arr));
    }
}

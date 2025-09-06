import java.util.*;

public class Template {
    static class Stack {
        private int[] arr;
        private int top;
        private int capacity;
        
        public Stack(int cap) {
            capacity = cap;
            arr = new int[capacity];
            top = -1;
        }
        
        public Stack() {
            this(1000);
        }
        
        public void push(int val) {
            if (isFull()) {
                System.out.println("Stack overflow!");
                return;
            }
            arr[++top] = val;
        }
        
        public int pop() {
            if (isEmpty()) {
                System.out.println("Stack underflow!");
                return -1;
            }
            return arr[top--];
        }
        
        public int peek() {
            if (isEmpty()) {
                System.out.println("Stack is empty!");
                return -1;
            }
            return arr[top];
        }
        
        public boolean isEmpty() {
            return top == -1;
        }
        
        public boolean isFull() {
            return top == capacity - 1;
        }
        
        public int size() {
            return top + 1;
        }
        
        public void print() {
            if (isEmpty()) {
                System.out.println("Stack is empty!");
                return;
            }
            
            System.out.print("Stack: ");
            for (int i = 0; i <= top; i++) {
                System.out.print(arr[i] + " ");
            }
            System.out.println();
        }
    }
    
    // Common stack operations
    public static boolean isValidParentheses(String s) {
        // TODO: Implement valid parentheses
        return false;
    }
    
    public static int[] nextGreaterElement(int[] nums) {
        // TODO: Implement next greater element
        return new int[0];
    }
    
    public static int largestRectangleArea(int[] heights) {
        // TODO: Implement largest rectangle in histogram
        return 0;
    }
    
    public static int[] dailyTemperatures(int[] temperatures) {
        // TODO: Implement daily temperatures
        return new int[0];
    }
    
    public static String removeDuplicates(String s) {
        // TODO: Implement remove adjacent duplicates
        return "";
    }
    
    public static int evaluatePostfix(String expression) {
        // TODO: Implement postfix evaluation
        return 0;
    }
    
    public static int[] asteroidCollision(int[] asteroids) {
        // TODO: Implement asteroid collision
        return new int[0];
    }
    
    public static void main(String[] args) {
        Stack st = new Stack(5);
        st.push(1);
        st.push(2);
        st.push(3);
        st.print();
        
        System.out.println("Peek: " + st.peek());
        System.out.println("Pop: " + st.pop());
        st.print();
        
        System.out.println("Size: " + st.size());
        System.out.println("Is empty: " + st.isEmpty());
    }
}

import java.util.*;

public class Template {
    static class Queue {
        private int[] arr;
        private int front;
        private int rear;
        private int capacity;
        private int size;
        
        public Queue(int cap) {
            capacity = cap;
            arr = new int[capacity];
            front = 0;
            rear = -1;
            size = 0;
        }
        
        public Queue() {
            this(1000);
        }
        
        public void enqueue(int val) {
            if (isFull()) {
                System.out.println("Queue is full!");
                return;
            }
            rear = (rear + 1) % capacity;
            arr[rear] = val;
            size++;
        }
        
        public int dequeue() {
            if (isEmpty()) {
                System.out.println("Queue is empty!");
                return -1;
            }
            int val = arr[front];
            front = (front + 1) % capacity;
            size--;
            return val;
        }
        
        public int peek() {
            if (isEmpty()) {
                System.out.println("Queue is empty!");
                return -1;
            }
            return arr[front];
        }
        
        public boolean isEmpty() {
            return size == 0;
        }
        
        public boolean isFull() {
            return size == capacity;
        }
        
        public int getSize() {
            return size;
        }
        
        public void print() {
            if (isEmpty()) {
                System.out.println("Queue is empty!");
                return;
            }
            
            System.out.print("Queue: ");
            for (int i = 0; i < size; i++) {
                int index = (front + i) % capacity;
                System.out.print(arr[index] + " ");
            }
            System.out.println();
        }
    }
    
    static class Deque {
        private int[] arr;
        private int front;
        private int rear;
        private int capacity;
        private int size;
        
        public Deque(int cap) {
            capacity = cap;
            arr = new int[capacity];
            front = -1;
            rear = 0;
            size = 0;
        }
        
        public Deque() {
            this(1000);
        }
        
        public void addFront(int val) {
            if (isFull()) {
                System.out.println("Deque is full!");
                return;
            }
            if (front == -1) {
                front = 0;
                rear = 0;
            } else if (front == 0) {
                front = capacity - 1;
            } else {
                front--;
            }
            arr[front] = val;
            size++;
        }
        
        public void addRear(int val) {
            if (isFull()) {
                System.out.println("Deque is full!");
                return;
            }
            if (front == -1) {
                front = 0;
                rear = 0;
            } else if (rear == capacity - 1) {
                rear = 0;
            } else {
                rear++;
            }
            arr[rear] = val;
            size++;
        }
        
        public int removeFront() {
            if (isEmpty()) {
                System.out.println("Deque is empty!");
                return -1;
            }
            int val = arr[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else if (front == capacity - 1) {
                front = 0;
            } else {
                front++;
            }
            size--;
            return val;
        }
        
        public int removeRear() {
            if (isEmpty()) {
                System.out.println("Deque is empty!");
                return -1;
            }
            int val = arr[rear];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else if (rear == 0) {
                rear = capacity - 1;
            } else {
                rear--;
            }
            size--;
            return val;
        }
        
        public boolean isEmpty() {
            return size == 0;
        }
        
        public boolean isFull() {
            return size == capacity;
        }
        
        public int getSize() {
            return size;
        }
    }
    
    // Common queue operations
    public static int[] slidingWindowMaximum(int[] nums, int k) {
        if (nums == null || k == 0) return new int[0];
        int n = nums.length;
        int[] res = new int[n - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!dq.isEmpty() && dq.peekFirst() <= i - k) dq.pollFirst();
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) dq.pollLast();
            dq.offerLast(i);
            if (i >= k - 1) res[i - k + 1] = nums[dq.peekFirst()];
        }
        return res;
    }
    
    public static int firstNonRepeatingChar(String s) {
        int[] count = new int[256];
        Queue<Character> q = new LinkedList<>();
        for (char c : s.toCharArray()) {
            count[c]++;
            q.offer(c);
            while (!q.isEmpty() && count[q.peek()] > 1) q.poll();
        }
        return q.isEmpty() ? -1 : s.indexOf(q.peek());
    }
    
    public static int[] maxSlidingWindow(int[] nums, int k) {
    return slidingWindowMaximum(nums, k);
    }
    
    public static void main(String[] args) {
        Queue q = new Queue(5);
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        q.print();
        
        System.out.println("Dequeued: " + q.dequeue());
        System.out.println("Peek: " + q.peek());
        q.print();
        
        Deque dq = new Deque(5);
        dq.addFront(1);
        dq.addRear(2);
        dq.addFront(3);
        dq.addRear(4);
        
        System.out.println("Deque size: " + dq.getSize());
        System.out.println("Remove front: " + dq.removeFront());
        System.out.println("Remove rear: " + dq.removeRear());
    }
}

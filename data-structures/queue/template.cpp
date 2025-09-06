#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;
    
public:
    Queue(int cap = 1000) : capacity(cap), front(0), rear(-1), size(0) {
        arr = new int[capacity];
    }
    
    ~Queue() {
        delete[] arr;
    }
    
    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = val;
        size++;
    }
    
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % capacity;
        size--;
        return val;
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    int getSize() {
        return size;
    }
    
    void print() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        
        cout << "Queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % capacity;
            cout << arr[index] << " ";
        }
        cout << endl;
    }
};

class Deque {
private:
    int* arr;
    int front;
    int rear;
    int capacity;
    int size;
    
public:
    Deque(int cap = 1000) : capacity(cap), front(-1), rear(0), size(0) {
        arr = new int[capacity];
    }
    
    ~Deque() {
        delete[] arr;
    }
    
    void addFront(int val) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
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
    
    void addRear(int val) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
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
    
    int removeFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
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
    
    int removeRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
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
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
    
    int getSize() {
        return size;
    }
};

// Common queue operations
vector<int> slidingWindowMaximum(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k - 1) res.push_back(nums[dq.front()]);
    }
    return res;
}

int firstNonRepeatingChar(string s) {
    vector<int> count(256, 0);
    queue<char> q;
    for (char c : s) {
        count[c]++;
        q.push(c);
        while (!q.empty() && count[q.front()] > 1) q.pop();
    }
    return q.empty() ? -1 : s.find(q.front());
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    return slidingWindowMaximum(nums, k);
}

int main() {
    Queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Peek: " << q.peek() << endl;
    q.print();
    
    Deque dq(5);
    dq.addFront(1);
    dq.addRear(2);
    dq.addFront(3);
    dq.addRear(4);
    
    cout << "Deque size: " << dq.getSize() << endl;
    cout << "Remove front: " << dq.removeFront() << endl;
    cout << "Remove rear: " << dq.removeRear() << endl;
    
    return 0;
}

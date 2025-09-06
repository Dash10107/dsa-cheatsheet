#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;
    
public:
    Stack(int cap = 1000) : capacity(cap), top(-1) {
        arr = new int[capacity];
    }
    
    ~Stack() {
        delete[] arr;
    }
    
    void push(int val) {
        if (isFull()) {
            cout << "Stack overflow!" << endl;
            return;
        }
        arr[++top] = val;
    }
    
    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow!" << endl;
            return -1;
        }
        return arr[top--];
    }
    
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[top];
    }
    
    bool isEmpty() {
        return top == -1;
    }
    
    bool isFull() {
        return top == capacity - 1;
    }
    
    int size() {
        return top + 1;
    }
    
    void print() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Common stack operations
bool isValidParentheses(string s) {
    stack<char> st;
    unordered_map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
    for (char c : s) {
        if (mp.count(c)) {
            if (st.empty() || st.top() != mp[c]) return false;
            st.pop();
        } else if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
    }
    return st.empty();
}

vector<int> nextGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() <= nums[i]) st.pop();
        if (!st.empty()) res[i] = st.top();
        st.push(nums[i]);
    }
    return res;
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0, n = heights.size();
    for (int i = 0; i <= n; ++i) {
        int h = (i == n) ? 0 : heights[i];
        while (!st.empty() && h < heights[st.top()]) {
            int height = heights[st.top()]; st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        st.push(i);
    }
    return maxArea;
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0);
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int idx = st.top(); st.pop();
            res[idx] = i - idx;
        }
        st.push(i);
    }
    return res;
}

string removeDuplicates(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    string res;
    while (!st.empty()) { res = st.top() + res; st.pop(); }
    return res;
}

int evaluatePostfix(string expression) {
    stack<int> st;
    string token;
    istringstream iss(expression);
    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);
        } else {
            st.push(stoi(token));
        }
    }
    return st.empty() ? 0 : st.top();
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;
    for (int a : asteroids) {
        bool alive = true;
        while (alive && a < 0 && !st.empty() && st.top() > 0) {
            if (st.top() < -a) st.pop();
            else if (st.top() == -a) { st.pop(); alive = false; }
            else { alive = false; }
        }
        if (alive) st.push(a);
    }
    vector<int> res(st.size());
    for (int i = st.size() - 1; i >= 0; --i) {
        res[i] = st.top(); st.pop();
    }
    return res;
}

int main() {
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.print();
    
    cout << "Peek: " << st.peek() << endl;
    cout << "Pop: " << st.pop() << endl;
    st.print();
    
    cout << "Size: " << st.size() << endl;
    cout << "Is empty: " << (st.isEmpty() ? "Yes" : "No") << endl;
    
    return 0;
}

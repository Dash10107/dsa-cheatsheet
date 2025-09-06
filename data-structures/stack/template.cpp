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
    // TODO: Implement valid parentheses
    return false;
}

vector<int> nextGreaterElement(vector<int>& nums) {
    // TODO: Implement next greater element
    return {};
}

int largestRectangleArea(vector<int>& heights) {
    // TODO: Implement largest rectangle in histogram
    return 0;
}

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // TODO: Implement daily temperatures
    return {};
}

string removeDuplicates(string s) {
    // TODO: Implement remove adjacent duplicates
    return "";
}

int evaluatePostfix(string expression) {
    // TODO: Implement postfix evaluation
    return 0;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
    // TODO: Implement asteroid collision
    return {};
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

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;
    
public:
    LinkedList() : head(nullptr) {}
    
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }
    
    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        
        ListNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    
    void insertAtPosition(int val, int pos) {
        if (pos == 0) {
            insertAtHead(val);
            return;
        }
        
        ListNode* newNode = new ListNode(val);
        ListNode* curr = head;
        for (int i = 0; i < pos - 1 && curr; i++) {
            curr = curr->next;
        }
        
        if (curr) {
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    
    void deleteAtHead() {
        if (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void deleteAtTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        
        ListNode* curr = head;
        while (curr->next->next) {
            curr = curr->next;
        }
        delete curr->next;
        curr->next = nullptr;
    }
    
    void deleteByValue(int val) {
        if (!head) return;
        if (head->val == val) {
            deleteAtHead();
            return;
        }
        
        ListNode* curr = head;
        while (curr->next && curr->next->val != val) {
            curr = curr->next;
        }
        
        if (curr->next) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
    }
    
    bool search(int val) {
        ListNode* curr = head;
        while (curr) {
            if (curr->val == val) return true;
            curr = curr->next;
        }
        return false;
    }
    
    int size() {
        int count = 0;
        ListNode* curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        return count;
    }
    
    void print() {
        ListNode* curr = head;
        while (curr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
    
    void reverse() {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    
    bool hasCycle() {
        if (!head || !head->next) return false;
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast && fast->next) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
    
    ListNode* findMiddle() {
        if (!head) return nullptr;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

// Common linked list operations
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            curr->next = l1;
            l1 = l1->next;
        } else {
            curr->next = l2;
            l2 = l2->next;
        }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;
    for (int i = 0; i < n; ++i) {
        if (!fast->next) return head;
        fast = fast->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* toDelete = slow->next;
    if (toDelete) slow->next = toDelete->next;
    delete toDelete;
    return dummy.next;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = v1 + v2 + carry;
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    return dummy.next;
}

ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            ListNode* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }
    return nullptr;
}

int main() {
    LinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    
    cout << "Original list: ";
    list.print();
    
    cout << "Size: " << list.size() << endl;
    cout << "Search 3: " << (list.search(3) ? "Found" : "Not found") << endl;
    
    list.reverse();
    cout << "Reversed list: ";
    list.print();
    
    ListNode* middle = list.findMiddle();
    if (middle) {
        cout << "Middle element: " << middle->val << endl;
    }
    
    return 0;
}

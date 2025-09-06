import java.util.*;

public class Template {
    static class ListNode {
        int val;
        ListNode next;
        
        ListNode(int x) {
            val = x;
        }
    }
    
    static class LinkedList {
        private ListNode head;
        
        public LinkedList() {
            head = null;
        }
        
        public void insertAtHead(int val) {
            ListNode newNode = new ListNode(val);
            newNode.next = head;
            head = newNode;
        }
        
        public void insertAtTail(int val) {
            ListNode newNode = new ListNode(val);
            if (head == null) {
                head = newNode;
                return;
            }
            
            ListNode curr = head;
            while (curr.next != null) {
                curr = curr.next;
            }
            curr.next = newNode;
        }
        
        public void insertAtPosition(int val, int pos) {
            if (pos == 0) {
                insertAtHead(val);
                return;
            }
            
            ListNode newNode = new ListNode(val);
            ListNode curr = head;
            for (int i = 0; i < pos - 1 && curr != null; i++) {
                curr = curr.next;
            }
            
            if (curr != null) {
                newNode.next = curr.next;
                curr.next = newNode;
            }
        }
        
        public void deleteAtHead() {
            if (head != null) {
                head = head.next;
            }
        }
        
        public void deleteAtTail() {
            if (head == null) return;
            if (head.next == null) {
                head = null;
                return;
            }
            
            ListNode curr = head;
            while (curr.next.next != null) {
                curr = curr.next;
            }
            curr.next = null;
        }
        
        public void deleteByValue(int val) {
            if (head == null) return;
            if (head.val == val) {
                deleteAtHead();
                return;
            }
            
            ListNode curr = head;
            while (curr.next != null && curr.next.val != val) {
                curr = curr.next;
            }
            
            if (curr.next != null) {
                curr.next = curr.next.next;
            }
        }
        
        public boolean search(int val) {
            ListNode curr = head;
            while (curr != null) {
                if (curr.val == val) return true;
                curr = curr.next;
            }
            return false;
        }
        
        public int size() {
            int count = 0;
            ListNode curr = head;
            while (curr != null) {
                count++;
                curr = curr.next;
            }
            return count;
        }
        
        public void print() {
            ListNode curr = head;
            while (curr != null) {
                System.out.print(curr.val + " -> ");
                curr = curr.next;
            }
            System.out.println("NULL");
        }
        
        public void reverse() {
            ListNode prev = null;
            ListNode curr = head;
            
            while (curr != null) {
                ListNode next = curr.next;
                curr.next = prev;
                prev = curr;
                curr = next;
            }
            head = prev;
        }
        
        public boolean hasCycle() {
            if (head == null || head.next == null) return false;
            
            ListNode slow = head;
            ListNode fast = head.next;
            
            while (fast != null && fast.next != null) {
                if (slow == fast) return true;
                slow = slow.next;
                fast = fast.next.next;
            }
            return false;
        }
        
        public ListNode findMiddle() {
            if (head == null) return null;
            
            ListNode slow = head;
            ListNode fast = head;
            
            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;
            }
            return slow;
        }
    }
    
    // Common linked list operations
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                curr.next = l1;
                l1 = l1.next;
            } else {
                curr.next = l2;
                l2 = l2.next;
            }
            curr = curr.next;
        }
        curr.next = (l1 != null) ? l1 : l2;
        return dummy.next;
    }
    
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy, slow = dummy;
        for (int i = 0; i < n; i++) {
            if (fast.next == null) return head;
            fast = fast.next;
        }
        while (fast.next != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
    
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode curr = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry != 0) {
            int v1 = (l1 != null) ? l1.val : 0;
            int v2 = (l2 != null) ? l2.val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (l1 != null) l1 = l1.next;
            if (l2 != null) l2 = l2.next;
        }
        return dummy.next;
    }
    
    public static ListNode detectCycle(ListNode head) {
        if (head == null || head.next == null) return null;
        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                ListNode entry = head;
                while (entry != slow) {
                    entry = entry.next;
                    slow = slow.next;
                }
                return entry;
            }
        }
        return null;
    }
    
    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.insertAtTail(1);
        list.insertAtTail(2);
        list.insertAtTail(3);
        list.insertAtTail(4);
        list.insertAtTail(5);
        
        System.out.print("Original list: ");
        list.print();
        
        System.out.println("Size: " + list.size());
        System.out.println("Search 3: " + (list.search(3) ? "Found" : "Not found"));
        
        list.reverse();
        System.out.print("Reversed list: ");
        list.print();
        
        ListNode middle = list.findMiddle();
        if (middle != null) {
            System.out.println("Middle element: " + middle.val);
        }
    }
}

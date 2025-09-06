class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, val):
        new_node = ListNode(val)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node
    
    def prepend(self, val):
        new_node = ListNode(val)
        new_node.next = self.head
        self.head = new_node
    
    def delete(self, val):
        if not self.head:
            return
        if self.head.val == val:
            self.head = self.head.next
            return
        current = self.head
        while current.next:
            if current.next.val == val:
                current.next = current.next.next
                return
            current = current.next
    
    def display(self):
        values = []
        current = self.head
        while current:
            values.append(current.val)
            current = current.next
        return values

# Common linked list operations
def reverse_list(head):
    """Reverse a singly linked list (LeetCode 206)."""
    prev = None
    curr = head
    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node
    return prev

def merge_two_lists(l1, l2):
    """Merge two sorted linked lists (LeetCode 21)."""
    dummy = ListNode()
    curr = dummy
    while l1 and l2:
        if l1.val < l2.val:
            curr.next = l1
            l1 = l1.next
        else:
            curr.next = l2
            l2 = l2.next
        curr = curr.next
    curr.next = l1 or l2
    return dummy.next

def add_two_numbers(l1, l2):
    """Add two numbers represented by linked lists (LeetCode 2)."""
    dummy = ListNode()
    curr = dummy
    carry = 0
    while l1 or l2 or carry:
        v1 = l1.val if l1 else 0
        v2 = l2.val if l2 else 0
        total = v1 + v2 + carry
        carry = total // 10
        curr.next = ListNode(total % 10)
        curr = curr.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    return dummy.next

def remove_nth_from_end(head, n):
    """Remove the nth node from the end of list (LeetCode 19)."""
    dummy = ListNode(0, head)
    fast = slow = dummy
    for _ in range(n):
        if not fast or not fast.next:
            return head  # n is larger than the length of the list
        fast = fast.next
    while fast and fast.next:
        fast = fast.next
        if not slow:
            return head
        slow = slow.next
    if slow and slow.next:
        slow.next = slow.next.next
    return dummy.next

def has_cycle(head):
    """Detect if a linked list has a cycle (LeetCode 141)."""
    slow = fast = head
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

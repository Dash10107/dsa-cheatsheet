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
    pass

def merge_two_lists(l1, l2):
    pass

def add_two_numbers(l1, l2):
    pass

def remove_nth_from_end(head, n):
    pass

def has_cycle(head):
    pass

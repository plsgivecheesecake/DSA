# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        # So apparently, the list is 1-indexed
        dummy = ListNode()
        index = 0
        dummy.next = head
        curr = dummy

        while index < left - 1:
            curr = curr.next
            index += 1

        prefix = curr
        tail = curr.next

        prev = tail
        curr = prev.next

        while left < right:
            next_node = curr.next
            curr.next = prev
            prev = curr
            curr = next_node
            left += 1

        prefix.next = prev
        tail.next = curr

        return dummy.next
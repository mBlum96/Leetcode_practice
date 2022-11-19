# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        fast = head
        slow = head
        
        while(fast and fast.next):#fast goes forward twice as fast so when it reaches the end node slow will be midway
            slow = slow.next
            fast = fast.next.next
        return slow
        
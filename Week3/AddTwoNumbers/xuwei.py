# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @return a ListNode
    def addTwoNumbers(self, l1, l2):
        carry=0
        head=ListNode(0)
        back_head=head
        while l1 or l2 or carry:
            val1=l1.val if l1 else 0
            val2=l2.val if l2 else 0
            val=val1+val2+carry
            if val>=10:
                val-=10
                carry=1
            else:
                carry=0
            l1=l1.next if l1 else None
            l2=l2.next if l2 else None
            node=ListNode(val)
            head.next=node
            head=head.next
        return back_head.next

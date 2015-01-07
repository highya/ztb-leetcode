# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param two ListNodes
    # @return a ListNode
    def mergeTwoLists(self, l1, l2):
        l3=ListNode(0)    
        p3=l3
        while l1!=None and l2!=None:
            if l1.val<l2.val:
                p3.next=l1
                l1=l1.next
            else:
                p3.next=l2
                l2=l2.next
            p3=p3.next
        if l1!=None:
            p3.next=l1
        if l2!=None:
            p3.next=l2
        return l3.next

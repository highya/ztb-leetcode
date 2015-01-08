class Solution:
    # @param head, a ListNode
    # @return a ListNode
     def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head
        now = head.next
        if head.val == now.val:
            while now and head.val == now.val:
                now = now.next
            return self.deleteDuplicates(now)
        else:
            head.next = self.deleteDuplicates(head.next)
        return head    
        

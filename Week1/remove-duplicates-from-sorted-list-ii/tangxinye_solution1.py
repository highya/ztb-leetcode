class Solution:
    # @param head, a ListNode
    # @return a ListNode
     def deleteDuplicates(self, head):
        if head == None or head.next == None:
            return head
        helper = ListNode(0)
        helper.next = head
        pre = helper
        now = helper.next
        while pre.next:
            while now.next and now.next.val == pre.next.val:
                now = now.next
            if now == pre.next:
                pre = pre.next
                now = pre.next
            else:
                pre.next = now.next
        return helper.next
        

class Solution:
    def deleteDuplicates(self, head):
        if head is None or head.next is None:
            return head
        Head,p = ListNode(0),head
        Head.next = head
        pre = Head
        while p.next:
            if p.val == p.next.val:
                dup = p.val
                while p.next and dup == p.next.val:
                    p = p.next
                pre.next = p.next
                p = p.next if p.next else p 
            else:
                pre,p = pre.next,p.next
        return Head.next

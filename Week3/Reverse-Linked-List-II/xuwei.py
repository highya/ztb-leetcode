class Solution:
    def reverseBetween(self, head, m, n):
        if m == n:
            return head
        prev = ListNode(0)
        prev.next = head
        Head,p,num = prev,head,m
        while num > 1:
            p,prev,num = p.next,prev.next,num-1
        for i in range(n-m):
            q = p.next
            p.next = q.next
            q.next = prev.next
            prev.next = q
        return Head.next

class Solution:
    def detectCycle(self, head):
        p1,p2 = head,head
        while p2 and p2.next:
            p1,p2 = p1.next,p2.next.next
            if p1 == p2:
                p1 = head
                while p1 != p2:
                    p1,p2 = p1.next,p2.next
                return p1
        return None

class Solution:
    # @param head, a RandomListNode
    # @return a RandomListNode
    def copyRandomList(self, head):
        if head is None:
            return head
        cur,dct = head,{}
        while cur:
            dct[cur] = cur.next
            cp = RandomListNode(cur.label)
            cp.next = cur.next
            cp.random = cur.random
            cur.next = cp
            cur = cp.next if cp.next else None
        Head = RandomListNode(0)
        Head.next = head.next
        cur = head
        while cur and cur.next:
            cpcur = cur.next
            cur = cpcur.next
            cpcur.next = cpcur.next.next if cpcur.next else None
            cpcur.random = cpcur.random.next if cpcur.random else None
        cur = head
        while cur:
            cur.next = dct[cur]
            cur = cur.next
        return Head.next

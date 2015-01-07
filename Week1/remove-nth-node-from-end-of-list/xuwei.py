class Solution:
	def removeNthFromEnd(self,head,n):
		if head is None or n == 0:
			return None
		p1,p2,m = listNode(0),head,n-1
		p1.next = head
		Head = p1
		while m > 0:
			p2,m = p2.next,m-1
		while p2.next:
			p1,p2=p1.next,p2.next
		p1.next = p1.next.next
		return Head.next

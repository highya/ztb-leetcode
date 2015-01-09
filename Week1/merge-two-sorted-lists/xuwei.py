class Solution:
	def mergeTwoLists(self, l1, l2):
		nHead = ListNode(0)
		lt, rt, backHead = l1, l2, nHead
		while lt or rt:
			if lt is None:
				nHead.next, rt = rt, rt.next
			elif rt is None:
				nHead.next, lt = lt, lt.next
			elif lt.val < rt.val:
				nHead.next, lt = lt, lt.next
			else:
				nHead.next, rt = rt, rt.next
			nHead = nHead.next
		return backHead.next


















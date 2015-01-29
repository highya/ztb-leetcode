public class Solution {
    public RandomListNode copyRandomList(RandomListNode head) {
        Map<RandomListNode, RandomListNode> map = new HashMap<RandomListNode, RandomListNode>();

        for (RandomListNode p = head; p != null; p = p.next)
            map.put(p, new RandomListNode(p.label));

        RandomListNode result = new RandomListNode(0);
        RandomListNode current = result;
        RandomListNode p = head;

        while (p != null) {
            RandomListNode node = map.get(p);
            node.next = map.get(p.next);
            node.random = map.get(p.random);
            current.next = node;
            p = p.next;
            current = current.next;
        }

        return result.next;
    }
}

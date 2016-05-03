from heapq import heappush, heappop
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        res = list()
        result_root = None
        node = result_root
        heap = []
        for idx, list_node in enumerate(lists):
            if list_node is None:
                continue
            heappush(heap, (list_node.val, idx))
        while heap:
            value, index = heappop(heap)
            lists[index] = lists[index].next
            if lists[index] is not None:
                heappush(heap, (lists[index].val, index))
            if result_root is None:
                result_root = ListNode(value)
                node = result_root
            else:
                node.next = ListNode(value)
                node = node.next
        return result_root

node1 = ListNode(1)
node1.next = ListNode(5)
node1.next.next = ListNode(8)

node2 = ListNode(2)
node2.next = ListNode(4)
node2.next.next = ListNode(6)

node3 = ListNode(3)
node3.next = ListNode(7)
node3.next.next = ListNode(10)

lists = [node1, node2, node3]
sol = Solution()
root = sol.mergeKLists(lists)
while root is not None:
    print(root.val)
    root = root.next

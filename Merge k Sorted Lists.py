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
        result_root = ListNode(-1)
        node = result_root
        while True:
            min = 9999999999
            index = None

            for idx, list_node in enumerate(lists):
                if list_node is None:
                    continue
                if list_node.val < min:
                    min = list_node.val
                    index = idx
            if index is None:
                break
            lists[index] = lists[index].next
            if node.val == -1:
                node.val = min
            else:
                node.next = ListNode(min)
                node = node.next
        if result_root.val == -1:
            return None
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

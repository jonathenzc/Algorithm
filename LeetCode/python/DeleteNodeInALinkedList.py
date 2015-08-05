# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} node
    # @return {void} Do not return anything, modify node in-place instead.
    def deleteNode(self, node):
        if(node != None and node.next != None):
            nextNode = node.next
            nextNext = nextNode.next
            node.val = nextNode.val
            node.next = nextNext

            
#测试函数
l1 = ListNode(1)
l2 = ListNode(2)
# l3 = ListNode(3)
# l4 = ListNode(4)
# l5 = ListNode(5)
l1.next = l2
# l2.next = l3
# l3.next = l4
# l4.next = l5

s = Solution()
s.deleteNode(l1)
l = l1
while(l!=None):
    print(l.val)
    l = l.next
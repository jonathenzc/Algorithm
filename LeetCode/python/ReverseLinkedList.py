# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        if(head == None or head.next == None):
            return head
        else:
            nextNode = head.next
            head.next = None #head的下一个节点设为none
            while(nextNode != None):        
                tempNode = nextNode.next
                nextNode.next = head
                head = nextNode
                nextNode = tempNode
                
            return head

#测试函数
s = Solution()
l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
# l4 = ListNode(4)
# l5 = ListNode(5)

l1.next = l2
l2.next = l3
# l3.next = l4
# l4.next = l5

l = s.reverseList(l1)

while(l!=None):
    print(l.val)
    l = l.next
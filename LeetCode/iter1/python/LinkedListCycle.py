# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        if(head == None or head.next == None):
            return False
			
        slowNode = head #每次指向下一个节点
        fastNode = head.next #每次指向下一个节点的下一个节点
        while(slowNode != None and fastNode != None):
            if(slowNode == fastNode):
                return True
			
            slowNode = slowNode.next
            if(fastNode.next != None):
                fastNode = fastNode.next.next
            else:
                return False
		
        return False
		

#测试程序
l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)

l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l1 #Cycle

# head = l1
# while(head != None):
#     print(head.val)
#     head = head.next

s = Solution()
print(s.hasCycle(l1))			 
		
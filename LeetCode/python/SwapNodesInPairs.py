# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if(head == None or head.next == None):
            return head
        
        preNode = head
        postNode = head.next
        
        preNode.next = postNode.next
        postNode.next = preNode
        
        head = postNode #获取交换后的头节点
        
        while(preNode.next != None and preNode.next.next != None):
            nextNode = preNode.next
            postNode = nextNode.next
            
            #交换两个节点
            nextNode.next = postNode.next
            preNode.next = postNode
            postNode.next = nextNode
            
            #设置前一个节点
            preNode = nextNode
            
        return head
     
        
#测试程序
l1 = ListNode(1)
l2 = ListNode(2)
l3 = ListNode(3)
l4 = ListNode(4)
l5 = ListNode(5)
l6 = ListNode(6)

l1.next = l2
l2.next = l3
l3.next = l4
l4.next = l5
l5.next = l6

s = Solution()
l1 = s.swapPairs(l1)

while(l1 != None):
    print(l1.val)
    l1 = l1.next
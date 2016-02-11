# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def oddEvenList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if(head == None or head.next == None): #节点个数为1个或者空节点
            return head
		
        oddTail = head
        evenHead = head.next
        evenTail = head.next
		
        while(evenTail != None and evenTail.next != None):
            oddTail.next = evenTail.next
            evenTail.next = evenTail.next.next
            oddTail = oddTail.next
            evenTail = evenTail.next
			
        oddTail.next = evenHead #奇数列的尾节点指向偶数列的头节点
		
        return head

def initList(n):
    head = ListNode(1)
    traverse = head
    for i in range(2,n+1,1):
        tmp = ListNode(i)
        traverse.next = tmp
        traverse = traverse.next

    return head

def outputList(node):
    while(node != None):
        print(node.val)
        node = node.next


list1 = initList(4)
outputList(list1)

print(" ")

s = Solution()
list1 = s.oddEvenList(list1)
outputList(list1)
# Definition for binary tree with next pointer.
class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if(root != None):
            l = []
            l.append(root)
            cnt = 0
            nextNullCnt = 1 #用来记录哪个节点的next为NULL
            while(cnt<len(l)): 
                temp = l[cnt]
                cnt+=1
                if(cnt == nextNullCnt):
                    temp.next = None
                    nextNullCnt = nextNullCnt*2+1
                else:
                    temp.next = l[cnt]
                    
                if(temp.left != None):
                    l.append(temp.left)
                
                if(temp.right != None):
                    l.append(temp.right)
				

#测试函数
s = Solution()
root = TreeLinkNode(1)
node2 = TreeLinkNode(2)
node3 = TreeLinkNode(3)
node4 = TreeLinkNode(4)
node5 = TreeLinkNode(5)

root.left = node2
root.right = node3

s.connect(root)	

print("Done")	
		
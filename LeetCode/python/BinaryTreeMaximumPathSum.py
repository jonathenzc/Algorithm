# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def whichBigger(self,a,b):
        if(a>b):
            return a
        else:
            return b
    
    def pathSumHelper(self,root,max):
        if(root == None):
            return 0
        
        left = self.pathSumHelper(root.left,max)
        right = self.pathSumHelper(root.right,max)
        #比较1.当前节点+左子树；2.当前节点+右子树；3.当前节点的最大值
        nodeMax = self.whichBigger(self.whichBigger(root.val+left , root.val+right),root.val)
        #将上面的最大值（考虑当前节点的父节点与当前节点相连的情况）与不考虑父节点的情况进行比较
        allMax = self.whichBigger(nodeMax,root.val+left+right)
        
        max[0] = self.whichBigger(max[0],allMax)
        return nodeMax
        
    def maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        maxLst=[-10000000000]
        self.pathSumHelper(root,maxLst)
        return maxLst[0]
        
#测试程序
root = TreeNode(1)
node1 = TreeNode(2)
node2 = TreeNode(3)

node3 = TreeNode(4)
node4 = TreeNode(5)
node5 = TreeNode(4)

root.left = node1
root.right = node2

node1.left = node3
node1.right = node4

node2.left = node5

s = Solution()
print(s.maxPathSum(root))
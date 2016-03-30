# Definition for a binary tree node.
import sys

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def validBSTHelper(self,root,min,max):
        if(root == None):
            return True
        
        if(root.val>min and root.val <max):
            return self.validBSTHelper(root.left,min,root.val) and self.validBSTHelper(root.right,root.val,max)
        else:
            return False
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if(root == None):
            return True
            
        return self.validBSTHelper(root.left,-10000000000,root.val) and self.validBSTHelper(root.right,root.val,10000000000)
        
#测试程序
s = Solution()
root = TreeNode(10)
node1 = TreeNode(5)
node2 = TreeNode(15)

node3 = TreeNode(6)
node4 = TreeNode(20)

root.left = node1
root.right = node2

# node2.left = node3
node2.right = node4

print(s.isValidBST(root))
# print(sys.minsize)
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        size = len(preorder)-1
        node = self.buildHelper(preorder,inorder,0,0,size)
        return node
        
#测试程序
s = Solution()
prelist = [1,2,4,5,3,6]
inlist = [4,2,5,1,3,6]

print(s.buildTree(prelist,inlist))

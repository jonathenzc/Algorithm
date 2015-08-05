# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer}
    def maxDepth(self, root):
        if(root == None):
            return 0
        else:
            leftDepth = self.maxDepth(root.left)+1
            rightDepth = self.maxDepth(root.right)+1
            if(leftDepth > rightDepth):
                return leftDepth
            else:
                return rightDepth
                

#测试函数
root = TreeNode(1)
left = TreeNode(1)
right = TreeNode(1)
root.left = left
left.right = right
s = Solution()
print(s.maxDepth(root))
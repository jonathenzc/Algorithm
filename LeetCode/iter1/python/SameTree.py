# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {boolean}
    def isSameTree(self, p, q):
        if(p == None and q == None):
            return True
        elif(p != None and q == None):
            return False
        elif(p == None and q != None):
            return False
        else:
            if(p.val == q.val):
                return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
            else:
                return False
				
				
#测试函数
root1 = TreeNode(1)
left1 = TreeNode(2)
right1 = TreeNode(4)
root1.left = left1
root1.right = right1

root2 = TreeNode(1)
left2 = TreeNode(1)
right2 = TreeNode(5)
root2.left = left2
root2.right = right2

s = Solution()
print(s.isSameTree(root1,left2))
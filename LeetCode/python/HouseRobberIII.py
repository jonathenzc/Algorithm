# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def robHelper(self,root):
        if(root == None):
            return [0,0]
        
        leftL = self.robHelper(root.left)
        rightL = self.robHelper(root.right)
        
        leftLmax = leftL[0]
        if(leftLmax < leftL[1]):
            leftLmax = leftL[1]
        
        rightLmax = rightL[0]
        if(rightLmax < rightL[1]):
            rightLmax = rightL[1]
        
        fatherVal = leftLmax + rightLmax 
        grandChildVal = root.val + leftL[1] + rightL[1]
        
        return [grandChildVal,fatherVal]
    
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        result = []
        result = self.robHelper(root)
        if(result[0] > result[1]):
            return result[0]
        else:
            return result[1]
        
        
#测试程序
s = Solution()
root = TreeNode(3)
node1 = TreeNode(2)
node2 = TreeNode(3)
node3 = TreeNode(3)
node4 = TreeNode(1)

root.left = node1
root.right = node2
node1.right = node3
node2.right = node4

print(s.rob(root))
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def postorderHelper(self, root,l):
        """
        :type root: TreeNode
		:type l: List[int]
        :rtype: nothing
        """
        if(root != None):
            self.postorderHelper(root.left,l)
            self.postorderHelper(root.right,l)						
            l.append(root.val)	
	
    def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        l = []
        self.postorderHelper(root,l)
        return l
		
		
#测试程序
root = TreeNode(1)
node2 = TreeNode(2)
node3 = TreeNode(3)
node4 = TreeNode(4)
node5 = TreeNode(5)
node6 = TreeNode(6)

root.left = node2
root.right = node3
node2.left = node4
node2.right = node5
node3.left = node6

s = Solution()
print(s.postorderTraversal(root))
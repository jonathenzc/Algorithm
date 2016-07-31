# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
	# @param {TreeNode} root
    # @return void
    def preOrderHelper(self,root):
        if(root != None):
            self.preOrder.append(root.val)
            self.preOrderHelper(root.left)
            self.preOrderHelper(root.right)
		
    # @param {TreeNode} root
    # @return {integer[]}
    def preorderTraversal(self, root):
        self.preOrder = []
        self.preOrderHelper(root)
        return self.preOrder

		
#测试程序
s = Solution()
node1 = TreeNode(1)
node2 = TreeNode(2)
node3 = TreeNode(3)
node4 = TreeNode(4)
node5 = TreeNode(5)

node1.left = node2
node1.right = node5
node2.left = node3
node3.right = node4

print(s.preorderTraversal(node1))

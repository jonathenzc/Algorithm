# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        if(root == None):
            return None
        
        pVal = p.val
        qVal = q.val
        while(True):
            rootVal = root.val
            if(pVal<rootVal and qVal<rootVal): #都在根节点的左边，访问根的左子树
                root = root.left
            elif(pVal>rootVal and qVal>rootVal):  #都在根节点的右边，访问根的右子树
                root = root.right
            else: #在两边则返回结果
                return root
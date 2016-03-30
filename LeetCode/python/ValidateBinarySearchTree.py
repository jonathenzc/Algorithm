# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

#限定范围来比较节点的值是否在其中
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

#利用中序遍历后的链表来比较是否递增
class Solution(object):
    def inorderTraverse(self,root,lst):
        if(root == None):
            return lst
        
        lst = self.inorderTraverse(root.left,lst)
        lst.append(root.val)
        lst = self.inorderTraverse(root.right,lst)
        
        return lst
    
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if(root == None):
            return True
        
        treelst = self.inorderTraverse(root,[])
        
        print(treelst)
        
        lstSize = len(treelst)
        item = treelst[0]
        
        result = True
        
        for i in range(1,lstSize):
            treeItem = treelst[i]
            if(item>=treeItem):
                result = False
                break
            else:
                item = treeItem
                
        return result
        
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
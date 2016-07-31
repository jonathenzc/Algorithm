# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def pathSumHelper(self,root,sum,path_sum,pathLst,Lst):
        if(root != None):
            print(pathLst)
            print(path_sum)
            if(root.left == None and root.right == None): #叶子节点
                if(path_sum + root.val == sum):
                    tmpLst = []
                    for i in pathLst:
                        tmpLst.append(i)
                        
                    tmpLst.append(root.val)
                    Lst.append(tmpLst)
            else:
                tmpPath_sum = path_sum
                tmpPath_sum += root.val
                    
                tmplst = []
                for i in pathLst:
                    tmplst.append(i)
                    
                tmplst.append(root.val)

                if(root.left != None):
                    self.pathSumHelper(root.left,sum,tmpPath_sum,tmplst,Lst)
                        
                if(root.right != None):
                    self.pathSumHelper(root.right,sum,tmpPath_sum,tmplst,Lst)    
    
    def pathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: List[List[int]]
        """
        LST = []
        self.pathSumHelper(root,sum,0,[],LST)
        return LST
        

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
print(s.pathSum(root,8))
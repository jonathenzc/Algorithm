# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sumLst(self,lst):
        lstSize = len(lst)
        sum = 0
        for i in range(0,lstSize):
            tmp = lst[i]
            while(i<lstSize-1):
                tmp*=10
                i+=1
                
            sum += tmp
            
        return sum
    
    def sumHelper(self,root,lst,sum):
        if(root != None):
            if(root.left == None and root.right == None):
                tmplst = []
                for i in lst:
                    tmplst.append(i)
                
                tmplst.append(root.val)
                sumNum = self.sumLst(tmplst)
                print(sumNum)
                sum[0] += sumNum
            else: 
                tmpLst = []
                for i in lst:
                    tmpLst.append(i)
                    
                tmpLst.append(root.val)
                      
                if(root.left != None):
                    self.sumHelper(root.left,tmpLst,sum)
                
                if(root.right != None):
                    self.sumHelper(root.right,tmpLst,sum)

    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        sumNum = [0]
        self.sumHelper(root,[],sumNum)
        return sumNum[0]

        
#测试程序
root = TreeNode(1)
node1 = TreeNode(2)
node2 = TreeNode(3)

node3 = TreeNode(4)
node4 = TreeNode(5)
node5 = TreeNode(6)

root.left = node1
root.right = node2

node1.left = node3
node1.right = node4

node2.left = node5

s = Solution()
print(s.sumNumbers(root))
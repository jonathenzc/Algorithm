class Solution:
    # @param {integer} n
    # @return {integer}
    def numTrees(self, n):
        #利用动态规划来做
        treeNum = [1,1,2] #treeNum[i]表示i个节点可以构建多少个BST，它的值等于左右子树可能出现的乘积
        for i in range(3,n+1,1):
            treeNum.append(0)
            for j in range(i):
                # print("i,j:",i,j)
                treeNum[i] += treeNum[j]*treeNum[i-j-1]
            
        return treeNum[n]
            
            
#测试函数
s = Solution()
for i in range(6):
    print(s.numTrees(i))		
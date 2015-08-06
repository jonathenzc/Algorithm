class Solution:
    # @param n, an integer
    # @return an integer
    def hammingWeight(self, n):
        oneCnt = 0
        while(n>0):
            if(n%2 == 1):
                oneCnt += 1
            n = n//2
        return oneCnt
		

#测试程序
s = Solution()
print(s.hammingWeight(7))	
class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self, n):
        if(n<=1):
            return 1	
			
        waysToTop = [1,1]
		
        for i in range(2,n+1):
            waysToTop.append(waysToTop[i-1]+waysToTop[i-2])
		
        return waysToTop[n]
		

#测试程序
s = Solution()
print(s.climbStairs(3))
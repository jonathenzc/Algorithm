class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        if(n<=0):
            return False

        if(n<=2):
            return True
			
        while(n>2):
            if(n%2 == 1):
                return False
			
            n = n//2
		
        return True
		
		
#main函数
s = Solution()
print(s.isPowerOfTwo(12))
class Solution:
    # @param {integer} num
    # @return {integer}
    def addDigits(self, num):
        if(num==0):
            return 0
        
        result = num%9
        if(result == 0):
            return 9
        else:
            return result					
		

#测试程序
s = Solution()
print(s.addDigits(38))
print(s.addDigits(18))
print(s.addDigits(0))
print(s.addDigits(9))
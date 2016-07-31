class Solution:
    # @param {integer} num
	# @param {integer} n
    # @return {integer}
	# 消除num中的因数n
    def degrade(self, num,n):
        while(num%n == 0):
            num = num//n
			
        return num	
	
    # @param {integer} num
    # @return {boolean}
    def isUgly(self, num):
        if(num <= 0):
            return False
        
		#消除2的因数
        num = self.degrade(num,2)
		#消除3的因数
        num = self.degrade(num,3)
        #消除5的因数
        num = self.degrade(num,5)
		#如果num为1就是ugly数
        if(num == 1):
            return True
        else:
            return False

			
#测试程序
s = Solution()
print(s.isUgly(1)) #True
print(s.isUgly(6)) #True
print(s.isUgly(8)) #True
print(s.isUgly(14)) #False
print(s.isUgly(28)) #False
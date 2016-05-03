class Solution(object):
    def isPowerOfFour(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if(num<=0):
            return False
        
        return ((num-1) & num ) == 0 and (num& 0x55555555) != 0
        
#测试程序
s = Solution()
print(s.isPowerOfFour(2))
print(s.isPowerOfFour(1))
print(s.isPowerOfFour(16))
print(s.isPowerOfFour(17))
print(s.isPowerOfFour(256))
print(s.isPowerOfFour(257))
print(s.isPowerOfFour(6))
print(s.isPowerOfFour(12))
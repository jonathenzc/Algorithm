class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if(n%4==0):
            return False
        else:
            return True
		
#测试程序	
s = Solution()
print(s.canWinNim(4))
print(s.canWinNim(5))
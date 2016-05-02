class Solution(object):
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        sSize = len(s)
        
        if(sSize == 0 or sSize == 1):
            return s
            
        return s[::-1]
        
#测试程序
s = Solution()
print(s.reverseString(""))
print(s.reverseString("a"))
print(s.reverseString("abc"))
print(s.reverseString("abcd"))
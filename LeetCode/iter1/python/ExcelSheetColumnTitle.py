class Solution:
    # @param {integer} n
    # @return {string}
    def convertToTitle(self, n):
        result=""
        while(n!=0):
            digit = n%26
            if(digit == 0):
                digit = 26
            
            result += chr(digit+64)
            n = (n-1)//26
        
        return result[::-1] #反转字符串


#测试程序
s = Solution()
print(s.convertToTitle(677))
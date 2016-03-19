import math

class Solution:
    # # @param {integer} i
    # # @return {integer}  
    # def powerOf26(self,i):
    #     if(i==0):
    #         return 1
    #     
    #     Sum=1
    #     cnt=0
    #     while(cnt<i):
    #         Sum*=26
    #         cnt+=1
    #     
    #     return Sum
        
    # @param {string} s
    # @return {integer}
    def titleToNumber(self, s):
        strSize = len(s)
        title = 0
        for i in range(strSize):
            digit = ord(s[i])-ord('A')+1
            multiplyCnt = strSize-i-1
            title += digit * (26**multiplyCnt)   

        return title

#测试程序
s = Solution()
# print(s.powerOf26(2))
print(s.titleToNumber("ZA"))
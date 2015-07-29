class Solution:
    # @param {string} s
    # @return {integer}
    def lengthOfLastWord(self, s):
        strLen = len(s)
        
        if(strLen == 0):
            return 0
        
        nonSpaceIndex = -1 #第一个非空格下标
        
        for i in range(strLen-1,-1,-1):
            # print("i:",i)
            # print("nonSpaceIndex:",nonSpaceIndex)
            if(s[i] == ' '):
                if(nonSpaceIndex != -1):
                    return nonSpaceIndex-i
            else:
                if(nonSpaceIndex == -1): #之前未记录非空格字符的下标
                    nonSpaceIndex = i
                    
            if(i == 0): #？字符串未发现空格
                return nonSpaceIndex - i+1
                

#main 函数
s = Solution()
print(s.lengthOfLastWord(""))
                              
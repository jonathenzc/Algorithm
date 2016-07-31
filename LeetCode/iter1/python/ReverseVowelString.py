class Solution(object):
    def isCharVowel(self,ch):
        if(ch == "a" or ch == "e" or ch == "i" or ch == "o" or ch == "u" or
        ch == "A" or ch == "E" or ch == "I" or ch == "O" or ch == "U"):
            return True
        else:
            return False
    
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        sSize = len(s)
        if(sSize == 0 or sSize == 1):
            return s
            
        start = 0
        end = sSize-1
        isStartVowelFound = False
        isEndVowelFound = False

        lstStr = list(s)

        while(start < end):
            if(not isStartVowelFound and self.isCharVowel(lstStr[start])):
                isStartVowelFound = True
            
            if(not isEndVowelFound and self.isCharVowel(lstStr[end])):
                isEndVowelFound = True
            
            if(isStartVowelFound and isEndVowelFound):
                tmp = lstStr[start]
                lstStr[start] = lstStr[end]
                lstStr[end] = tmp
                isStartVowelFound = False
                isEndVowelFound = False                
            
            if(not isStartVowelFound):
                start += 1
                
            if(not isEndVowelFound):
                end -= 1               
        
        
        targetS = "".join(lstStr);
        return targetS
        
        
#测试程序
s = Solution()
print(s.reverseVowels(""))
print(s.reverseVowels("a"))
print(s.reverseVowels("abc"))
print(s.reverseVowels("abe"))
print(s.reverseVowels("acde"))
print(s.reverseVowels("aceid"))
print(s.reverseVowels("aecbd"))
print(s.reverseVowels("aeioubcd"))
print(s.reverseVowels("aA"))
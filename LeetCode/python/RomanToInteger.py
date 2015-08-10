class Solution:
    # @param {string} s
    # @return {integer}
    def romanToInt(self, s):
        #建立罗马数字与阿拉伯数的映射
        romanDict = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        sSize = len(s)
        result=0
        for i in range(sSize-1):
            #如果前一个数大于等于后一个数就加1
            front = romanDict[s[i]]
            latter = romanDict[s[i+1]]			
            if(front>=latter):
                result += front 
            else:
                result -= front			
				
        result += romanDict[s[sSize-1]]
		
        return result

#测试程序
s=Solution()
print(s.romanToInt("I"))
print(s.romanToInt("III"))
print(s.romanToInt("IIII"))
print(s.romanToInt("XIX"))
print(s.romanToInt("XIV"))
print(s.romanToInt("XXVII"))
class Solution:
    # @param {string} s
    # @param {integer} numRows
    # @return {string}
    def convert(self, s, numRows):
        if(numRows == 1):
            return s
			
        sSize = len(s)
        convertedS = ""
        diff = -2
        doubleSize = 2*(numRows-1)
        for i in range(numRows):
            diff += 2
            strIndex = i
            tempDistance = diff #将diff先保存					
            while(strIndex < sSize):
                convertedS += s[strIndex]
                if(i==0 or i == numRows-1): #第一行和最后一行
                    strIndex += doubleSize
                else: #其他行
                    diff = doubleSize-diff
                    strIndex += diff 
            diff = tempDistance
					
        return convertedS
		
#测试函数
s = Solution()
print(s.convert("fsdafa",1))					
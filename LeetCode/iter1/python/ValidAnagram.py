class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isAnagram(self, s, t):
        if(len(s) != len(t)):
            return False
		
		#根据字符串s构建字典	
        wordDict = {}
        for c in s:
            if c in wordDict:
                wordDict[c] += 1
            else:
                wordDict[c] = 1
		
		#查找s中的单词是否都出现在t中了
        for c in t:
            if c in wordDict:
                if(wordDict[c] == 0):
                    return False
			
                wordDict[c] -= 1
            else:
                return False
		
        return True				
			
#测试函数
s = Solution()
print(s.isAnagram("f",""))		
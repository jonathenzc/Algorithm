class Solution(object):
    def turnWords2Int(self,word):
        resultInt = 0
        for c in word:
            resultInt |= 1<<(ord(c)-ord('a'))
        
        return resultInt
		
    def maxProduct(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        wordsInt=[]
        for word in words:
            wordsInt.append(self.turnWords2Int(word))

        max_product = 0
        words_Size = len(words)				
        for i in range(0,words_Size,1):
            for j in range(i+1,words_Size,1):
                if((wordsInt[i] & wordsInt[j]) == 0):
                    tmpSize = len(words[i])*len(words[j])
                    if(tmpSize > max_product):
                        max_product = tmpSize					

        return max_product
		
s = Solution()
v = ["abcw","baz","foo","bar","xtfn","abcdef"]
print(s.maxProduct(v)) 
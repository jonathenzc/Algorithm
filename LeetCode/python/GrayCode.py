class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = [0]
        for i in range(n):
            #得到最后一位的差距
            addition = 1
            cnt = 0
            while(cnt<i):
                addition *= 2
                cnt += 1
			
            for j in range(addition-1,-1,-1):
                result.append(result[j]+addition)
			
        return result
		

#测试程序
s = Solution()
for i in range(5):
	print(s.grayCode(i))
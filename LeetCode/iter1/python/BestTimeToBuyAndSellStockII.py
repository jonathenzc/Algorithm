class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        listSize = len(prices)
        if(listSize<=1):
            return 0
			
        profitSum = 0
        for i in range(1,listSize,1):
            diff = prices[i]-prices[i-1]
            if(diff>0): #价格增长
                profitSum += diff
				
        return profitSum
        
#测试程序
s = Solution()
#max profit: 8
prices = [1,2,3,4,5,6,7,8,9]
print(s.maxProfit(prices))

#max profit: 2
prices = [2,1,2,0,1]
print(s.maxProfit(prices))

#max profit: 1
prices = [2,1,2,1,0]
print(s.maxProfit(prices))

#max profit: 3
prices = [2,1,2,4,1]
print(s.maxProfit(prices))

#max profit: 7
prices = [2,1,2,4,3,0,4,3]
print(s.maxProfit(prices))

#max profit: 5
prices = [2,1,2,4,3,0,2,-1]
print(s.maxProfit(prices))

#max profit: 7
prices = [6,1,3,2,4,7,2,-1]
print(s.maxProfit(prices))
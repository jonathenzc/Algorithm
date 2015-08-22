class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        pricesSize = len(prices)
        if(pricesSize == 0):
            return 0
		
        # profit = [0 for i in range(pricesSize)] #profit[i]表示第1天到第i天的最大利益
        lowestPrice = prices[0]
        maxprofitSoFar = 0
        for i in range(1,pricesSize,1):
            #更新股票最低价
            if(prices[i]<lowestPrice):
                lowestPrice = prices[i]
			
            todayProfit = prices[i] - lowestPrice
            if(todayProfit > maxprofitSoFar):
                maxprofitSoFar = todayProfit
            #     profit[i] = todayProfit
            # else:
            #     profit[i] = profit[i-1]
		
        # return profit[pricesSize-1]
        return maxprofitSoFar
		
#测试程序
s = Solution()
#max profit: 8
prices = [1,2,3,4,5,6,7,8,9]
print(s.maxProfit(prices))

#max profit: 1
prices = [2,1,2,0,1]
print(s.maxProfit(prices))

#max profit: 1
prices = [2,1,2,1,0]
print(s.maxProfit(prices))

#max profit: 3
prices = [2,1,2,4,1]
print(s.maxProfit(prices))

#max profit: 4
prices = [2,1,2,4,3,0,4,3]
print(s.maxProfit(prices))

#max profit: 3
prices = [2,1,2,4,3,0,2,-1]
print(s.maxProfit(prices))

#max profit: 6
prices = [6,1,3,2,4,7,2,-1]
print(s.maxProfit(prices))
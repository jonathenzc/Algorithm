class Solution:
    # @param {integer []} uglyNumber
    # @param {integer []} i 2,3,5的指针           
    # @return {integer}
    def min235(self, uglyNumber, i):	
        two = 2*uglyNumber[i[0]]
        three = 3*uglyNumber[i[1]]
        five = 5*uglyNumber[i[2]]
        if(two<=three and five>=two): #min two
            i[0] += 1
            if(two == three): #处理公约数
                i[1] += 1
            if(five == two):
                i[2] += 1
                
            return two
        elif(three<=two and five>=three): #min three
            i[1] += 1
            if(two == three): #处理公约数
                i[0] += 1
            if(five == three):
                i[2] += 1
                
            return three
        elif(five<=two and three>=five): #min five
            i[2] += 1
            if(five == two): #处理公约数
                i[0] += 1
            if(five == three):
                i[1] += 1
                
            return five    
    
    # @param {integer} n
    # @return {integer}
    def nthUglyNumber(self, n):
        index=[0,0,0]
        uglyNumber = [1]
        
        for i in range(1,n,1):
            uglyNumber.append(self.min235(uglyNumber,index))
            # print("uglyNumber: ",uglyNumber)
            # print("index: ",index)
           
        return uglyNumber[n-1]


#测试程序
s = Solution()
for i in range(1,17,1):
    print(s.nthUglyNumber(i))
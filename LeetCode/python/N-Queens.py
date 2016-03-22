class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        queensResultList = []
        
        chessBoard = []
        
        for i in range(0,n):
            chessBoard.append(-1)
        
        for i in range(0,n):
            chessBoard[0] = i #第一列
            tempList = self.isSafe(chessBoard,1,n)
            listSize = len(tempList)
            for j in range(0,listSize):
                queensResultList.append(tempList[j])
			
        return queensResultList
        
        
     # chessBoard的下标是col,值是row
    def isSafeHelper(self,chessBoard,col,row):
        result = False
        
        for i in range(0,col):
            if(row == chessBoard[i]):
                break
            
            if(row - chessBoard[i] == col - i):
                break
                
            if(row - chessBoard[i] == i - col):
                break
            
            if(i == col - 1):
                result = True

        return result
    
    def isSafe(self,chessBoard,col,n):
        queensResultList = []
        if(col == n):
            stringVector = []
            for i in range(0,n):
                s = ""
                for j in range(0,n):
                    if(j == chessBoard[i]):
                        s+= "Q"
                    else:
                        s += "."
                   
                stringVector.append(s)
            
            queensResultList.append(stringVector);    
        else:            
            for i in range(0,n):
                if(self.isSafeHelper(chessBoard,col,i)):
                    chessBoard[col] = i
                    tempList = self.isSafe(chessBoard,col+1,n)
                    listSize = len(tempList)
                    for j in range(0,listSize):
                        queensResultList.append(tempList[j])
                    
                    
        return queensResultList
       
        
#测试程序
s = Solution()

a = s.solveNQueens(1)

print(len(a))
print(a)
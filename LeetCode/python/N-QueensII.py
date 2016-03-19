class Solution(object):
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
        cnt = 0
        if(col == n):
            cnt = 1
        else:            
            for i in range(0,n):
                if(self.isSafeHelper(chessBoard,col,i)):
                    chessBoard[col] = i
                    cnt += self.isSafe(chessBoard,col+1,n)
                    
        return cnt

    def totalNQueens(self, n):
        """
        :type n: int
        :rtype: int
        """
        QueensCnt = 0
        
        chessBoard = []
        
        for i in range(0,n):
            chessBoard.append(-1)
        
        for i in range(0,n):
            chessBoard[0] = i #第一列
            QueensCnt += self.isSafe(chessBoard,1,n)
			
        return QueensCnt
				
				
#测试程序
s = Solution()

print(s.totalNQueens(8))
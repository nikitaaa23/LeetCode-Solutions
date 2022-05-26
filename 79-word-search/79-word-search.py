class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n = len(board)
        m = len(board[0])
        vis = set()
        
        def backtrack(i, j, idx):
            if len(word) == idx:
                return True
            
            if(i< 0 or i>=n or j<0 or j>=m or board[i][j]!=word[idx] or (i, j) in vis):
                return False
            
            if(board[i][j] == word[idx]):
                vis.add((i, j))
                res = (backtrack(i+1, j, idx+1) or
                    backtrack(i, j+1, idx+1) or
                    backtrack(i-1, j, idx+1) or
                    backtrack(i, j-1, idx+1))
                vis.remove((i, j))
                
            return res
        
        for i in range(n):
            for j in range(m):
                if word[0] == board[i][j]:
                    if backtrack(i, j, 0):
                        return True
                    
        return False
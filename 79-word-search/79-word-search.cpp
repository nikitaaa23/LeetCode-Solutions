class Solution {
public:
    bool backtrack(int i, int j, vector<vector<int>>&vis, vector<vector<char>> &board, string &word, int n, int m, int idx){

          
 if(idx==word.size()){
          return true;
      }
      
     if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || vis[i][j] == true || board[i][j]!=word[idx]){
           return false;
       }
 
      if(board[i][j] == word[idx]){
          vis[i][j] = true;
          bool ispos = (backtrack(i+1, j, vis, board, word, n, m, idx+1)
            ||  backtrack(i-1, j, vis, board, word, n, m, idx+1)
            ||  backtrack(i, j+1, vis, board, word, n, m, idx+1)
            ||  backtrack(i, j-1, vis, board, word, n, m, idx+1)) ; 
            vis[i][j] = false;
            return ispos;
      }
      
          return false;

  }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i= 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(backtrack(i, j, vis, board, word, n, m, 0)){
                        return true;
                    }
                        
                }
            }
        }
        return false;
    }
};
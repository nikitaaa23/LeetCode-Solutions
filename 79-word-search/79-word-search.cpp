class Solution {
public:
    
    bool dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>&vis, string &word, int idx){
        if(idx == word.size())
            return true;
       if(r >= board.size() || r<0 || c<0 || c>=board[0].size() || vis[r][c]==true ||
         word[idx]!=board[r][c])
           return false;
        if(word[idx] == board[r][c]){
            vis[r][c] = true;
        bool res = dfs(r+1, c, board, vis, word, idx+1)
            ||  dfs(r-1, c, board, vis, word, idx+1)
            ||  dfs(r, c+1, board, vis, word, idx+1)
            ||  dfs(r, c-1, board, vis, word, idx+1);
        vis[r][c] = false;
        return res;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
         vector<vector<int>>vis(board.size(), vector<int>(board[0].size(), 0));
        for(int i = 0;i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, board, vis, word, 0)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};
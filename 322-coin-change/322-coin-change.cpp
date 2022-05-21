class Solution {
public:
    #define INF INT_MAX-1
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int t[n+1][amount+1];
        
//         for(int i=0; i<=n; i++)
//         {
//             for(int j=0; j<=amount; j++)
//             {
//                 if(i==0){ t[i][j] = INF ;}
//                 if(j==0){ t[i][j] = 0 ;}
//                 if(i==1)
//                 {   
//                     if((j%coins[i-1]) == 0){ t[i][j] = j/coins[i-1] ;}
//                     else{ t[i][j] = INF ;}
//                 }
//             }
//         }
        
        
//         for(int i = 1; i<=n; i++){
//             for(int j = 1; j<=amount; j++){
//                 if(coins[i-1]<=j){
//                     t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
//                 }
//                 else
//                     t[i][j] = t[i-1][j];
//             }
//         }
        
//         return t[n][amount] > amount ? -1 : t[n][amount];
        
//         for(int i = 0; i<amount+1; i++){
//             t[i] = INT_MAX-1;
//         }
//         t[0] = 0;
        
//         for(int i =1; i<amount+1; i++){
//             for(auto c : coins){
//                 if(i - c >= 0){
//                     t[i] = min(t[i], 1+t[i-c]);
//                 }
//             }
//         }
//         return t[amount] == INT_MAX-1 ? -1 : t[amount];
        
        for(int i = 0 ;i<=n; i++){
            for(int j=0; j<=amount; j++){
                if(i==0){
                    t[i][j]  = INF;
                }
                
                if(j==0){
                    t[i][j]  = 0;
                }
                if(i==1){
                    if(j%coins[i-1]==0) t[i][j] = j/coins[i-1];
                    else t[i][j]  = INF;
                }
            }
        }
        
        for(int i = 1 ;i<=n; i++){
            for(int j=1; j<=amount; j++){
                if(coins[i-1]<=j){
                    t[i][j] = min(t[i-1][j], 1+t[i][j-coins[i-1]]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][amount] > amount ? -1:  t[n][amount];
        
    }
};
class Solution {
public:
    
    bool solve(int idx, vector<int>&matchsticks, int tar, vector<int>&sides){
        if(idx==matchsticks.size())
            return true;
        
        for(int j=0;j<4;j++){
            if(sides[j] + matchsticks[idx] <= tar){
                sides[j]+=matchsticks[idx];
                if(solve(idx+1, matchsticks, tar, sides)){
                    return true;
                }
                sides[j]-=matchsticks[idx];
            }
        }
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for(auto x : matchsticks)
            sum+=x;
        
        if(sum%4)
            return false;
    
        int tar = sum/4;
        vector<int>sides(4, 0);
        
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return solve(0, matchsticks, tar, sides);
    }
};
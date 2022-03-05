class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i = left; i<=right; i++){
            bool flag = false;
            for(auto x : ranges){
                if(x[0] <= i && x[1] >= i){
                    flag = true;
                    break;
                }
            }
            if(flag ==false)
                return false;
        }
        return true;
        
        
    }
};
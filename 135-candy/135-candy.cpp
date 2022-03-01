class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if(n==0)
            return 0;
        int ret = 1;
        int up = 0, down =0, peak = 0;
        for(int i = 1; i<n; i++){
            if(ratings[i-1] < ratings[i]){
                up++;
                peak = up;
                down = 0;
                ret+=1+up;
            }
            else if(ratings[i-1] == ratings[i]){
                peak = up = down = 0;
                ret+=1;
            }
            else{
                down++;
                up = 0;
                ret+=1+down + (peak>=down ? -1:0);
            }
        }
        return ret;
    }
};
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        
        int total = 0;
        int l=0, r = n-k;
        for(int i = r; i<n; i++){
            total+=cardPoints[i];
        }
        int res= total;
        while(r<n){
            total += cardPoints[l] - cardPoints[r];
            res = max(res, total);
            l++;
            r++;
        }
        
        return res;
    }
};
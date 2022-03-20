class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        vector<int>a(7), b(7), same(7);
        
        for(int i = 0; i<n; i++){
            a[tops[i]]++;
            b[bottoms[i]]++;
            if(tops[i]==bottoms[i])
                same[tops[i]]++;
        }
        
        int mn = INT_MAX;
        
        for(int i = 1; i<=6; i++){
            if(a[i]+b[i]-same[i] == n)
                mn = min(mn, min(a[i], b[i]) - same[i]);
        }
        
        return mn == INT_MAX ? -1 : mn;
    }
};
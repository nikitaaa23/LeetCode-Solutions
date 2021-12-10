class Solution {
public:
    int mod = 1000000007;
    int numTilings(int n) {
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 5;
        vector<int>t(n+1, 0);
       t[0] = 1;
        t[1] = 1;
        t[2] = 2;
        t[3] = 5;
        
        for(int i = 4; i<=n; i++){
            t[i] = (2*t[i-1]%mod + t[i-3]%mod)%mod;
        }
        return t[n]%mod;
    }
};
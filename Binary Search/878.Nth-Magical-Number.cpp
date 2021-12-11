class Solution {
public:
    int mod = 1e9+7;
    long magicless(long x, long a, long b, long lc){
        return (x/a) + (x/b) - (x/lc);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long lc = lcm(a, b);
        long l =  min(a, b);
        long r = n*l;
        long ans;
        while(l<=r){
            long mid = l + (r-l)/2;
            if(magicless(mid, a, b, lc)<n)
                l = mid+1;
            else{
                r = mid-1;
                ans = mid;
            }
        }
        return ans%mod;
    }
};
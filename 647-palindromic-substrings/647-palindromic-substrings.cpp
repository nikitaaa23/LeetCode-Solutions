class Solution {
public:
    
    int ans = 0, n;
    
    void check(int st, int ed, string&s){
         while(st>=0 && ed<n && s[st]==s[ed]){
            st--;
            ed++;
            ans++;
        }
    }
    int countSubstrings(string s) {
        n = s.size();
        for(int i=0; i<n; i++){
            check(i,i, s); // odd length
            check(i,i+1, s); // even length
        }
	    return ans;
    }
};
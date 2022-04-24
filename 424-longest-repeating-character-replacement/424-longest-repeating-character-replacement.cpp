class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int>mp;
        int i =0, j=0;
        int len = 0;
        int n = s.size();
        // while(j<n){
        //     int mx = 0;
        //     mp[s[j]]++;
        //     for(auto x : mp){
        //         mx = max(mx, x.second);
        //     }
        //     if(j-i+1 - mx <= k){
        //         len = max(len, j-i+1);
        //     }
        //     else if(j - i+1 -mx >k){
        //         mp[s[i]]--;
        //         i++;
        //     }
        //     j++;
        // }
        
        while(j<n){
            int mx = 0;
            mp[s[j]]++;
            for(auto x : mp){
                mx = max(mx, x.second);
            }
            if(j-i+1 - mx <=k ){
                len = max(len, j-i+1);
            }
            else if(j-i+1 -mx > k){
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return len;
    }
};
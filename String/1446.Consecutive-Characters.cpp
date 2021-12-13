class Solution {
public:
    int maxPower(string s) {
        int curr =1, mx=1;
        
        for(int i=0;i<s.size()-1; i++){
            if(s[i]==s[i+1])
                curr++;
            else
                curr=1;
            
            mx  = max(mx, curr);
        }
        return mx;
    }
};
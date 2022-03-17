class Solution {
public:
    int scoreOfParentheses(string s) {
        int i=0, n=s.size();
        stack<char>st;
        int count = 0;
        int ans =0;
        while(i<n){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
                if(s[i-1]=='('){
                ans+= 1<<count;
                }
            }
            i++;
        }
        return ans;
    }
};
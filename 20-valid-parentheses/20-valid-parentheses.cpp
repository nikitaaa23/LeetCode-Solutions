class Solution {
public:
    bool isValid(string s) {
        int i=0, n=s.size();
        stack<char>st;
        
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(s[i]==')' ){
                if(!st.empty() && st.top()=='(')
                st.pop();
                else return false;
            }
            else if(s[i]==']'){
                if(!st.empty()  && st.top()=='[')
                st.pop();
                else return false;
            }
            else if(s[i]=='}' ){
                if(!st.empty() && st.top()=='{')
                st.pop();
                else return false;
            }
            i++;
        }
        
        if(st.empty()) return true;
        return false;
    }
};
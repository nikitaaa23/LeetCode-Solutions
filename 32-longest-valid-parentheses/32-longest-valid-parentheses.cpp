class Solution {
public:
    int longestValidParentheses(string s) {
         if(s.size()==0 || s.size()==1)
    return 0;
    if(s.size()==2 ){
        if((s[0]=='(' && s[1]=='(') || (s[0]==')' && s[1]=='(') || (s[0]==')' && s[1]==')'))
        return 0;
    }
    
    stack<int>p;
    int ans = 0;
    p.push(-1);

    for(int i = 0 ;i<s.size(); i++){
        if(s[i] == '('){
            p.push(i);
        }
        else{
            if(!p.empty()){
                p.pop();
            }
            if(!p.empty()){
                ans = max(ans, i - p.top());
            }
            else{
                p.push(i);
            }
        }
    }
    return ans;
    }
};

// -1
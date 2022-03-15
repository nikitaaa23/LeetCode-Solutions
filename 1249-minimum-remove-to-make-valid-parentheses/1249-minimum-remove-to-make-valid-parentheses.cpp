class Solution {
public:
    string minRemoveToMakeValid(string s) {
    stack<char>st;
    int open=0;
    string ans="";
	
    for(int i=0;i<s.length();i++)
    {

        if(isalpha(s[i])) // check the char
            st.push(s[i]);
			
        else if(s[i]=='('){
            open++;
            st.push('(');
        }
        else
        {
                if(open>0){
                    st.push(s[i]);
                    open--;
                }
        }
    }
	
    if(st.empty())
        return "";
    
    while(!st.empty()){
        if(st.top()=='('){
            if(open>0)
            {
            open--;}
            else
                ans+=st.top();
            st.pop();
        }
        else{
            ans+=st.top();
                st.pop();
        }    
    }
	
    reverse(ans.begin(),ans.end());
    return ans;
    }
};
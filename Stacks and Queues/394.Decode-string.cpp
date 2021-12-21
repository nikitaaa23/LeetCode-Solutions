class Solution {
public:
    string decodeString(string s) {
        stack<int>num;
        stack<string>st;
        int i =0;
        string ans = "";
        int n = 0;
        int m = s.size();
        
        while(i<m){
            if(isdigit(s[i])){
                
                n = n*10 + (s[i]-'0');
            }
            else if(s[i]=='['){
                num.push(n);
                n=0;
                st.push(ans);
                ans="";
            }
            else if(s[i]==']'){
                int t= num.top();
                string str = st.top();
                st.pop();
                num.pop();
                for(int i = 0; i<t; i++){
                    str.append(ans);
                }
                ans = str;
            }
            else{
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};
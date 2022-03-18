class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char>st;
        vector<int>vis(26, 0);
        vector<int>last(26, -1);
        
        for(int i = 0;i<n; i++){
            last[s[i]-'a'] = i;
        }
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(s[i]);
                vis[s[i]-'a']=1;
            }
            else if(!vis[s[i]-'a']){
                while(!st.empty() && st.top() >s[i] && last[st.top()-'a'] >i){
                    vis[st.top()-'a']=0;
                    st.pop();
                }
                st.push(s[i]);
                vis[s[i]-'a']=1;
            }
        }
        string ans="";
        
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//   a-2 b-6,c-7, d-4
// cba
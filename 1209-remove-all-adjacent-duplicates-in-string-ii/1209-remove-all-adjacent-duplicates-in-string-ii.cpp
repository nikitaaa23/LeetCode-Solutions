class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        stack<pair<char, int>>st;
        
        for(int i = 0; i<s.size(); i++){
           if(!st.empty() && st.top().first==s[i]){
               int c = st.top().second;
               st.pop();
               st.push({s[i], c+1});
           }
            else
                st.push({s[i], 1});
            
            if(st.top().second==k)
                st.pop();
        }
        string ans;
        while(!st.empty()){
            while(st.top().second--){
                 ans+= st.top().first;
            }
           
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        
        for(int i = 0; i<s.size(); i++){
           //cout<<ch<<endl;
            if(st.empty() || st.top().first!=s[i]){
                  st.push({s[i], 1});
            }
            else{
                auto t = st.top();
                st.pop();
                st.push({s[i], t.second+1});
            }
            if(st.top().second==k){
                st.pop();
            }

        }
        string ans;
          while(!st.empty()){
            auto cur = st.top();
            st.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
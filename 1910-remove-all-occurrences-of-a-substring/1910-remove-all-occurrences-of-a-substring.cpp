class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        stack<int>st;
        for(auto x : s){
            st.push(x);
            if(st.size() >= part.size()){
                int j = part.size() -1;
                while(!st.empty() && j>=0 && st.top()==part[j]){
                    st.pop();
                    j--;
                }
                if(j!=-1)
                {
                    j++;
                    while(j<part.size())
                    {
                        st.push(part[j++]);
                    }
                }
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
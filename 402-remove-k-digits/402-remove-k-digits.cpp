class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>s;
        int n = num.size();
        string ans ="";
        
        if(n <= k)
            return "0";
        if(k==0)
            return num;
        s.push(num[0]);
        
        for(int i = 1; i<n; i++){
            while(!s.empty() && s.top() > num[i] && k){
                s.pop();
                k--;
            }
             s.push(num[i]);
            
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        while(k && !s.empty()){
            s.pop();
            k--;
        }
        
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        if(ans.size()==0)
            return "0";
        return ans;
        
    }
};
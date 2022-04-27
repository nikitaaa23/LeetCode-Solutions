class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i =0, j =0;
        
        stack<char>st1, st2;
        
        while(i<s.size()){
            if(s[i]!='#'){
                st1.push(s[i]);
            }
            else{
                if(!st1.empty())
                st1.pop();
            }
            i++;
        }
         while(j<t.size()){
            if(t[j]!='#'){
                st2.push(t[j]);
            }
            else{
                if(!st2.empty())
                st2.pop();
            }
            j++;
        }
        string p, q;
        while(!st1.empty()){
            // cout<<st1.top()<<" ";
            p+=st1.top();
            st1.pop();
        }
         while(!st2.empty()){
             cout<<st2.top()<<" ";
            q+=st2.top();
            st2.pop();
        }
        return p==q;
    }
};
class Solution {
public:
    
    
    static bool check(string s, int idx){
        string t1, t2;
        
        for(int i = 0; i<s.size(); i++){
            if(i!=idx) t1+=s[i];
        }
        
        t2 = t1;
        reverse(t1.begin(), t1.end());
        if(t1==t2) return true;
        
        return false;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        
        while(i<s.size() && j>=0){
            if(s[i]!=s[j]){
                if(check(s, i)) return true;
                if(check(s, j)) return true;;
                
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
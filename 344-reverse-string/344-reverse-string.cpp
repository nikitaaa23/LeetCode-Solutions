class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()<=1) return;
        
        int l = 0, r = s.size()-1;
        
        while(l<=r){
            swap(s[l++], s[r--]);
        }
        
    }
};
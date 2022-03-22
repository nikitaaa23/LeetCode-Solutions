class Solution {
public:
    
        // string res(n, ' ');
        
//         for(int i=n; i>0; i--)
//         {
//             int charIdx = min(26, (k-i+1));
//             res[i-1] = 'a' + (charIdx - 1);
//             k -= charIdx;
//         }
        
//         return res;
    string getSmallestString(int n, int k) {
        string s(n, ' ');
       for(int i = n; i>0; i--){
           int ch = min(26, (k-i+1));
           s[i-1] = 'a' + (ch-1);
           k -= ch;
       }
        return s;
    }
};
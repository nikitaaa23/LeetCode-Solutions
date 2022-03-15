class Solution {
public:
    vector<string>v;
    
//     void par(int start, int end, const string &s){
//         if(!start && !end){
//             v.push_back(s);
//         }
        
//         if(start!=0){
//             par(start-1, end, s+"(");
//         }
//         if(start<end){
//             par(start, end-1, s+")");
//         }
//         return;
//     }
//     vector<string> generateParenthesis(int n) {
//         string s;
        
//         par(n, n, s);
//         return v;
//     }
    
    void par(int start, int end, const string &s){
        if(!start && !end)
            v.push_back(s);
        
        if(start > 0 ){
            par(start-1, end, s+"(");
        }
        if(start < end ){
            par(start, end-1, s+")");
        }
        
    }
    
     vector<string> generateParenthesis(int n) {
         string s;
        
         par(n, n, s);
         return v;
     }
};
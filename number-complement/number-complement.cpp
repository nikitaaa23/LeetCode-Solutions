class Solution {
public:
    int findComplement(int num) {
        int x = log2(num)+1;
        
        int y = pow(2, x)-1;
       // cout<<y<<endl;
        return y-num;
    }
};
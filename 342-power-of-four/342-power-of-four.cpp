class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0){
            return false;
        }
        
        // while(n%4!=0 && n!=0){
        //     n/=4;
        // }
        double x = log(n)/log(4);
        
        return  x == (int)x;
    }
};
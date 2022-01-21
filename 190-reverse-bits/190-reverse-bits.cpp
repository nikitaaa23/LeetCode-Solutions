class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
                
        for(int i = 0;i <32; i++){
           int v = n &1; //and bits
            n = n>>1;       //right shift --> 00110 -> 0011 -> 001 -> 00 ->0
            ans = ans<<1;   //left shift -> 0 -> 00 -> 001 -> 0011 -> 00110
             ans =ans | v; //last two steps ans ko bits banane ke liye
        }
        return ans;
    }
};
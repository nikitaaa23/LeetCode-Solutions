class Solution {
    public int singleNumber(int[] nums) {
        int x = 0;
        for(int y : nums){
            x^=y;
        }
        
        return x;
    }
}
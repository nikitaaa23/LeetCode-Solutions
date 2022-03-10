class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int reach = nums[n-1];
        
        for(int i =n -1 ; i>=0; i--){
           if(i + nums[i] >= reach)
            reach = i;
        }
        return reach == 0 ? true : false;
        
    }
};
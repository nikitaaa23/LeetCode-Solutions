class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{                                                     //move slow by 1, fast by 2
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow!=fast);
        
        fast = nums[0];                              //move slow and fast by 1, 
                                                       // 2nd collision at duplicate
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
        
    }
};
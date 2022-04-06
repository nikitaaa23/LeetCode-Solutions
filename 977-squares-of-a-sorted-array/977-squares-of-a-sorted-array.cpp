class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n= nums.size();
        vector<int>v(n);
        
        int st = 0, ed = n-1;
        int pos = n-1;
        
        while(st<=ed){
            if(abs(nums[st]) < abs(nums[ed])){
                v[pos] = nums[ed]*nums[ed];
                pos--;
                ed--;
            }
            else{
                v[pos] = nums[st]*nums[st];
                pos--;
                st++;
            }
        }
        return v;
    }
};
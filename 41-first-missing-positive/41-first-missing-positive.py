class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        
        for i in range(n):
            if nums[i]<=0 or nums[i]>n:
                nums[i] = n+1;
        
        for i in range(n):
            k = abs(nums[i])
            if k > n:
                continue
            else:
                if nums[k-1]>0:
                    nums[k-1] = -1*nums[k-1]
                    
        for i in range(n):
            if nums[i]>0:
                return i+1
        return n+1
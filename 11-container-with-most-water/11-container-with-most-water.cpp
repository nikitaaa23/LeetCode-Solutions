class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        
        int l =0, h = n-1;
        
        int area = 0;
        int maxA = 0;
        while(l<h){
            int lh = height[l];
            int rh = height[h];
            int high = min(lh, rh);
            area = (h-l) * high;
            maxA = max(maxA, area);
            
            if(lh<rh){l++;}
            else{
                h--;
            }
        }
        return maxA;
    }
};
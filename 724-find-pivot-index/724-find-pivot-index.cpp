class Solution {
public:
    int pivotIndex(vector<int>& arr) {
            int ans =-1;
        int n = arr.size();
        vector<int>pre(n);
        pre[0] = arr[0];
        for(int i = 1; i<n; i++){
            pre[i] = arr[i]+pre[i-1];
        }
        vector<int>suff(n);
        suff[n-1] = arr[n-1];
        for(int i = n-2; i>=0; i--){
            suff[i] = arr[i]+suff[i+1];
        }

        for(int i = n-1; i>=0; i--){
            if(pre[i] == suff[i]){
                ans = i;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        
    vector<int>l(n, 0), r(n, 0);
        vector<int>ans;
        l[0] = 1;
        for(int i = 1; i<n; i++){
            if(security[i-1]>=security[i])
                l[i] = 1 + l[i-1];
        }
        r[n-1] = 1;
        
        for(int i = n-2; i>=0; i--){
            if(security[i+1]>=security[i])
                r[i] = 1+ r[i+1];
        }
        
        for(int i = time; i<n-time; i++){
            if(l[i]>=time && r[i]>=time)
                ans.push_back(i);
        }
        return ans;
    }
};
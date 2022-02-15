class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int>q;
        q.push(start);
        vector<bool>vis(arr.size(), 0);
        vis[start] = true;
        while(!q.empty()){
           auto i = q.front();
            
            
            if(arr[i] == 0){
                return true;
            }
            q.pop();
            if(i + arr[i] < arr.size() && !vis[i + arr[i]]){
                q.push(i + arr[i]);
                vis[i + arr[i]] = true;
            }
            
            
            if(i - arr[i] >=0 && !vis[i - arr[i]]){
                q.push(i - arr[i]);
                vis[i - arr[i]] = true;
            }
        }
        return false;
    }
};
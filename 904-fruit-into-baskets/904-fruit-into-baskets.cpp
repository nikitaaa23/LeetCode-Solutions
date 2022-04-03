class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        if(n==1)
            return 1;
        int i =0, j = 0;
        int count = 0;
        unordered_map<int, int>mp;
        while(j<n){
            mp[fruits[j]]++;
            //cout<<mp.size() << endl;
            if(mp.size() <= 2){
                count = max(j-i+1, count);
            }
            else if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0)
                        mp.erase(fruits[i]);
                    i++;
                }
            }
            j++;
        }
        return count;
    }
};
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++){
            unordered_map<char,int> m;
            for(auto c:words[i]){
                m[c++];
            }
            for(int j=i+1;j<words.size();j++){
                int flag=0;
                for(auto c:words[j]){
                    if(m.find(c)!=m.end()){
                        flag=1;
                        break;
                    }
                    
                }
                if(flag==0){if(ans<words[i].size()*words[j].size()){
                    ans=words[i].size()*words[j].size();
                }}
            }
        }
        return ans;
    }
};
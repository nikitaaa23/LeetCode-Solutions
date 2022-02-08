class UnionFind {
  public:
    int count;
    vector<int>root;
    vector<int>rank;
    UnionFind(int n){
        count = n;
        root = vector<int>(n);
        rank = vector<int>(n);
        
        for(int i=0; i<n; i++){
            root[i]=i;
            rank[i]=1;
        }
    }
    
    void unionset(int x, int y){
        int rootx=find(x);
        int rooty = find(y);
        if(rootx!=rooty){
             if(rank[rootx]>rank[rooty])
                root[rooty]=rootx;
             else if(rank[rooty]>rank[rootx])
                root[rootx]=rooty;
            else{
                root[rooty] = rootx;
                rank[rootx]++;
            }
            count--;
        }
    }
    
    int find(int x){
       if(x == root[x])
           return root[x];
       return root[x] =find(root[x]); 
    }
    
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        if(pairs.size()==0){
            return s;
        }
        
        UnionFind uf(n);
        
        for(auto x: pairs){
            uf.unionset(x[0], x[1]);
        }
        
        map<int, string>mp;            //map stores chars with same parent root at same idx
        for(int i = 0; i<n; i++){
            int root = uf.find(i);
            uf.root[i] = root;
            mp[root]+=s[i];
        }
        
        if(uf.count==1){
            sort(s.begin(), s.end());
            return s;
        }
        
        for(auto x: mp){
            int i = x.first;            //sort string at each idx in map in desc order
            string s = x.second;
            sort(s.begin(), s.end(), greater<char>());
            mp[i] = s;
        }
        
        for(int i = 0; i<n; i++){          //find root of ith element to find char from map
            int root = uf.find(i);           //change org string by taking element from map
            s[i] = mp[root].back();
            mp[root].pop_back();
        }
        
        return s;
    }
};
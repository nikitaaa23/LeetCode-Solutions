class Solution {
public:
    
    unordered_map<string, pair<string, double>>parent;
    
    string find(string &a, double &val){
        if(parent.find(a)==parent.end()){
            parent[a] = make_pair(a, 1.0);
            return a;
        }
        else{
            string p = parent[a].first;
            if(p==a)
                return a;
            else{
                val*=parent[a].second;
                return find(p, val);
            }
        }
    }
    
    void unionset(string a, string b, double val){
        double pav = 1.0, pbv = 1.0;
        string pa = find(a, pav);
        string pb = find(b, pbv);
        
        if(pa!=pb){
            parent[pb].first = pa;
            parent[pb].second = pav*val/pbv;
        }
    }
    
    
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0; i<values.size(); i++){
            unionset(equations[i][0], equations[i][1], values[i]);
        }
        
        vector<double>ans;
        
        for(int i = 0; i<queries.size(); i++){
            string a = queries[i][0];
            string b = queries[i][1];
            
            if(parent.find(a)==parent.end() || parent.find(b)==parent.end()){
                ans.push_back(-1.0);
            }
            else{
                double pav = 1.0, pbv = 1.0;
                string pa = find(a, pav);
                string pb = find(b, pbv);
                if(pa!=pb){
                    ans.push_back(-1.0);
                }
                else{
                    ans.push_back(pbv/pav);
                }
            }
        }
        return ans;
    }
};
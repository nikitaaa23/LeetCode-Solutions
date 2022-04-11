class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int>s; int sum = 0;
        for(int i = 0; i<ops.size(); i++){
            
            if(ops[i] == "+"){
               
                    int x = s.top();
                    s.pop();
                    int y = s.top();
                    s.push(x);
                    s.push(x+y);
            
            }
            else if(ops[i]=="D"){
                int x = s.top();
                s.push(2*x);
            }
            else if(ops[i]=="C"){
                int x = s.top();
                s.pop();
            }
           else{
                int x = stoi(ops[i]);
                s.push(x);
            }
        }
        while(!s.empty()){
            int x = s.top();
            s.pop();
            sum+=x;
        }
        return sum;
    }
};
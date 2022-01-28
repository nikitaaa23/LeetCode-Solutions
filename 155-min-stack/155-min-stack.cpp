class MinStack {
public:
    
    stack<long long int>s;
    long long int mn;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            mn = val;
        }
        else{
            if(val<mn){
                s.push((long long int)2*val - mn);  
                mn = val;              
            }
            else{
                s.push(val);
            }
        }
    }
    
    void pop() {
        if(s.top() < mn){
            long long int temp = 2*mn - s.top();
            mn = temp;
            s.pop();
        }
        else s.pop();    
    }
    
    int top() {
        if(mn > s.top())
            return mn;
        else return s.top();
    }
    
    int getMin() {
        return mn;
    }
};



// -3 0 -2   //-4 0 -2   //-6 + 4 

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
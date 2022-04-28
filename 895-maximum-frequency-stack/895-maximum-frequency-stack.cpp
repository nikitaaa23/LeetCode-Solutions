class FreqStack {
public:
    map<int, int>mp;
    map<int, stack<int>>st;
    int mF =0 ;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++; //5-2 7-1 
        mF=max(mF, mp[val]);
        st[mp[val]].push(val); //1-5,7,4  2-5,7 3-5
    }
    
    int pop() {
        int x = st[mF].top();
        st[mF].pop();
        mp[x]--;
        
        if(st[mF].empty())
            mF--;
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
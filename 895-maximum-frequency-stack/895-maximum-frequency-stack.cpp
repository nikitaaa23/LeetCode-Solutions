class FreqStack {
public:
    map<int, int>mp;
    map<int, stack<int>>gp;
    int mxF = 0;
    FreqStack() {
    }
    
    void push(int val) {
        mp[val]++;
        gp[mp[val]].push(val);
        mxF = max(mxF, mp[val]);
    }
    
    int pop() {
        int tp = gp[mxF].top();
        gp[mxF].pop();
        mp[tp]--;
        
        if(gp[mxF].empty())
			mxF--;

		return tp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
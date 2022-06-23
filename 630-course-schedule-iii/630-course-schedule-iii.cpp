class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int>pq;
        
        int s = 0;
        
        for(auto i : courses){
            s+=i[0];
            pq.push(i[0]);
            if(s > i[1]){
                s-=pq.top();
                pq.pop();
            }
                
        }
        return pq.size();
    }
};
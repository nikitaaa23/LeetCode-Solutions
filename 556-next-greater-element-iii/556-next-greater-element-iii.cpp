class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long x = stol(s);

        return (x > INT_MAX || x <= n) ? -1 : x;
    }
};
class Solution {
public:
    int titleToNumber(string columnTitle) {
              
        long long int num = 0, p = 1;
        
        for(int i = columnTitle.size()-1; i>=0; i--){
            num+= (columnTitle[i] - 'A' + 1)*p;
                p*=26;
        }
        return num;
    }
};
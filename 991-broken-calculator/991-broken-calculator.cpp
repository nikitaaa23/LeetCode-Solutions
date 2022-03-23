class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int count = 0;
       if(target==startValue)
           return 0;
        while(1){
            if(target%2==0 && target > startValue){
                target/=2;
                count++;
            }
            else{
                target++;
                count++;
            }
            if(target==startValue)
                return count;
        }
        return -1;
    }
};
// Last updated: 4/3/2026, 2:00:57 PM
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>=10){
            sum=0;
            while(num!=0){
                sum+=num%10;
                num/=10;
            }
            num=sum;
        }
        return num;
    }
};
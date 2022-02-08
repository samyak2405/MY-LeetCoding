class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(1)
        {
            sum+=(num%10);
            num/=10;
            if(num==0 and sum<10)
                break;
            else if(num==0 and sum>=10)
            {
                num = sum;
                sum = 0;
            }
        }
        return sum;
    }
};
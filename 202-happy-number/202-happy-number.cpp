class Solution {
public:
    
    int solve(int n)
    {
        int res = 0;
        while(n>0){
            int rem = n%10;
            res+=rem*rem;
            n/=10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        while(n!=1 and n!=4)
            n = solve(n);
        if(n==4)
            return false;
        return true;
    }
};
class Solution {
public:
    int twoEggDrop(int n) {
        int sum = 0;
        for(int i = 1;i<1001;i++)
        {
            sum+=i;
            if(sum>=n)
                return i;
        }
        return -1;
    }
};
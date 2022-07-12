class Solution {
public:
    int minOperations(int n) {
        vector<int> arr;
        for(int i = 0;i<n;i++)
            arr.push_back(2*i+1);
        int median = 0;
        if(n%2)
            median = arr[n/2];
        else
            median = arr[n/2]-1;
        int sum = 0;
        for(int i = 0;i<n/2;i++)
            sum+=abs(arr[i]-median);
        return sum;
    }
};
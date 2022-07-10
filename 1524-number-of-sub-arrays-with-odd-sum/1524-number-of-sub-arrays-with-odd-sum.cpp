class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        // vector<int> even(n),odd(n);
        // if(arr[n-1]%2)
        //     odd[n-1] = 1;
        // else
        //     even[n-1] =1;
        // int sum = odd[n-1];
        // for(int i = n-2;i>=0;i--)
        // {
        //     if(arr[i]%2==0)
        //     {
        //         even[i] = (1+even[i+1])%mod;
        //         odd[i] =odd[i+1];
        //     }
        //     else
        //     {
        //         odd[i] = (1+even[i+1])%mod;
        //         even[i] = odd[i+1];
        //     }
        //     sum = (sum+odd[i])%mod;
        // }
        // return sum;
        int even = 0,odd = 0,odd_next,even_next;
        int sum = 0;
        if(arr[n-1]%2)
            odd = 1;
        else
            even = 1;
        odd_next = odd;
        even_next = even;
        sum+=odd;
        for(int i = n-2;i>=0;i--)
        {
            if(arr[i]%2==0)
            {
                even = (1+even_next)%mod;
                even_next = even;
            }
            else
            {
                odd = (1+even_next)%mod;
                even = odd_next;
                odd_next = odd;
                even_next = even;
            }
            sum = (sum + odd)%mod;
        }
        return sum;
    }
};
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> s;
        for(int i = 0;i<x.length();i++)
        {
            if(s.empty() or (x[i]=='[' or x[i]=='{' or x[i]=='('))
            {
                s.push(x[i]);
            }
            else if((s.top()=='{' and x[i]=='}') or (s.top()=='[' and x[i]==']') 
            or (s.top()=='(' and x[i]==')'))
                s.pop();
            else if((s.top()!='{' and x[i]=='}') or (s.top()!='[' and x[i]==']') 
            or (s.top()!='(' and x[i]==')'))
                return false;
        }
        if(s.size()!=0)
            return false;
        return true;
    }

};

// { Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}  // } Driver Code Ends
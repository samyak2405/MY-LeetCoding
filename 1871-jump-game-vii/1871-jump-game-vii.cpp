class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if(s[n-1]!='0')
            return false;
        int i = 0;
        queue<int> q;
        q.push(0);
        int curr_max = 0;
        while(!q.empty())
        {
            i = q.front();
            q.pop();
            if(i==n-1)
                return true;
            for(int k = max(curr_max,i+minJump);k<=min(i+maxJump,n-1);k++)
                if(s[k]=='0')
                    q.push(k);
            curr_max = max(i+maxJump+1,curr_max);
        }
        return false;
    }
};
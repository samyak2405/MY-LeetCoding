class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ways = 0;
        long long penscost = 0;
        while(penscost<=total)
        {
            long long remaining = total-penscost;
            ways += (remaining/cost2) + 1;
            penscost += cost1;
        }
        return ways;
    }
};
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];
        int total = 0;

        for(int i=2; i<n; i++) {
            int mini = min(a, b);
            total = mini + cost[i];

            a = b;
            b = total;
        }
        return min(a, b);
    }
};
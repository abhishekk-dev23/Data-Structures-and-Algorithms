class Solution {
private:
    int solve(int r, int c, int x, int y, vector<vector<int>> &dp, vector<vector<int>> &dun) 
    {  
        // base case
        if(r == x-1 && c == y-1) {
            return dp[r][c] = max(1, 1 - dun[r][c]);
        }
        if(r == x || c == y) return 1e8;

        if(dp[r][c] != -1) return dp[r][c];

        int right = solve(r, c+1, x, y, dp, dun);
        int down = solve(r+1, c, x, y, dp, dun);

        int val = min(down, right) - dun[r][c];

        return dp[r][c] = max(1, val);
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r = dungeon.size();
        int c = dungeon[0].size();

        vector<vector<int>> dp(r, vector<int> (c, -1));
        int ans = solve(0, 0, r, c, dp, dungeon);

        return ans;
    }
};
class Solution {
private:
    int findPath(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        
        if(x == 0 && y == 0) {
            return dp[x][y] = grid[x][y];
        }
        if(dp[x][y] != -1) return dp[x][y];

        int up = INT_MAX, left = INT_MAX;
        if(x > 0) up = findPath(x-1, y, grid, dp);
        if(y > 0) left = findPath(x, y-1, grid, dp);


        return dp[x][y] = grid[x][y] + min(up, left);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> dp(r, vector<int> (c, -1));
        

        return findPath(r-1, c-1, grid, dp);
    }
};
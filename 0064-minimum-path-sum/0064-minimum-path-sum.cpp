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
        
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[r-1][c-1];
    }
};
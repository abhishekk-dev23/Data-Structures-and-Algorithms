class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[r-1][c-1])
            return 0;

        vector<vector<int>> dp(r, vector<int> (c, -1));

        int obsX = -1, obsY = -1;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i > 0) {
                        if(!obstacleGrid[i-1][j]) up = dp[i-1][j];
                    } 
                    if(j > 0) {
                        if(!obstacleGrid[i][j-1]) left = dp[i][j-1];
                    }

                    dp[i][j] = left + up;
                }
            }
        }
        return dp[r-1][c-1];
    }
};
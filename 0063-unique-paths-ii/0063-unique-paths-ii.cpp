class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int r = obstacleGrid.size();
        int c = obstacleGrid[0].size();
        if(obstacleGrid[0][0] || obstacleGrid[r-1][c-1])
            return 0;

        vector<int> prev(c, 0);
        for(int i=0; i<r; i++) {
            vector<int> curr(c, 0);

            for(int j=0; j<c; j++) {
                if(i == 0 && j == 0) curr[j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i > 0) {
                        if(!obstacleGrid[i-1][j]) up = prev[j];
                    } 
                    if(j > 0) {
                        if(!obstacleGrid[i][j-1]) left = curr[j-1];
                    }

                    curr[j] = left + up;
                }
            }
            prev = curr;
        }
        return prev[c-1];
    }
};
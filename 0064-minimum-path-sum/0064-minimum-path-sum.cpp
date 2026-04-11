class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> prev(c, 0);
        
        for(int i=0; i<r; i++) {
            vector<int> curr(c, 0);

            for(int j=0; j<c; j++) {
                if(i == 0 && j == 0) {
                    curr[j] = grid[i][j];
                }
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = curr[j-1];

                    curr[j] = grid[i][j] + min(up, left);
                }
            }
            prev = curr;
        }
        return prev[c-1];
    }
};
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();

        vector<vector<int>> dp(r, vector<int> (c, -1));
        for(int i=0; i<c; i++) 
            dp[r-1][i] = triangle[r-1][i];
        
        for(int i=r-2; i>=0; i--) {
            for(int j=i; j>=0; j--) {
                int down = INT_MAX, dig = INT_MAX;
                down = triangle[i][j] + dp[i+1][j];
                dig = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, dig);
            }
        }
        return dp[0][0];
    }
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, 1));
        // for(int i=0; i<n; i++)  dp[0][i] = 1;
        // for(int i=0; i<m; i++) dp[i][0] = 1;

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                int upVal = dp[i-1][j];
                int lftVal = dp[i][j-1];
                int val = upVal + lftVal;
                dp[i][j] = val;
            }
        }
        return dp[m-1][n-1];
    }
};
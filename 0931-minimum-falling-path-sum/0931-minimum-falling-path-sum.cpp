class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        for(int i=0; i<n; i++)
            dp[n-1][i] = matrix[n-1][i];

        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<n; j++) {
                int leftDig = INT_MAX;
                int down = INT_MAX;
                int rightDig = INT_MAX;

                if(j-1 >= 0) leftDig = matrix[i][j] + dp[i+1][j-1];
                down = matrix[i][j] + dp[i+1][j];
                if(j+1 < n) rightDig = matrix[i][j] + dp[i+1][j+1];

                dp[i][j] = min(leftDig, min(down, rightDig));
            }
        }
        int min_path = INT_MAX;
        for(int i=0; i<n; i++) 
            min_path = min(min_path, dp[0][i]);
        
        return min_path;
    }
};
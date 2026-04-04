class Solution {
private:
    int findPath(int m, int n, vector<vector<int>> &dp) {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        int right = findPath(m, n-1, dp);
        int down = findPath(m-1, n, dp);
        int ans = right + down;
        
        return dp[m][n] =  ans;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return findPath(m-1, n-1, dp);
    }
};
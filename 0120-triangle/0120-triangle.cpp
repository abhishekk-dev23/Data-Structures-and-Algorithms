class Solution {
private:
    int findPath(int x, int y, vector<vector<int>>& triangle, vector<vector<int>> &dp) {
        if(x == 0 && y == 0) {
            return dp[x][y] = triangle[x][y];
        }

        if(dp[x][y] != -1) return dp[x][y];
        
        int dig = INT_MAX, up = INT_MAX;
        if(x > 0 && y <= x-1) up = findPath(x-1, y, triangle, dp);
        if(x > 0 && y > 0) dig = findPath(x-1, y-1, triangle, dp);
        
        return dp[x][y] = triangle[x][y] + min(dig, up);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();

        vector<vector<int>> dp(r, vector<int> (c, -1));
        int sum = 0;
        int min_sum = INT_MAX;
        for(int i=0; i<c; i++) {
            sum = findPath(r-1, i, triangle, dp);
            min_sum = min(min_sum, sum);
        }
        return min_sum;
    }
};
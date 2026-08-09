class Solution {
public:
    int solve(int i, int j, vector<int>& piles, vector<vector<int>> &dp) {
        if(i > j) return 0;
        if (i == j) return piles[i];

        if(dp[i][j] != -1) return dp[i][j];

        int take_a = piles[i] + min(solve(i+2, j, piles, dp), solve(i+1, j-1, piles, dp));
        int take_b = piles[j] + min(solve(i, j-2, piles, dp), solve(i+1, j-1, piles, dp));

        return dp[i][j] = max(take_a, take_b);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int totalStones = 0;
        for (int count : piles) totalStones += count;
        vector<vector<int>> dp(n, vector<int> (n, -1));

        int stones = solve(0, n-1, piles, dp);

        return stones > totalStones / 2;
    }
};
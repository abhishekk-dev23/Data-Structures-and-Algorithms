class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> next(n, 0);

        for(int i=0; i<n; i++)
            next[i] = matrix[n-1][i];

        for(int i=n-2; i>=0; i--) {
            vector<int> curr(n, 0);

            for(int j=0; j<n; j++) {
                int leftDig = INT_MAX;
                int down = INT_MAX;
                int rightDig = INT_MAX;

                if(j-1 >= 0) leftDig = matrix[i][j] + next[j-1];
                down = matrix[i][j] + next[j];
                if(j+1 < n) rightDig = matrix[i][j] + next[j+1];

                curr[j] = min(leftDig, min(down, rightDig));
            }
            next = curr;
        }
        
        return *min_element(next.begin(), next.end());
    }
};
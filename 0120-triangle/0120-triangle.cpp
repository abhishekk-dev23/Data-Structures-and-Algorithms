class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int r = triangle.size();
        int c = triangle[r-1].size();

        vector<int> next(c, 0);
        for(int i=0; i<c; i++) 
            next[i] = triangle[r-1][i];
        
        for(int i=r-2; i>=0; i--) {
            vector<int> curr(i+1, 0);

            for(int j=i; j>=0; j--) {
                int down = INT_MAX, dig = INT_MAX;
                down = triangle[i][j] + next[j];
                dig = triangle[i][j] + next[j+1];

                curr[j] = min(down, dig);
            }
            next = curr;
        }
        return next[0];
    }
};
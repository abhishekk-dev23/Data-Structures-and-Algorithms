class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m, 1);

        for(int j=1; j<n; j++) {
            vector<int> curr(m, 1);
            for(int i=1; i<m; i++) {
                curr[i] = curr[i-1] + prev[i];
            }
            prev = curr;
        }
        return prev[m-1];
    }
};
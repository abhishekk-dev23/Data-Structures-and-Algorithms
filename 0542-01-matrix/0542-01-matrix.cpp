class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        vector<vector<int>> adj(r, vector<int> (c, INT_MAX));
        queue<pair<int, int>> q;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(mat[i][j] == 0) {
                    adj[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int dirx[4] = {1, 0, -1, 0};
        int diry[4] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int newX = x + dirx[i];
                int newY = y + diry[i];

                if(newX >= 0 && newX < r && newY >= 0 && newY < c) {
                    if(adj[newX][newY] > adj[x][y]+1) {
                        adj[newX][newY] = adj[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }
        return adj;
    }
};
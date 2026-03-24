class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<int>> vis(r, vector<int>(c, 0));
        queue<pair<int, int>> q;
        // left and right
        for(int i=0; i<r; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                vis[i][0] = 1;
            }
            if(grid[i][c-1] == 1) {
                q.push({i, c-1});
                vis[i][c-1] = 1;
            }
        }
        // top and bottom
        for(int j=0; j<c; j++) {
            if(grid[0][j] == 1) {
                q.push({0, j});
                vis[0][j] = 1;
            }
            if(grid[r-1][j] == 1) {
                q.push({r-1, j});
                vis[r-1][j] = 1;
            }
        }

        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx < r && nx >= 0 && ny < c && ny >= 0 &&
                    !vis[nx][ny] && grid[nx][ny] == 1) {

                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
            }
        }

        int cnt = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!vis[i][j] && grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
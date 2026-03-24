class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        queue<pair<int, int>> q;
        // left and right
        for(int i=0; i<r; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if(grid[i][c-1] == 1) {
                q.push({i, c-1});
                grid[i][c-1] = 0;
            }
        }
        // top and bottom
        for(int j=1; j<c-1; j++) {
            if(grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if(grid[r-1][j] == 1) {
                q.push({r-1, j});
                grid[r-1][j] = 0;
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
                    grid[nx][ny] == 1) {

                        grid[nx][ny] = 0;
                        q.push({nx, ny});
                    }
            }
        }

        int cnt = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(grid[i][j] == 1)
                    cnt++;
            }
        }
        return cnt;
    }
};
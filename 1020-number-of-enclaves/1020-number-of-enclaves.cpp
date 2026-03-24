class Solution {
private:
    void dfs(int x, int y, vector<vector<int>> &grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for(int i=0; i<4; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];

            if(nx < r && nx >= 0 && ny < c && ny >= 0 &&
                grid[nx][ny] == 1) {

                    grid[nx][ny] = 0;
                    dfs(nx, ny, grid);
                }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        // left and right
        for(int i=0; i<r; i++) {
            if(grid[i][0] == 1) {
                grid[i][0] = 0;
                dfs(i, 0, grid);
            }
            if(grid[i][c-1] == 1) {
                grid[i][c-1] = 0;
                dfs(i, c-1, grid);
            }
        }
        // top and bottom
        for(int j=1; j<c-1; j++) {
            if(grid[0][j] == 1) {
                grid[0][j] = 0;
                dfs(0, j, grid);
            }
            if(grid[r-1][j] == 1) {
                grid[r-1][j] = 0;
                dfs(r-1, j, grid);
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
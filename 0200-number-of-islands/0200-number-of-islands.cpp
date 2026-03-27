class Solution {
private: 
    void dfs(int x, int y, vector<vector<char>>& grid, 
            vector<vector<int>> &vis) {
                int r = grid.size();
                int c = grid[0].size();

                vis[x][y] = 1;

                int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, 
                                {0, -1}};

                
                for(int i=0; i<4; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];

                    if(nx >= 0 && nx < r && 
                        ny >= 0 && ny < c &&
                        grid[nx][ny] == '1' &&
                        !vis[nx][ny]) {
                            
                            vis[nx][ny] = 1;
                            dfs(nx, ny, grid, vis);
                        }
                }
                
            }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        
        vector<vector<int>> vis(r, vector<int>(c, 0));

        int island = 0;

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    island++;
                    dfs(i, j, grid, vis);
                }
            }
        }
        return island;
           
    }
};
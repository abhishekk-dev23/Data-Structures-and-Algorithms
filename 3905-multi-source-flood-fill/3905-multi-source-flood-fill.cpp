class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        vector<vector<int>> best(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;

        for(auto &src : sources) {
            int r = src[0];
            int c = src[1];
            int col = src[2];
    
            grid[r][c] = col;
            q.push({r, c, col});
        }
        
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            int sz = q.size();
            vector<pair<int, int>> vec;

            for(int k=0; k<sz; k++) {
                auto [x, y, c] = q.front();
                q.pop();
    
                for(auto& d: dir) {
                    int nx = x + d[0];
                    int ny = y + d[1];
    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0) {
                        if(best[nx][ny] == 0) vec.push_back({nx, ny});
                        best[nx][ny] = max(best[nx][ny], c);
                    }
                }
            }
            
            for(auto& [x, y]: vec) {
                grid[x][y] = best[x][y];
                q.push({x, y, grid[x][y]});
                best[x][y] = 0;
            }
                  
        }
        return grid;
    }
};
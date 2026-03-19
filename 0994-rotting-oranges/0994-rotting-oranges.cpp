class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int freshO = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2){
                    q.push({i, j, 0});
                    vis[i][j] = 2;
                } 
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1) freshO++;
            }
        }
        int cnt = 0;
        int total_time = 0;
        int drow[] = {+1, 0, -1, 0};
        int dcol[] = {0, +1, 0, -1};
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int r = node[0];
            int c = node[1];
            int t = node[2];
            total_time = max(total_time, t);

            for(int i=0; i<4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && 
                    ncol < m && grid[nrow][ncol] == 1 && 
                    vis[nrow][ncol] != 2) {
                        q.push({nrow, ncol, t+1});
                        vis[nrow][ncol] = 2;
                        cnt++;
                    }
            }
        }
        if(cnt != freshO) return -1;

        return total_time;
    }
};
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<tuple<int, int, int>> q;

        sort(sources.begin(), sources.end(), [](vector<int> &a, vector<int> &b){
            return a[2]>b[2];
        });

        for(auto& s : sources) {
            grid[s[0]][s[1]] = s[2];
            q.push({s[0], s[1], s[2]});
        }
        
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            auto [x, y, c] = q.front();
            q.pop();

            for(auto& d: dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0) {
                    grid[nx][ny] = c;
                    q.push({nx, ny, c});
                }
            }
                  
        }
        return grid;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int r = mat.size();
        int c = mat[0].size();
                //      {{x, y}, dis}
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(r, vector<int>(c, 0));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        vector<vector<int>> res(r, vector<int>(c));

        int dis[4][2] = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first.first;
            int y = node.first.second;
            int min_dis = node.second;

            res[x][y] = min_dis;
            vis[x][y] = 1;
            for(int i=0; i<4; i++) {
                int finX = x + dis[i][0];
                int finY = y + dis[i][1];

                if(finX >= 0 && finX < r && finY >= 0 &&
                    finY < c && 
                    !vis[finX][finY]) {
                        vis[finX][finY] = 1;
                        q.push({{finX, finY}, min_dis+1});
                        
                }
            }
        }
        return res;
    }
};
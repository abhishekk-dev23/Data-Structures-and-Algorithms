class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        int r = mat.size();
        int c = mat[0].size();
                //      {{x, y}, dis}
        queue<pair<int, int>> q;
        vector<vector<int>> res(r, vector<int>(c, INT_MAX));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;
                }
            }
        }

        int dir[4][2] = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;

            for(int i=0; i<4; i++) {
                int finX = x + dir[i][0];
                int finY = y + dir[i][1];

                if(finX >= 0 && finX < r && finY >= 0 &&
                    finY < c) {
                    if(res[finX][finY] > res[x][y] + 1) {
                        res[finX][finY] = res[x][y] + 1;
                        q.push({finX, finY});
                    }
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r = board.size();
        int c = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<char>> vis(r, vector<char>(c, 'n'));

        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(board[i][j] == 'O' && 
                    (i == 0 || i == r-1 || 
                    j == 0 ||j == c-1 )) {

                        q.push({i, j});
                        vis[i][j] = 's';
                }
            }
        }
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            vis[x][y] = 's';
            int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
            for(int i=0; i<4; i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if(nx < r && nx >= 0 && ny < c && ny >= 0 
                    && vis[nx][ny] != 's' 
                    && board[nx][ny] == 'O') {
                        vis[nx][ny] = 's';
                        q.push({nx, ny});
                }
            }
        }
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(vis[i][j] != 's') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
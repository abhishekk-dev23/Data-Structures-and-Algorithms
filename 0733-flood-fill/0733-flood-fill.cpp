class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int originalColor = image[sr][sc];
        vector<vector<int>> vis = image;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vis[sr][sc] = color;

        int dirs[4][2] = {{+1, 0}, {0, +1}, {-1, 0}, {0, -1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int drow = r + dirs[i][0];
                int dcol = c + dirs[i][1];

                if(drow >= 0 && drow < n && dcol >= 0 && 
                    dcol < m && vis[drow][dcol] != color && 
                    image[drow][dcol] == originalColor) {

                    vis[drow][dcol] = color;
                    q.push({drow, dcol});
                }
            }
        }
        return vis;
    }
};
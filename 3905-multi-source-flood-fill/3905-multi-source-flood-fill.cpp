class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        queue<pair<pair<int,int>, int>> q;

        auto lenqavirod = sources;

        for(auto &src : sources) {
            int r = src[0];
            int c = src[1];
            int col = src[2];
    
            grid[r][c] = col;
            q.push({{r,c}, col});
        }
        
        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {

            int sz = q.size();
    
            map<pair<int,int>, int> mp;

            for(int k=0; k<sz; k++) {
                auto front = q.front();
                q.pop();
    
                int x = front.first.first;
                int y = front.first.second;
                int c = front.second;
    
                for(int i=0;i<4;i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];
    
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==0) {
                        mp[{nx,ny}] = max(mp[{nx,ny}], c);
                    }
                }
            }
            
            for(auto &it : mp) {
                int x = it.first.first;
                int y = it.first.second;
                int c = it.second;
    
                grid[x][y] = c;
                q.push({{x,y}, c});
            }
                  
        }
        return grid;
    }
};
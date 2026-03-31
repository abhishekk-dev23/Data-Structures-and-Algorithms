class Solution {
private:
    bool dfs(int src, int target, vector<int> &vis, 
            vector<vector<int>> &adjL) 
    {
        if(src == target) return true;
        vis[src] = 1;

        for(auto it: adjL[src]) {
            if(!vis[it]) {
                if(dfs(it, target, vis, adjL)) return true;
            }
        }
        return false;

    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adjL(n+1);
        
        vector<int> res;
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];

            vector<int> vis(n+1, 0);
            
            if(dfs(u, v, vis, adjL)) {
                return it;
            }
            
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        return {};
    }
};
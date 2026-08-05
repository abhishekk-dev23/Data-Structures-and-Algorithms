class Solution {
private:
    void dfs(int k, vector<int> &vis, vector<vector<int>> &adj) {
        vis[k] = 1;

        for(auto x : adj[k]) {
            if(!vis[x]) dfs(x, vis, adj);
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        int e = invocations.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<e; i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }

        vector<int> vis(n, 0);
        dfs(k, vis, adj);

        bool isRemove = true;
        for(int i=0; i<e; i++) {
            int u = invocations[i][0];
            int v = invocations [i][1];

            if(vis[u] == 0 && vis[v] == 1) {
                isRemove = false;
                break;
            }
        }

        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(!isRemove || vis[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
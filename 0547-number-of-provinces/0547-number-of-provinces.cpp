class Solution {
     private:
    void findDfs(int node, vector<vector<int>>& adj, vector<int> &vis){
        vis[node] = 1;
        
        for(int it: adj[node]) {
            if(!vis[it]) {
                findDfs(it, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(i != j && isConnected[i][j])
                adj[i].push_back(j);
            }
        }

        vector<int> vis(V, 0);
        int res = 0;
        
        for(int i=0; i<V; i++) {
            int node = i;
            if(!vis[node]) {
                res++;
                findDfs(node, adj, vis);
            }
        }
        return res;
    }
};
class Solution {
     private:
    void findDfs(int i, vector<vector<int>>& adj, vector<int> &vis){
        vis[i] = 1;
        
        for(int j=0; j<adj.size(); j++) {
            if(adj[i][j] == 1 &&  !vis[j]) {
                findDfs(j, adj, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();

        vector<int> vis(V, 0);
        int res = 0;
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                res++;
                findDfs(i, isConnected, vis);
            }
        }
        return res;
    }
};
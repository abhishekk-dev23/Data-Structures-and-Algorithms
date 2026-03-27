class Solution {
private:
    bool bfs(int node, vector<vector<int>>& graph, vector<char> &color) {
        // y->csk
        // r->rcb
        
        queue<int> q;
        q.push(node);
        color[node] = 'y';

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: graph[node]) {
                if(!color[it]){
                    q.push(it);
                    color[it] = color[node] == 'y' ? 'r' : 'y';
                }
                else if(color[node] == color[it]) {
                    return false;
                }
                
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<char> color(graph.size());
        bool ans;
        for(int i=0; i<graph.size(); i++) {
            if(!color[i]) {
                if(!bfs(i, graph, color)) return false;
            }
        }
        return true;
    }
};
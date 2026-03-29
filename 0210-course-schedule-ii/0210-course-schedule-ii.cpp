class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjL(V);
        for(int i=0; i<prerequisites.size(); i++) {
            adjL[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        vector<int> inDegree(V, 0);
        for(int i=0; i<V; i++) {
            for(auto it: adjL[i]) {
                inDegree[it]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<V; i++) {
            if(inDegree[i] == 0) q.push(i);
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adjL[node]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        reverse(topo.begin(), topo.end());
        if(topo.size() == V) return topo;
        return {};
    }
};
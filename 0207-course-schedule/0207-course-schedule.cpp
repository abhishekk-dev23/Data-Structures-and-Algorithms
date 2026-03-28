class Solution {
private:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
            vector<vector<int>> &adjL) 
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto it: adjL[node]) {
            if(!vis[it]) {
                if(dfs(it, vis, pathVis, adjL)) return true;
            }
            else if(pathVis[it] == 1) return true;
        }
        pathVis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        vector<vector<int>> adjL(n);
        for(int i=0; i<prerequisites.size(); i++) {
            adjL[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                if(dfs(i, vis, pathVis, adjL)) return false;
            }
        }
        return true;
    }
};
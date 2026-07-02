class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        for(int i=0; i<mat.size(); i++) {
            for(int j=i; j<mat[0].size(); j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        reverse(mat.begin(), mat.end());
        return mat;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        
        if(mat == target) return true;

        mat = rotate(mat);
        if(mat == target) return true;

        mat = rotate(mat);
        if(mat == target) return true;

        mat = rotate(mat);
        if(mat == target) return true;

        return false;
    }
};
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> temp;
        temp = matrix;

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                matrix[i][j] = temp[col-1-j][i];
            }
        }
    }
};
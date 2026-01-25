class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> zerothRow(row, false);
        vector<bool> zerothCol(col, false);

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0){
                    zerothRow[i] = true;
                    zerothCol[j] = true;
                }
            }
        }
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++){
                if(zerothRow[i] || zerothCol[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> res;
        int count = 0;
        int total = rowSize*colSize;

        int leftCol = 0;
        int topRow = 0;
        int rightCol = colSize - 1;
        int bottomRow = rowSize - 1;

        while(count < total) {
            //for right
            for(int index=leftCol; count<total && index<=rightCol; index++) {
                res.push_back(matrix[topRow][index]);
                count++;
            }
            topRow++;

            // for bottom
            for(int index=topRow; count<total && index<=bottomRow; index++) {
                res.push_back(matrix[index][rightCol]);
                count++;
            }
            rightCol--;

            // for left
            for(int index=rightCol; count<total && index>=leftCol; index--) {
                res.push_back(matrix[bottomRow][index]);
                count++;
            }
            bottomRow--;

            // for top
            for(int index=bottomRow; count<total && index>=topRow; index--) {
                res.push_back(matrix[index][leftCol]);
                count++;
            }
            leftCol++;
        } 
        return res;
    }
};
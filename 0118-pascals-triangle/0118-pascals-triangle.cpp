class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int r = numRows;
        vector<vector<int>> tri(r);
        tri[0] = {1};
        if(r == 1) return tri;

        tri[1] = {1, 1};

        for(int i=2; i<r; i++) {
            vector<int> col(i+1);
            col[0] = 1;
            col[i] = 1;

            for(int j=1; j<col.size()-1; j++) {
                col[j] = tri[i-1][j] + tri[i-1][j-1];
            }
            tri[i] = col;
        }
        return tri;
    }
};
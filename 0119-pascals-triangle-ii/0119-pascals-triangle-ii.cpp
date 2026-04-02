class Solution {
private:
    vector<int> oneRow(int r) {
        vector<int> v;
        long long ans = 1;
        v.push_back(1);
        for(int i=1; i<=r; i++) {
            ans = ans * (r+1 - i);
            ans = ans / i;
            v.push_back(ans);
        }
        return v;
    }
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        if(n == 0) return {1};

        return oneRow(n);
    }
};
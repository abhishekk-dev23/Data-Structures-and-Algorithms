class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        vector<int> mpp(2, 0);
        for(auto& it: moves) {
            if(it == 'L')  mpp[0]++;
            else if(it == 'R')  mpp[1]++;
        }

        int path = 0;
        int _val = mpp[0] > mpp[1] ? -1 : 1;
        
        for(int i=0; i<n; i++) {
            if(moves[i] == 'L') path -= 1;
            else if(moves[i] == 'R') path += 1;
            else path += _val;
        }
        return abs(path);
    }
};
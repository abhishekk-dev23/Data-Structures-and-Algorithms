class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        unordered_map<char, int> mpp;
        for(auto& it: moves) {
            mpp[it]++;
        }
        int _path = max(mpp['L'], mpp['R']);

        int path = 0;
        int _val = mpp['L'] > mpp['R'] ? -1 : 1;
        
        for(int i=0; i<n; i++) {
            if(moves[i] == 'L') path -= 1;
            else if(moves[i] == 'R') path += 1;
            else path += _val;
        }
        return abs(path);
    }
};
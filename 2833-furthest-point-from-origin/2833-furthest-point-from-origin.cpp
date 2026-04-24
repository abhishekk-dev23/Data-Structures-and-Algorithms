class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int l = 0, r = 0, u = 0;
        for(auto& it: moves) {
            if(it == 'L') l++;
            else if(it == 'R') r++;
            else u++;
        }
        return abs(l-r) + u;
    }
};
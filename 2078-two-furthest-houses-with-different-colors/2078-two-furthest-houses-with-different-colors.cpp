class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int fc = 0;
        int sc = colors.size() - 1;
        int max_dist = INT_MIN;
        int dist = 0;

        while (fc < sc) {
            if (colors[fc] != colors[sc]) {
                max_dist = max(max_dist, abs(sc - fc));
                break;
            } else {
                sc--;
            }
        }
        fc = 0;
        sc = colors.size() - 1;
        while(fc < sc) {
            if (colors[fc] != colors[sc]) {
                max_dist = max(max_dist, abs(sc - fc));
                break;
            } else {
                fc++;
            }
        }
        return max_dist;
    }
};
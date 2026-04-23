class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);

        unordered_map<int, vector<int>> mpp;
        for(int i=0; i<n; i++) {
            mpp[nums[i]].push_back(i) ;
        }

        for(auto it: mpp) {
            vector<int> &idx = it.second;
            int siz = idx.size();
            if(siz == 1) continue;

            vector<long long> pref(siz, 0);
            pref[0] = idx[0];

            for(int i=1; i<siz; i++) {
                pref[i] = pref[i-1] + idx[i];
            }

            for(int i=0; i<siz; i++) {
                long long left = 0, right = 0;
                // lft
                if(i > 0) left = 1LL * i * idx[i] - pref[i-1];
                // rgt
                if(i < siz-1) right = (pref[siz-1] - pref[i]) - 1LL*(siz - i - 1) * idx[i];

                ans[idx[i]] = left + right;
            }
        }
        return ans;
    }
};
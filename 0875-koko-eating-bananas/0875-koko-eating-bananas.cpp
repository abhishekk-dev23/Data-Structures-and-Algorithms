class Solution {
public:
    bool isAteBanana(vector<int>& piles, int h, int k) {
        int n = piles.size();
        long long hours = 0;

        for(int i=0; i<n; i++) {
            hours += (piles[i] + k - 1)/k;
            if(hours > h) return false;
        }
        return true;
    }
    int findMax(vector<int>&piles) {
        int max_val = INT_MIN;
        for(auto x: piles) {
            max_val = max(max_val, x);
        }
        return max_val;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1, e = findMax(piles);
        int ans = e;

        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isAteBanana(piles, h, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool isBouquests(vector<int>& bloomDay, int m, int k, int mid) {
        int bouquets = 0;
        int flowers = 0;

        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= mid){
                flowers++;
                if(flowers == k) {
                    bouquets++;
                    flowers = 0;
                }
            }
            else{
                flowers = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m * k > n) return -1;

        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while(s <= e) {
            int mid = s + (e-s)/2;
            bool isValid = isBouquests(bloomDay, m, k, mid);

            if(isValid) {
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
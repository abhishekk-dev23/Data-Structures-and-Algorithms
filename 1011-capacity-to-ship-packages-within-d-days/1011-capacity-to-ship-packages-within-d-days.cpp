class Solution {
public:
    int checkValidWeight(vector<int>& weights, int days, int cap) {
        int sum = 0;
        int usedDays = 1;
        int n = weights.size();

        for(int i=0; i<n; i++) {
            if(sum + weights[i] > cap) {
                usedDays++;
                sum = weights[i];
                if (usedDays > days) return false;
            }
            else{
                sum += weights[i];
            }
        }
        return usedDays <= days;
    }
    int sumation(vector<int>& weights)  {
        int sum = 0;
        for(auto s: weights) sum += s;
        return sum;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = e;

        while(s <= e) {
            int mid = s + (e-s)/2;
            bool isValidWeight = checkValidWeight(weights, days, mid);

            if(isValidWeight) {
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
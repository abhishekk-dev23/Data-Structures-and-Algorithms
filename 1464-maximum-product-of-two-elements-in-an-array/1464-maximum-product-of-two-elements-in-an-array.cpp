class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxi1 = 0;
        int maxi2 = 0;

        for(int x : nums) {
            if(maxi1 < x) {
                maxi2 = maxi1;
                maxi1 = x;
            }
            else if(maxi2 < x){
                maxi2 = x;
            }
        }
        return (maxi1-1)*(maxi2-1);
    }
};
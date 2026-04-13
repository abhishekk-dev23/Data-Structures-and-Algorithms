class Solution {
private:
    int findDigit(int n, int dig) {
        int count = 0;
        while(n > 0) {
            int x = n % 10;
            n = n/10;
            if(x == dig) count++;
        }
        return count;
    }
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        int n = nums.size();

        for(int i=0; i<n; i++) {
            count += findDigit(nums[i], digit);
        }
        return count;
    }
};
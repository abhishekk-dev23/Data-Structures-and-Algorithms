class Solution {
private:
    bool isPrime(int n) {
        if(n <= 1) return false;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    int minOperations(vector<int>& nums) {
        int oper = 0;

        for(int i=0; i<nums.size(); i++) {
            // index is odd
            if(i%2 == 0) {
                if(!isPrime(nums[i])) {
                    while(!isPrime(nums[i])) {
                        nums[i]++;
                        oper++;
                    }
                }
            }
            // index is even
            else {
                if(isPrime(nums[i])) {
                    while(isPrime(nums[i])) {
                        nums[i]++;
                        oper++;
                    }
                }
            }
        }
        return oper;
    }
};
class Solution {
private:
    int reverse(int n) {
        int rev = 0;
        while(n > 0) {
            int digit = n % 10;
            rev = rev*10 + digit;
            n = n / 10;
        }
        return rev;
    }
public:
    int mirrorDistance(int n) {
        return abs(reverse(n) - n);
    }
};
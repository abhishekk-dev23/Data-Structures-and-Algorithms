class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while(n > 0) {
            int d = n % 10;
            rev = rev * 10 + d;
            n = n / 10;
        }
        return rev;
    }
    bool isPrime(int n) {
        if(n <= 1) return false;
        for(int i=2; i * i<=n; i++) {
            if(n % i == 0) return false;
        }
        return true;
    }
public:
    int sumOfPrimesInRange(int n) {
        int rev = reverse(n);
        int a = max(n, rev);
        int b = min(n, rev);

        int sum = 0;
        for(int i=b; i<=a; i++) {
            if(isPrime(i)) sum += i;
        }
        return sum;
    }
};
class Solution {
public:
    bool isPowerOfTwo(int n) {
        int s = 0;
        int e = n;
        long long mid = 0;

        while(s <= e) {
            mid = s + (e-s)/2;
            if(pow(2, mid) == n) return true;

            if(pow(2, mid) > n) e = mid - 1;
            else s = mid + 1;
        }
        return false;
    }
};
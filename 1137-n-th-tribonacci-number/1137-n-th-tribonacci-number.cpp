class Solution {
public:
// 0, 1, 1, 2, 4, 7, 13, 24, 44
    int tribonacci(int n) {
        int p1 = 0, p2 = 1, p3 = 1;
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int curr = 0;

        for(int i=3; i<=n; i++) {
            curr = p1 + p2 + p3;
            p1 = p2;
            p2 = p3;
            p3 = curr;
        }
        return curr;
    }
};
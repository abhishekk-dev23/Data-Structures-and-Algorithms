class Solution {
public:
    int findComplement(int num) {
        int k = (1LL << (int)(log2(num) + 1)) - 1;

        return (k ^ num);
    }
};
class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;

        for (int mask = 0; mask < (1 << n); mask++) {

            string str = "";
            int cost = 0;
            bool valid = true;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << (n - 1 - i))) {
                    str += '1';
                    cost += i;
                } else {
                    str += '0';
                }
            }

            for (int i = 1; i < n; i++) {
                if (str[i] == '1' && str[i - 1] == '1') {
                    valid = false;
                    break;
                }
            }

            if (valid && cost <= k) {
                res.push_back(str);
            }
        }

        return res;
    }
};
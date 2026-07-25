class Solution {
public:
    int maxProduct(int n) {
        string st = to_string(n);
        int maxi = 0;
        int sec_maxi = 0;

        for(int i=0; i<st.size(); i++) {
            int val = st[i] - '0';
            if(val >= maxi) {
                sec_maxi = maxi;
                maxi = val;
            }
            else if(sec_maxi < val && val < maxi) {
                sec_maxi = val;
            }
        }
        return (maxi * sec_maxi);
    }
};
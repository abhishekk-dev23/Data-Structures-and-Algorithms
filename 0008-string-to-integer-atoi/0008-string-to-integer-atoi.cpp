class Solution {
public:
    int myAtoi(string s) {
        if(s.size() == 0) return 0;

        int n = s.size();
        int sign = 1;

        int i=0;
        long long ans = 0;
        
        while(i < s.size() && s[i] == ' '){
            i++;
        }

        if(i == n) return 0;

        if(s[i] == '-'  || s[i] == '+') {
            sign = s[i] == '-' ? -1 : 1;
            i++;
        }
        
        while(i < s.size() && s[i] == '0') i++;
        
        while(i < n && isdigit(s[i])) {
            if(ans > (INT_MAX - s[i] + '0') / 10) {
                return (sign == -1 ? INT_MIN : INT_MAX);
            }

            ans = ans * 10 + s[i] - '0';
            i++;
        }
        return int(ans)*sign;
    }
};
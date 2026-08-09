class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int i = n - 1;
        int j = m - 1;
        double total_amount = 0.0;
        
        while(i >= 0 && j >= 0) {
            int p = prices[i];
            int d = discounts[j];
            total_amount += double((p * (100.00 - d)) / 100.00);
            i--;
            j--;
        }
        while(i >= 0) {
            total_amount += prices[i];
            i--;
        }

        return total_amount;
    }
};
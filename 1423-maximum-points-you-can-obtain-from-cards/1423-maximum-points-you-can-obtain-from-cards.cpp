class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int max_sum = INT_MIN;
        int leftSum = 0;
        int rgtSum = 0;
        
        for(int i=0; i<k; i++) {
            leftSum += cardPoints[i];
        }
        max_sum = max(max_sum, leftSum);
        int sum = 0;

        for(int x=1; x<=k; x++) {
            leftSum -= cardPoints[k-x];
            rgtSum += cardPoints[n-x];
            sum = leftSum + rgtSum;

            max_sum = max(max_sum, sum);
        }

        return max_sum;
    }
};
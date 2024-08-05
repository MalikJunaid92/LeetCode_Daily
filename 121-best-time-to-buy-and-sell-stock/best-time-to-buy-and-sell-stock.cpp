class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxprof = 0;
        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                int prof = prices[r] - prices[l];
              maxprof=  max(maxprof, prof);
            } else {
                l = r;
            }
            r++;
        }
        return maxprof;
    }
};
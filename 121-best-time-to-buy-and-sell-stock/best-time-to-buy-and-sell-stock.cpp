class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini_pri = prices[0];
        int max_pri = 0;
        for (int i = 1; i < n; i++) {
            mini_pri = min(mini_pri, prices[i]);
            int profit = prices[i] - mini_pri;
            max_pri = max(profit, max_pri);
        }
        return max_pri;
    }
};
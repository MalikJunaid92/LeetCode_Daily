class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob from index 0 to n - 2
        int prev1 = 0, prev2 = 0;
        for (int i = 0; i < n - 1; ++i) {
            int temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }
        int money1 = prev1;

        // Case 2: Rob from index 1 to n - 1
        prev1 = 0;
        prev2 = 0;
        for (int i = 1; i < n; ++i) {
            int temp = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = temp;
        }
        int money2 = prev1;

        return max(money1, money2);
    }
};

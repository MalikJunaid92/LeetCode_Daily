class Solution {
public:
    int t[201][20001];

    bool solve(vector<int>& nums, int i, int x) {
        if (x == 0) return true;
        if (i >= nums.size() || x < 0) return false;

        if (t[i][x] != -1) return t[i][x];

        bool take = false;
        if (nums[i] <= x) {
            take = solve(nums, i + 1, x - nums[i]);
        }
        bool not_take = solve(nums, i + 1, x);

        return t[i][x] = take || not_take;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));

        int s = accumulate(nums.begin(), nums.end(), 0);

        if (s % 2 != 0) return false;

        int x = s / 2;
        return solve(nums, 0, x);
    }
};

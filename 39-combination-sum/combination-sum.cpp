class Solution {
public:
    void backtrack(int index, vector<int>& arr, int target, vector<int>& current, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = index; i < arr.size(); ++i) {
            if (arr[i] > target) continue;

            current.push_back(arr[i]);

            backtrack(i, arr, target - arr[i], current, result);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, arr, target, current, result);
        return result;
    }
};

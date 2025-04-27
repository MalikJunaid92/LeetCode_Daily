class Solution {
public:
    void backtrack(int idx, vector<int>& candidates, int target, vector<int>& current,
                   vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;  // Fix: Stop further recursion if target goes negative
        
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i-1])
                continue;
            current.push_back(candidates[i]);  // DO
            backtrack(i+1, candidates, target - candidates[i], current, result);
            current.pop_back();              // UNDO
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(0, candidates, target, current, result);
        return result;
    }
};

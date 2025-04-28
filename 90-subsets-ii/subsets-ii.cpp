class Solution {
public:
vector<vector<int>>result;
void backtrack(int idx, vector<int>& nums, vector<int>&temp){
        result.push_back(temp);
    for(int i=idx; i<nums.size();i++){
        if(i > idx && nums[i] == nums[i-1]) continue;
        temp.push_back(nums[i]);
        backtrack(i+1, nums,temp);
        temp.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
     vector<int>temp;
     sort(nums.begin(),nums.end());
      backtrack(0,nums,temp);
      return result;
    }
};
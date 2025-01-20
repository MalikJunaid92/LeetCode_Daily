class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            return nums[0];
        }
        return -1;
    }
};
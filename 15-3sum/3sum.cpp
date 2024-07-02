class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int k=0;k<nums.size();k++)
        {
            int target=-nums[k];
            int i=k+1;
            int j=nums.size()-1;
             if(k > 0 && nums[k] == nums[k - 1]){
                continue;
            }
            while(i<j )
            {
                int sum=nums[i]+nums[j];
                if(sum==target)
                {
                    ans.push_back({nums[k],nums[i],nums[j]});
                    int l=i;
                    int h=j;
                     while (i < j && nums[i] == nums[l]) {
                        i++;
                    }
                    while (i < j && nums[j] == nums[h]) {
                        j--;
                    }
                } 
                else if(sum>target)
                {
                    j--;
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
        
    }
};
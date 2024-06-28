class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        int n=nums.size();
        int t=1;
        for(int i=0;i<n;i++){
            t=t*nums[i];
            left.push_back(t);
        }
        t=1;
        for(int i=n-1;i>=0;i--){
            t=t*nums[i];
            right.push_back(t);
        }

        vector<int> ans;
        ans.push_back(right[n-2]);
        for(int i=1;i<n-1;i++){
            int temp=left[i-1]*right[n-2-i];
            ans.push_back(temp);
        }
        ans.push_back(left[n-2]);
        return ans;
    }
};
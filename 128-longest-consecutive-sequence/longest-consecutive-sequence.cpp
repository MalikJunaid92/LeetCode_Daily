class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int res=0;
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
        int num=nums[i];
        if(!mp[num]){
            int left= mp[num -1];
            int right= mp[num +1];
            int length= left + right +1;
            mp[num]= length;
            mp[num -left]= length;
            mp[num + right]= length;
            res = max(res,length);
        }
       }
       return res;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    priority_queue<pair<int,int>>max_heap;
    for(auto it=mp.begin();it!=mp.end();++it){
        max_heap.push({it->second,it->first});
    }
    vector<int>res;
    for(int i=0;i<k;++i){
        res.push_back(max_heap.top().second);
        max_heap.pop();
    }
    return res;
    }
};

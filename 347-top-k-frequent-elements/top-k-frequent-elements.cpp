class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq_map;
        for(auto x: nums){
            freq_map[x]++;
        }
        priority_queue<pair<int,int>> max_heap;
        for(auto &pair: freq_map){
            max_heap.push({pair.second,pair.first});
        }
        vector<int>res;
        for(int i=0;i<k; ++i){
            res.push_back(max_heap.top().second);
            max_heap.pop();
        }
        return res;
    }
};

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> s;

        // Fill the map with the next greater elements for nums2
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                nextGreaterMap[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }

        // For elements still in the stack, there is no next greater element
        while (!s.empty()) {
            nextGreaterMap[s.top()] = -1;
            s.pop();
        }

        // Build the result array for nums1 based on the next greater map
        vector<int> result;
        for (int num : nums1) {
            result.push_back(nextGreaterMap[num]);
        }

        return result;
    }
};

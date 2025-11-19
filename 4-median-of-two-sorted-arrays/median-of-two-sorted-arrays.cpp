class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;

        for (int num : nums1) {
            arr.push_back(num);
        }
        for (int num : nums2) {
            arr.push_back(num);
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();

        if (n % 2 == 1) {
            return arr[n / 2];
        }else{
            return (arr[n/2 -1] + arr[n/2])/2.0;
        }
    }
};

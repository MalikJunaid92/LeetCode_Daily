class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Combine the two vectors
        vector<int> array;
        array.reserve(nums1.size() + nums2.size());
        array.insert(array.end(), nums1.begin(), nums1.end());
        array.insert(array.end(), nums2.begin(), nums2.end());
        
        // Sort the combined vector
        sort(array.begin(), array.end());
        
        // Find the median
        int n = array.size();
        if (n % 2 == 0) {
            // If even, the median is the average of the two middle elements
            return (array[n/2 - 1] + array[n/2]) / 2.0;
        } else {
            // If odd, the median is the middle element
            return array[n/2];
        }
    }
};

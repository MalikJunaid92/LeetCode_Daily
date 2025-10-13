class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int l = 0, maxFreq = 0, res = 0;

        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);

            // if window invalid (too many changes)
            while ((r - l + 1) - maxFreq > k) {
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }
        return res;
    }
};
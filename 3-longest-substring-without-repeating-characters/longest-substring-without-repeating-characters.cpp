class Solution {
public:
   int lengthOfLongestSubstring(string s) {
    int longestSubStr = 0;

    unordered_map<char, int> visited;
    int left = 0, right = 0;

    for (int i = 0; i < s.size(); ++i, ++right) {
        if (visited.find(s[i]) != visited.end() && visited[s[i]] >= left) {
            left = visited[s[i]] + 1;
        }
        visited[s[i]] = i;
        longestSubStr = max(longestSubStr, right - left + 1);
    }

    return longestSubStr;
}
};
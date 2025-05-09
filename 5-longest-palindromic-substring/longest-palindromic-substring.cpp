class Solution {
public:
    int t[1001][1001];
    bool solve(string& s, int i, int j) {
        if (i >= j)
            return true;

        if (t[i][j] != -1) {
            return t[i][j];
        }
        if (s[i] == s[j]) {
            return solve(s, i + 1, j - 1);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxLen = INT_MIN;
        int sp = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (solve(s, i, j) == true) {
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};

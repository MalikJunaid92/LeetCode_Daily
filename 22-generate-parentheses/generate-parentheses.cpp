class Solution {
public:
    void generate(string s, int open, int close, int n, vector<string>& res) {
        if (s.size() == n * 2) {
            res.push_back(s);
            return;
        }
        if (open < n)
            generate(s + "(", open + 1, close, n, res);
        if (close < open)
            generate(s + ")", open, close + 1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate("", 0, 0, n, res);
        return res;
    }
};

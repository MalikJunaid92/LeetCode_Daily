class Solution {
public:
    bool isValid(string s) {
        stack<char> para;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                para.push(c);
            } else {
                if (para.empty()) {
                    return false;
                }
                char top = para.top();
                para.pop();
                if ((c == ')' && top != '(') || (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return para.empty();
    }
};
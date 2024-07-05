class Solution {
public:
    bool isValid(string s) {
        stack<char> parenthesesStack;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                parenthesesStack.push(c);
            } else {
                if (parenthesesStack.empty()) {
                    return false;
                }

                char top = parenthesesStack.top();
                parenthesesStack.pop();

                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return parenthesesStack.empty();
    }
};
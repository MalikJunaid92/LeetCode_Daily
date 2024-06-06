class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.length();
        unordered_set<char> st;
        int result=0;
        for(char &ch:s){
            if(st.count(ch)){
                result+=2;
                st.erase(ch);
            }
            else{
                st.insert(ch);
            }
        }
        if(!st.empty()){
            result++;
        }
        return result;
    }
};
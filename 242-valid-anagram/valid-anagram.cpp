class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!= t.length())return false;
       unordered_map<char,int>arr1;
       unordered_map<char,int>arr2;
       for(int i=0;i<s.length();i++){
        arr1[s[i]]++;
        arr2[t[i]]++;
       }
       return arr1== arr2;
    }
};

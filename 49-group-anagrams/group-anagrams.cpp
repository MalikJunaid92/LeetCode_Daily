class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto x : strs) {
            string word = x;
            sort(word.begin(), word.end()); // Sort the string alphabetically
            mp[word].push_back(x); // Add the original string to the vector for this key
        }

        vector<vector<string>> ans;
        for (auto x : mp) {
            ans.push_back(x.second); // Add the group of anagrams to the result
        }

        return ans;
    }
};

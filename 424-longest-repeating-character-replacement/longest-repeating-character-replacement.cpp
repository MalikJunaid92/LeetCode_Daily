class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, maxf=0,res=0;
        unordered_map<char, int>count;
        for(int i=0;i<s.size();i++){
            count[s[i]]++;
            maxf=max(maxf,count[s[i]]);
            if((i-l+1)- maxf > k){
                count[s[l]]--;
                l++;
            }
            res=max(res, i-l+1);
        }
       return res; 
    }
};
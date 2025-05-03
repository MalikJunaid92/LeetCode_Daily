class Solution {
public:
int climb(int n, vector<int>& memo){
    if(n<=2)return n;
    if(memo[n]!=-1)return memo[n];
    memo[n]= climb(n-1, memo) + climb(n-2,memo);
    return memo[n];
}
    int climbStairs(int n) {
      vector<int> memo(n+1, -1);
      return climb(n,memo);
    }
};
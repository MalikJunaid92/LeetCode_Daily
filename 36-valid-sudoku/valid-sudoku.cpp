class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
      const int num=9;
      bool row[num][num]={false};
      bool col[num][num]={false};
      bool subgrid[num][num]={false};
      for(int r=0;r<num;++r){
        for(int c=0;c<num;++c){
            if(board[r][c]=='.')
            continue;
            int idx=board[r][c] - '0' -1;
            int gridNum= (r/3) * 3 + (c/3);
            if(row[r][idx] || col[c][idx] || subgrid[gridNum][idx]){
                return false;
            }
            row[r][idx] = true;
            col[c][idx] = true;
            subgrid[gridNum][idx] = true;
        }
      }
        return true;

    }
};
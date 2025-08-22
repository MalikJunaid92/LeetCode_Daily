class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     for(int r=0;r<matrix.size();r++){
        for(int c=0;c<matrix[r].size();c++){
            if(matrix[r][c]==target){
                return true;
            }
        }
     }
      return false;
    }
};
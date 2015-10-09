//312ms, 67.46%

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int M = matrix.size();
        if(M != 0){
            int N = matrix[0].size()-1;
            
            int i_ = 0;
            while(N >= 0 && i_ < M){
                if(matrix[i_][N] == target) return true;
                else if(matrix[i_][N] > target) N--;
                if(matrix[i_][N] < target) i_++;
            }
        }
        
        return false;
    }
};
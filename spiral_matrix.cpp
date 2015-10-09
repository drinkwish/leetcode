//0ms, 6.04%

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size() != 0)
            spiralOrder(matrix, ret, 0, matrix[0].size()-1, 0, matrix.size()-1);
            
        return ret;
    }
    
    void spiralOrder(vector<vector<int>>& matrix, vector<int> &ret, int x1, int x2, int y1, int y2) {
        for(int i_ = x1; i_ <= x2; ++i_){
            ret.push_back(matrix[y1][i_]);
        }
        for(int i_ = y1+1; i_ <= y2; ++i_){
            ret.push_back(matrix[i_][x2]);
        }
        for(int i_ = x2-1; i_ >= x1 && y2 != y1; --i_){
            ret.push_back(matrix[y2][i_]);
        }
        for(int i_ = y2-1; i_ > y1 && x1 != x2; --i_){
            ret.push_back(matrix[i_][x1]);
        }
        
        if(++x1 <= --x2 && ++y1 <= --y2)
            spiralOrder(matrix, ret, x1, x2, y1, y2);
    }
};
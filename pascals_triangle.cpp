//0ms, fast enough

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        
        if(numRows <= 0) return ret;
        
        for(int i_ = 0; i_ < numRows; ++i_){
            vector<int> tmp(i_ + 1);
            tmp[0] =1;
            for(int j_ = 1; j_ < i_; ++j_){
                tmp[j_] = ret[i_-1][j_-1] + ret[i_-1][j_];
            }
            tmp[i_] = 1;
            ret.push_back(tmp);
        }
        
        return ret;
    }
};
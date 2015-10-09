//0ms, fast enough

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1);
        ret[0] = 1;
        
        for(int i_ = 1; i_ < rowIndex + 1; ++i_){
            vector<int> tmp(i_ + 1);
            tmp[0] = 1;
            for(int j_ = 1; j_ < i_; ++j_){
                tmp[j_] = ret[j_];
                ret[j_] = tmp[j_ - 1] + tmp[j_];
            }
            ret[i_] = 1;
        }
        
        return ret;
    }
};
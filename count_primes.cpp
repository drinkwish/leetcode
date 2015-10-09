//80,s. can be optimized

class Solution {
public:
    int countPrimes(int n) {
        int *m = new int[n];
        
        for(int i_ = 2; i_ < n; ++i_){
            m[i_] = 1;
        }
        
        
        for(int i_ = 2; i_ *i_ < n; ++i_){
            
            while(m[i_] == 0) ++i_;
            
            for(int j_ = i_*i_; j_ < n; j_ += i_){
                m[j_] = 0;
            }
        }
        
        int ret = 0;
        for(int i_ = 2; i_ < n; ++i_){
            ret += m[i_];
        }
        
        return ret;
    }
};
//8 ms, can be optimized

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ret = 0;
        for(int i_ = 31; i_>0; --i_){
            ret = ret | (n & 0x1);
            ret = ret << 1;
            n = n >> 1;
        }
        
        ret = ret | (n & 0x1);
        
        return ret;
    }
};
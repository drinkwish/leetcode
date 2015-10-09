//4ms, fast enough

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while(n){
            ret += n&0x00000001;
            n = n >> 1;
        }
        
        return ret;
    }
};
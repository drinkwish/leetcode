//16ms, 51.54%

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        int len = nums.size();
        
        for(int index = 0; index < 32; ++index){
            int tmp = 0;
            int mask = 0x1 << index;
            for(int i_ = 0; i_ < len; ++i_){
                if(nums[i_] & mask) ++tmp;
            }
            if(tmp%3) ret |= mask;
        }
        return ret;
        
    }
    
    
};
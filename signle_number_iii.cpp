//16ms, 76.21%

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();
        int xorsum = 0;
        for(int i_ = 0; i_ < len; ++i_){
            xorsum ^= nums[i_];
        }
        
        int mask = xorsum & (-xorsum);
        
        vector<int> ret(2,0);
        for(int i_ = 0; i_ < len; ++i_){
            if(nums[i_] & mask) ret[0] ^= nums[i_];
            else ret[1] ^= nums[i_];
        }
        
        return ret;
    }
};
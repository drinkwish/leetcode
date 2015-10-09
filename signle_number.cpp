//12ms, 85.53%
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i_ = 0; i_ < nums.size(); ++i_){
            ret ^= nums[i_];
        }
        return ret;
    }
};
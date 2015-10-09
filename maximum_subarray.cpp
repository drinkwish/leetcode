//12ms, 68.71%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len){
            int max = nums[0];
            int cur = nums[0];
            
            for(int i_ =1; i_ < len; ++i_){
                if(cur < 0) cur = nums[i_];
                else cur += nums[i_];
                
                if(cur > max) max = cur;
            }
            
            return max;
        }
    }
};
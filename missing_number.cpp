//36ms, 29.10%

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int sum = (len*(len+1))/2;
        
        for(int i_ = 0; i_ < len; ++i_){
            sum -= nums[i_];
        }
        
        return sum;
    }
};
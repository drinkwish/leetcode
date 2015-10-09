//16ms, not enough tests

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for(int i_ = 0; i_ < nums.size(); ++i_){
            if(nums[i_] != 0){
                nums[cur++] = nums[i_];
            }
        }
        while(cur < nums.size()) nums[cur++] = 0;
    }
};
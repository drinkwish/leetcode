//dynamic programming
//time limit exceeded
//class Solution {
//public:
//    int rob(vector<int>& nums) {
//        if(nums.size() == 0) return 0;
//        if(nums.size() == 1) return nums[0];
//        
//        int ret =0;
//        return robAlg(nums, 0);
//    }
//    
//private:
//    int robAlg(vector<int> & nums, int start){
//        if(start == nums.size()-2) return nums[start-2] > nums[start-1] ? nums[start-1] : nums[start-1];
//        if(start == nums.size()-1) return nums[start];
//        
//        int tmp1 = nums[start] + robAlg(nums, start+2);
//        int tmp2 = robAlg(nums, start + 1);
//        
//        return tmp1 > tmp2 ? tmp1 : tmp2;
//        
//    }
//};

//0ms, fast enough
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> max(nums.size(), 0);
        int length = nums.size();
        max[length-1] = nums[length-1];
        max[length-2] = nums[length-2] > nums[length -1] ? nums[length-2] : nums[length-1];
        for(int i_ = max.size()-3; i_> -1 ; --i_){
            max[i_] = max[i_+1] > (max[i_+2] + nums[i_]) ? max[i_+1] : max[i_+2] + nums[i_];
        }
        
        return max[0];
    }
};